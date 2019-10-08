#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <winsock2.h>
#include "accept.h"
#include "guidedialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

private slots:
    void aboutAction();

    void guideAction();

    void on_start_Button_clicked();

    void on_stop_Button_clicked();

    void on_path_Button_clicked();

private:
    Ui::MainWindow *ui;
    WSADATA mWsaData;
    SOCKET srvSocket=INVALID_SOCKET;
    Accept *acptThread;
    GuideDialog *guide;
};

#endif // MAINWINDOW_H
