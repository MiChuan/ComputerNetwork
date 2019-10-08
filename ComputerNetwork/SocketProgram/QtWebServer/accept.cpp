#include "accept.h"
#include <QDebug>
#include <winsock2.h>

Accept::Accept(QObject *parent):QThread(parent)
{
    qDebug()<<"accept thread: "<<QThread::currentThreadId();
}

Accept::~Accept(){
    requestInterruption();
    terminate();
    quit();
    wait();
    qDebug()<<"析构: accept thread";
    closesocket(this->listenSocket);
    qDebug()<<"accept thread 析构，socket关闭";
    qDebug()<<"accept thread running:"<<isRunning();
    emit acceptDone();
}

void Accept::setListenSocket(SOCKET s){
    this->listenSocket = s;
}

void Accept::setMainPath(std::string str){
    this->mainPath = str;
}

//run函数执行核心功能
void Accept::run()
{
    SOCKET sAccept;
    sockaddr_in clientAddr;
    int iLen=sizeof(clientAddr);
    int i=0;//for debug
    while(!isInterruptionRequested())
    {
        //缓存清零
        memset(&clientAddr,0,sizeof(clientAddr));
        //等待新客户端连接，阻塞函数必须用terminate打断，requestinterruption不管用
        //利用ioctlsocket设置非阻塞,待实现
        sAccept=accept(this->listenSocket,(sockaddr*)&clientAddr,&iLen);
        if(sAccept==INVALID_SOCKET)
        {
            qDebug()<<"accept error:"<<WSAGetLastError();
            return;
        }
        qDebug()<<"accept start i:"<<i;
        i++;
        //如果不是监听端口或者监听地址，直接断开连接，发送拒绝请求页面

        //开启新线程与客户端通信
        this->rpdThread=new Respond;
        this->rpdThread->setAcceptSocket(sAccept);
        this->rpdThread->setMainPath(this->mainPath);
        this->rpdThread->setClientAddr(clientAddr);
        rpdThread->start();

        connect(rpdThread,&Respond::respondDone,this,[=](QStringList msg){
            emit acceptOK(msg);
        });

        connect(this,&Accept::acceptDone,this,[=](){
            delete rpdThread;
            rpdThread=nullptr;
        });
    }
}
