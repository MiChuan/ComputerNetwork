#-------------------------------------------------
#
# Project created by QtCreator 2019-10-05T20:48:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtWebServer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    configation.cpp \
    respond.cpp \
    accept.cpp \
    guidedialog.cpp

HEADERS += \
        mainwindow.h \
    configation.h \
    respond.h \
    accept.h \
    guidedialog.h

#编译库静态链接，不加会产生编译错误
LIBS += -lpthread libwsock32 libws2_32

FORMS += \
        mainwindow.ui \
    guidedialog.ui

RESOURCES += \
    logo.qrc
