#include "msgboxdlg.h"
#include <QMessageBox>
MsgBoxDlg::MsgBoxDlg(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(QStringLiteral("标准消息对话框的实例"));
    label =new QLabel;
    label->setText(QStringLiteral("请选择一种消息框"));

    questionBtn =new QPushButton;
    questionBtn->setText(tr("QuestionMsg"));

    informationBtn =new QPushButton;
    informationBtn->setText(tr("InformationMsg"));

    warningBtn =new QPushButton;
    warningBtn->setText(tr("WarningMsg"));

    criticalBtn =new QPushButton;
    criticalBtn->setText(tr("CriticalMsg"));

    aboutBtn =new QPushButton;
    aboutBtn->setText(tr("AboutMsg"));

    aboutQtBtn =new QPushButton;
    aboutQtBtn->setText(tr("AboutQtMsg"));

    //甯冨眬
    mainLayout =new QGridLayout(this);
    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informationBtn,1,1);
    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(criticalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);

    //浜嬩欢鍏宠仈
    connect(questionBtn,SIGNAL(clicked()),this,SLOT(showQuestionMsg()));
    connect(informationBtn,SIGNAL(clicked()),this,SLOT(showInformationMsg()));
    connect(warningBtn,SIGNAL(clicked()),this,SLOT(showWarningMsg()));
    connect(criticalBtn,SIGNAL(clicked()),this,SLOT(showCriticalMsg()));
    connect(aboutBtn,SIGNAL(clicked()),this,SLOT(showAboutMsg()));
    connect(aboutQtBtn,SIGNAL(clicked()),this,SLOT(showAboutQtMsg()));
}

void MsgBoxDlg::showQuestionMsg()
{
    label->setText(tr("Question Message Box"));
    switch(QMessageBox::question(this,QStringLiteral("Question消息框 "),
          QStringLiteral("您现在已经修改完成，是否要结束程序？ "),
          QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        label->setText("Question button/Ok");
        break;
    case QMessageBox::Cancel:
        label->setText("Question button/Cancel");
        break;
    default:
        break;
    }
    return;
}
void MsgBoxDlg::showInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this,QStringLiteral("Informatio消息框n"),
                             QStringLiteral("这是information消息框测试，欢迎您！"));
    return;
}
void MsgBoxDlg::showWarningMsg()
{
    label->setText(tr("Warning Message Box"));
    switch(QMessageBox::warning(this,QStringLiteral(" Warning消息框 "),
         QStringLiteral(" 您修改的内容还未保持，是否要保存对文档的修改？ "),
         QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,
         QMessageBox::Save))
    {
    case QMessageBox::Save:
        label->setText(tr("Warning button/Save"));
        break;
    case QMessageBox::Discard:
        label->setText(tr("Warning button/Discard"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("Warning button/Cancel"));
        break;
    default:
        break;
    }
    return;
}
void MsgBoxDlg::showCriticalMsg()
{
    label->setText(tr("Critical Message Box"));
    QMessageBox::critical(this,QStringLiteral("Critical消息框 "),QStringLiteral(" 这是一个critical消息框测试！"));
    return;
}
void MsgBoxDlg::showAboutMsg()
{
    label->setText(tr("About Message Box"));
    QMessageBox::about(this,QStringLiteral(" About消息框 "),QStringLiteral(" 这是一个About消息框测试！"));
    return;
}
void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(tr("About Qt Message Box"));
    QMessageBox::aboutQt(this,QStringLiteral("About Qt消息框 "));
    return;
}
