//#pragma execution_character_set("utf-8")
#ifndef DIALOG_H
#define DIALOG_H

#include "msgboxdlg.h"
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include "inputdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    //文件标准对话框实例
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    //主布局
    QGridLayout *mainLayout;

    //颜色标准对话框实例
    QPushButton *colorBtn;
    QFrame *colorFrame;

    //字体标准对话框示例
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;

    //标准输入对话框示例
    QPushButton *inputBtn;
    InputDlg *inputDlg;

    //标准消息对话框示例
    QPushButton *MsgBtn;
    MsgBoxDlg *msgDlg;

    //用户自定义消息对话框实例
    QPushButton *CustomBtn;
    QLabel *label;

private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgDlg();
    void showCustomDlg();
};

#endif // DIALOG_H
