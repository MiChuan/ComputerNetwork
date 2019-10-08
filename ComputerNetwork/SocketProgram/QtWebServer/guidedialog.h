#ifndef GUIDEDIALOG_H
#define GUIDEDIALOG_H

#include <QDialog>

namespace Ui {
class GuideDialog;
}

class GuideDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GuideDialog(QWidget *parent = 0);
    ~GuideDialog();

private:
    Ui::GuideDialog *ui;
};

#endif // GUIDEDIALOG_H
