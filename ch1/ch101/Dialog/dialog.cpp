#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
const static double PI=3.1415;
Dialog::Dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_countBtn_clicked()
{
    bool ok;
    QString tempStr;
    QString valueStr=ui->radiusLineEdit->text();
    int valueInt=valueStr.toInt(&ok);
    qDebug()<<ok<<" "<<valueInt<<'\n';
    double area=valueInt*valueInt*PI;
    ui->areaLabel_2->setText(tempStr.setNum(area));
}

void Dialog::on_radiusLineEdit_textEdited(const QString &arg1)
{
    bool ok;
    QString tempStr;
    QString valueStr=ui->radiusLineEdit->text();
    int valueInt=valueStr.toInt(&ok);
    qDebug()<<ok<<" "<<valueInt<<'\n';
    double area=valueInt*valueInt*PI;
    ui->areaLabel_2->setText(tempStr.setNum(area));
}
