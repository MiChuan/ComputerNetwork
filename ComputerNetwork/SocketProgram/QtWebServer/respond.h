#ifndef RESPOND_H
#define RESPOND_H
#include <QObject>
#include <QThread>
#include <string>
#include <winsock2.h>

class Respond : public QThread
{
    Q_OBJECT
public:
    explicit Respond(QObject *parent=0);
    ~Respond();
    void run();
    void setAcceptSocket(SOCKET s);
    void setClientAddr(sockaddr_in addr);
    void setMainPath(std::string str);

signals:
    void respondDone(QStringList msg);
private:
    SOCKET acceptSocket;
    sockaddr_in clientSock;
    std::string mainPath;
    std::string clientAddrStr;
    int clientPort;
    std::string method;
    std::string url;
    std::string statusCode;
    int fileLength=0;
};

#endif // RESPOND_H
