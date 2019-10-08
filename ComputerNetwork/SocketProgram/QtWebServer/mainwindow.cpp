#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QTimer>
#include <QDateTime>
#include <QAction>
#include <QMessageBox>
#include <QDebug>
#include <direct.h>
#include <QFileDialog>
#include "configation.h"
#include <winsock2.h>
#include "guidedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置界面背景色
    this->setStyleSheet("background-color: rgb(238, 247, 242);");
    //禁止最大化按钮和拖动窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());

    //设置菜单栏
    connect(ui->action_About,&QAction::triggered,this,&MainWindow::aboutAction);
    //connect(ui->action_About, SIGNAL(clicked()), this, SLOT(AboutAction()));

    //guidedialog设置
    guide = new GuideDialog(this);
    guide->setWindowModality(Qt::ApplicationModal);
    guide->setFixedSize(guide->width(),guide->height());
    connect(ui->actionGuide,&QAction::triggered,this,&MainWindow::guideAction);

    //设置logo和title
    this->setWindowTitle("WebServer");
    QIcon icon(":/picture/images/webserver.ico");
    this->setWindowIcon(icon);

    //设置时间显示的字体
    ui->label_CurrentTime->setStyleSheet("QLabel { color: rgb(251,153,104);}");
    //定时器
    QTimer *CurrentTime = new QTimer(this);
    CurrentTime->start(0);
    //使用定时器信号槽，尽快更新时间的显示
    connect(CurrentTime,&QTimer::timeout,[=](){
    QDateTime current_time = QDateTime::currentDateTime();
    //显示时间，格式为：年-月-日 时：分：秒 周几
    QString StrCurrentTime = current_time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_CurrentTime->setText(StrCurrentTime);
    });

    //设置addrLineEdit
    ui->addr_line->setText(QString::fromStdString(Configation::DEFAULT_SERVER_ADDR_STR));

    //设置portSpinBox
    ui->port_spin->setValue(Configation::DEFAULT_SERVER_PORT);

    //设置maxSpinBox
    ui->maxConnect_spin->setValue(Configation::MAX_CONNECTION_NUM);

    //设置pathLineEdit
    char *tempPath=new char[_MAX_PATH];
    _getcwd(tempPath,_MAX_PATH);//读取当前工作目录
    QString tempQstr(tempPath);
    ui->path_line->setText(tempQstr);
    delete tempPath;

    //设置showTableWidget
    ui->Show_table->setColumnCount(7);
    ui->Show_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList tableHeaders;
    tableHeaders<<"Time"<<"IP"<<"Port"<<"Method"<<"Url"<<"File Length"<<"Respond";
    ui->Show_table->setHorizontalHeaderLabels(tableHeaders);

#define MAJORVERSION 2  //Winsock主版本号
#define MINORVERSION 2	//Winsock次版本号
    //第一步，初始化winsock，版本2.2
    if((WSAStartup(MAKEWORD(MAJORVERSION,MINORVERSION),&(this->mWsaData)))){
        qDebug()<<"Server initialize winsock error:"<<WSAGetLastError();
    }
    if(this->mWsaData.wVersion != 0x0202){
        WSACleanup();
        qDebug()<<"Server's winsock version error!";
    }
}

MainWindow::~MainWindow()
{
    closesocket(this->srvSocket);
    WSACleanup();
    delete ui;
}

//菜单栏Aboutaction操作函数
void MainWindow::aboutAction()
{
    QMessageBox::information(NULL, QString("About QtWebServer"), QString("作者：物联网1701 胡晗"));
    return;
}

//菜单栏Guide操作函数
void MainWindow::guideAction(){
    guide->show();
    return;
}

//启动服务
void MainWindow::on_start_Button_clicked()
{
    ui->start_Button->setDisabled(true);//未结束前不能再次启动服务
    ui->path_Button->setDisabled(true);

    //第二步，创建服务器套接字
    this->srvSocket=socket(AF_INET,SOCK_STREAM,0);
    if(this->srvSocket==INVALID_SOCKET)
    {
        QMessageBox::about(this,"Error","创建服务器套接字失败");
        qDebug()<<"socket error:"<<WSAGetLastError();
        ui->start_Button->setEnabled(true);
        ui->path_Button->setEnabled(true);
        return;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(ui->port_spin->value());
    serverAddr.sin_addr.S_un.S_addr=inet_addr(ui->addr_line->text().toStdString().c_str());
    //第三步，绑定套接字和地址信息
    if((bind(this->srvSocket,(sockaddr*)&serverAddr,sizeof(serverAddr)))==SOCKET_ERROR)
    {
        qDebug()<<"port:"<<ui->port_spin->value();
        qDebug()<<"addr:"<<inet_addr(ui->addr_line->text().toStdString().c_str());
        qDebug()<<"in addr any:"<<htonl(INADDR_ANY);
        QMessageBox::about(this,"Error","绑定套接字失败\n请重试");
        qDebug()<<"bind error:"<<WSAGetLastError();
        ui->start_Button->setEnabled(true);
        ui->path_Button->setEnabled(true);
        return;
    }

    //第四步，端口监听
    if((listen(this->srvSocket,ui->maxConnect_spin->value()))==SOCKET_ERROR)
    {
        QMessageBox::about(this,"Error","监听失败\n请重试");
        qDebug()<<"listen error:"<<WSAGetLastError();
        ui->start_Button->setEnabled(true);
        ui->path_Button->setEnabled(true);
        return;
    }

    //后台启动线程与客户端连接，防止阻塞ui线程
    this->acptThread=new Accept;
    this->acptThread->setListenSocket(this->srvSocket);
    this->acptThread->setMainPath(ui->path_line->text().toStdString());
    this->acptThread->start();

    //接收线程rpdThread发来的信号，更新UI，待实现
    connect(this->acptThread,&Accept::acceptOK,[=](QStringList msg){
        qDebug()<<endl<<"msg length:"<<msg.length()<<endl;
        ui->Show_table->insertRow(ui->Show_table->rowCount());//插入一行
        QString tempStr;
        int rowIndex=ui->Show_table->rowCount();
        for(int i=0;i<msg.length();i++)
        {
            tempStr=msg.at(i);
            qDebug()<<"msg "<<i<<":"<<tempStr;
            QTableWidgetItem *item=new QTableWidgetItem(tempStr);
            ui->Show_table->setItem(rowIndex-1,i,item);
        }
    });
}

//关闭程序
void MainWindow::closeEvent(QCloseEvent *event){
    if(this->acptThread!=nullptr){
        delete this->acptThread;
        this->acptThread=nullptr;
    }
}


void MainWindow::on_stop_Button_clicked()
{
    //关闭线程
    if(this->acptThread!=nullptr){
       delete this->acptThread;
       this->acptThread=nullptr;
    }
    QMessageBox::about(this,"reminder","关闭服务完成");
    ui->start_Button->setEnabled(true);
    ui->path_Button->setEnabled(true);
    //    ui->showTableWidget->clear();
}


void MainWindow::on_path_Button_clicked()
{
    QString str=QFileDialog::getExistingDirectory(this,"打开主目录",".");
    ui->path_line->setText(str);
}
