#include "guidedialog.h"
#include "ui_guidedialog.h"

GuideDialog::GuideDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuideDialog)
{
    ui->setupUi(this);
}

GuideDialog::~GuideDialog()
{
    delete ui;
}
