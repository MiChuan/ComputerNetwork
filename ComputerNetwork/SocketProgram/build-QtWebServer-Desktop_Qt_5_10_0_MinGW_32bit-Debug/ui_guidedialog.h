/********************************************************************************
** Form generated from reading UI file 'guidedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDEDIALOG_H
#define UI_GUIDEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_GuideDialog
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *GuideDialog)
    {
        if (GuideDialog->objectName().isEmpty())
            GuideDialog->setObjectName(QStringLiteral("GuideDialog"));
        GuideDialog->resize(659, 440);
        textBrowser = new QTextBrowser(GuideDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 10, 621, 411));

        retranslateUi(GuideDialog);

        QMetaObject::connectSlotsByName(GuideDialog);
    } // setupUi

    void retranslateUi(QDialog *GuideDialog)
    {
        GuideDialog->setWindowTitle(QApplication::translate("GuideDialog", "Dialog", nullptr));
        textBrowser->setHtml(QApplication::translate("GuideDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">QtWebServer Guide</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. select path, click path_Button to open a folder, which save the sources files, including .html, .jpg, .jpeg, .ico, .txt, ect.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; mar"
                        "gin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. the port, client addr, max connect number are default, if you want set it, please stop server then fill in your value, restart the server.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. open chrome or IE, fill in &quot;127.0.0.1:23456/index.html&quot;(default addr and port), then you can view the homepage of the QtWebServer.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px;\">4. you can get a file from the server, like &quot;three_odd_words.txt&quot;</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5. if you fill in a not exist item, the server will respond &quot;404 - Not Found&quot;</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuideDialog: public Ui_GuideDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDEDIALOG_H
