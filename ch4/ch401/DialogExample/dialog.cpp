﻿#include "dialog.h"
#include <QGridLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(QStringLiteral("各种标准对话框的实例"));
    fileBtn=new QPushButton;
    fileBtn->setText(QStringLiteral(" 文件标准对话框实例 "));
    fileLineEdit=new QLineEdit;

    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));

    colorBtn=new QPushButton;
    colorBtn->setText(QStringLiteral(" 颜色标准对话框实例 "));
    colorFrame=new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);

    mainLayout->addWidget(colorBtn,1,0);
    mainLayout->addWidget(colorFrame,1,1);
    connect(colorBtn,SIGNAL(clicked(bool)),this,SLOT(showColor()));

    fontBtn=new QPushButton;
    fontBtn->setText(QStringLiteral(" 字体标准对话框实例 "));
    fontLineEdit=new QLineEdit;
    fontLineEdit->setText(tr("Welcone!"));

    mainLayout->addWidget(fontBtn,2,0);
    mainLayout->addWidget(fontLineEdit,2,1);
    connect(fontBtn,SIGNAL(clicked(bool)),this,SLOT(showFont()));

    inputBtn=new QPushButton;
    inputBtn->setText(QStringLiteral(" 标准输入对话框实例 "));

    mainLayout->addWidget(inputBtn,3,0);
    connect(inputBtn,SIGNAL(clicked(bool)),this,SLOT(showInputDlg()));

    MsgBtn=new QPushButton;
    MsgBtn->setText(QStringLiteral(" 标准消息对话框实例 "));

    mainLayout->addWidget(MsgBtn,3,1);
    connect(MsgBtn,SIGNAL(clicked(bool)),this,SLOT(showMsgDlg()));

    CustomBtn=new QPushButton;
    CustomBtn->setText(QStringLiteral("用户自定义消息对话框实例"));
    label=new QLabel;
    label->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    mainLayout->addWidget(CustomBtn,4,0);
    mainLayout->addWidget(label,4,1);
    connect(CustomBtn,SIGNAL(clicked(bool)),this,SLOT(showCustomDlg()));

}

Dialog::~Dialog()
{

}


void Dialog::showFile()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/",
                                                      tr("files (*.c *.h *.cpp)"));
    fileLineEdit->setText(s);
}

void Dialog::showColor()
{
    QColor c=QColorDialog::getColor(Qt::blue);
    if(c.isValid())
           colorFrame->setPalette(QPalette(c));
}

void Dialog::showFont()
{
    bool ok;
    QFont f=QFontDialog::getFont(&ok);
    if(ok)
        fontLineEdit->setFont(f);
}

void Dialog::showInputDlg()
{
    inputDlg=new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg=new MsgBoxDlg();
    msgDlg->show();
}

void Dialog::showCustomDlg()
{
    label->setText(tr("Custom Message Box"));
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(QStringLiteral("用户自定义消息框"));

    QPushButton *yesBtn=customMsgBox.addButton(tr("Yes"),QMessageBox::ActionRole);
    QPushButton *noBtn=customMsgBox.addButton(tr("No"),QMessageBox::ActionRole);
    QPushButton *cancelBtn=customMsgBox.addButton(QMessageBox::Cancel);
    customMsgBox.setText(QStringLiteral("这是一个用户自定义消息框！"));
    customMsgBox.setIconPixmap(QPixmap(":/new/file-save.png"));
    customMsgBox.exec();

    if(customMsgBox.clickedButton()==yesBtn)
           label->setText("Custom Message Box/Yes");
    if(customMsgBox.clickedButton()==noBtn)
           label->setText("Custom Message Box/No");
    if(customMsgBox.clickedButton()==cancelBtn)
           label->setText("Custom Message Box/Cancel");

}
