#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegExp regExp("[A-Za-z][0-9]{0,2}");//表示限制输入子元的范围
    ui->lineEdit->setValidator(new QRegExpValidator(regExp,this));
    //使用Validator并且搭配正则表达式"[A-Za-z][0-9]{0,2}"，只允许第一个子元输入大小写英文字母，。。。
    connect(ui->okButton,SIGNAL(clicked(bool)),this,SLOT(accept()));
    //accept表示关闭Dialog窗口，但是结果设为1
    connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(reject()));
    //reject表示关闭Dialog窗口，结果设为0
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textChanged()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
