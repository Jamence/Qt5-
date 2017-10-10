#include "digiclock.h"
#include <QTimer>
#include <QTime>
#include <QMouseEvent>

DigiClock::DigiClock(QWidget *parent)
    :QLCDNumber(parent)
{
    QPalette p=palette();
    p.setColor(QPalette::Window,Qt::blue);
    setPalette(p);//设置背景色为蓝色

    setWindowFlags(Qt::FramelessWindowHint);
    //设置窗体为没有面板边框和标题栏
    setWindowOpacity(0.5);
    //设置窗体的透明度
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    //This signal is emitted when the timer times out.
    timer->start(1000);
    showTime();
    resize(150,60);
    //设置电子钟显示的尺寸
    showColon=true;
}

void DigiClock::showTime()
{
    QTime time=QTime::currentTime();
    QString text=time.toString("hh:mm");
    if(showColon)
    {
        text[2]=':';
        showColon=false;
    }
    else
    {
        text[2]=' ';
        showColon=true;
    }
    display(text);
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton)
    {
        close();
    }
}
void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}
