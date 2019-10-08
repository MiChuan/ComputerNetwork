/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_About;
    QAction *actionGuide;
    QWidget *centralWidget;
    QTableWidget *Show_table;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *addr_label;
    QLineEdit *addr_line;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *port_label;
    QSpinBox *port_spin;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *maxConnect_label;
    QSpinBox *maxConnect_spin;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *path_label;
    QLineEdit *path_line;
    QPushButton *path_Button;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *start_Button;
    QPushButton *stop_Button;
    QLabel *label_CurrentTime;
    QMenuBar *menuBar;
    QMenu *help;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(801, 493);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/picture/images/aboutus.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_About->setIcon(icon);
        QFont font;
        font.setFamily(QStringLiteral("Snap ITC"));
        action_About->setFont(font);
        actionGuide = new QAction(MainWindow);
        actionGuide->setObjectName(QStringLiteral("actionGuide"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/picture/images/guide.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionGuide->setIcon(icon1);
        QFont font1;
        font1.setFamily(QStringLiteral("Snap ITC"));
        font1.setBold(false);
        font1.setWeight(50);
        actionGuide->setFont(font1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Show_table = new QTableWidget(centralWidget);
        Show_table->setObjectName(QStringLiteral("Show_table"));
        Show_table->setGeometry(QRect(20, 10, 421, 431));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(470, 70, 291, 23));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addr_label = new QLabel(horizontalLayoutWidget);
        addr_label->setObjectName(QStringLiteral("addr_label"));

        horizontalLayout->addWidget(addr_label);

        addr_line = new QLineEdit(horizontalLayoutWidget);
        addr_line->setObjectName(QStringLiteral("addr_line"));

        horizontalLayout->addWidget(addr_line);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(470, 130, 139, 23));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        port_label = new QLabel(horizontalLayoutWidget_2);
        port_label->setObjectName(QStringLiteral("port_label"));

        horizontalLayout_2->addWidget(port_label);

        port_spin = new QSpinBox(horizontalLayoutWidget_2);
        port_spin->setObjectName(QStringLiteral("port_spin"));
        port_spin->setMinimum(-1);
        port_spin->setMaximum(65535);

        horizontalLayout_2->addWidget(port_spin);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(470, 190, 160, 23));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        maxConnect_label = new QLabel(horizontalLayoutWidget_3);
        maxConnect_label->setObjectName(QStringLiteral("maxConnect_label"));

        horizontalLayout_3->addWidget(maxConnect_label);

        maxConnect_spin = new QSpinBox(horizontalLayoutWidget_3);
        maxConnect_spin->setObjectName(QStringLiteral("maxConnect_spin"));
        maxConnect_spin->setMaximum(65535);
        maxConnect_spin->setValue(100);

        horizontalLayout_3->addWidget(maxConnect_spin);

        horizontalLayoutWidget_4 = new QWidget(centralWidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(470, 250, 291, 23));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        path_label = new QLabel(horizontalLayoutWidget_4);
        path_label->setObjectName(QStringLiteral("path_label"));

        horizontalLayout_4->addWidget(path_label);

        path_line = new QLineEdit(horizontalLayoutWidget_4);
        path_line->setObjectName(QStringLiteral("path_line"));

        horizontalLayout_4->addWidget(path_line);

        path_Button = new QPushButton(centralWidget);
        path_Button->setObjectName(QStringLiteral("path_Button"));
        path_Button->setGeometry(QRect(760, 250, 31, 21));
        horizontalLayoutWidget_5 = new QWidget(centralWidget);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(540, 390, 195, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        start_Button = new QPushButton(horizontalLayoutWidget_5);
        start_Button->setObjectName(QStringLiteral("start_Button"));

        horizontalLayout_5->addWidget(start_Button);

        stop_Button = new QPushButton(horizontalLayoutWidget_5);
        stop_Button->setObjectName(QStringLiteral("stop_Button"));

        horizontalLayout_5->addWidget(stop_Button);

        label_CurrentTime = new QLabel(centralWidget);
        label_CurrentTime->setObjectName(QStringLiteral("label_CurrentTime"));
        label_CurrentTime->setGeometry(QRect(520, 10, 231, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 801, 26));
        help = new QMenu(menuBar);
        help->setObjectName(QStringLiteral("help"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(help->menuAction());
        help->addAction(action_About);
        help->addAction(actionGuide);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_About->setText(QApplication::translate("MainWindow", "About QtWebServer", nullptr));
        actionGuide->setText(QApplication::translate("MainWindow", "Guide", nullptr));
        addr_label->setText(QApplication::translate("MainWindow", "\347\233\221\345\220\254\345\234\260\345\235\200", nullptr));
        port_label->setText(QApplication::translate("MainWindow", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        maxConnect_label->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\247\350\277\236\346\216\245\346\225\260", nullptr));
        path_label->setText(QApplication::translate("MainWindow", "\344\270\273\347\233\256\345\275\225", nullptr));
        path_Button->setText(QApplication::translate("MainWindow", "..", nullptr));
        start_Button->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", nullptr));
        stop_Button->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        label_CurrentTime->setText(QString());
        help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
