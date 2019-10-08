#ifndef ACCEPT_H
#define ACCEPT_H
#include <QThread>
#include <winsock2.h>
#include <QObject>
#include <string>
#include "respond.h"
#include <QThread>

using std::string;

class Accept:public QThread
{
    Q_OBJECT
public:
    explicit Accept(QObject *parent=0);
    ~Accept();
    void setListenSocket(SOCKET s);
    void setMainPath(string str);
    void run();
signals:
    void acceptOK(QStringList msg);
    void acceptDone();
    //    void acceptFailed();
private:
    SOCKET listenSocket;
    string mainPath;
    Respond *rpdThread;
};

#endif // ACCEPT_H
