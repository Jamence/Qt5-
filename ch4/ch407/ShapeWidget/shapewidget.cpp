#include "shapewidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

ShapeWidget::ShapeWidget(QWidget *parent)
    : QWidget(parent)
{
    QPixmap pix;
    pix.load(":/new/prefix1/9.png",0,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);
    resize(pix.size());
    setMask(QBitmap(pix.mask()));
    //为调用它的控件增加一个遮罩，遮住所选区域以外的部分使其看起来
    //是透明的，它的参数可为一个
    //QBitmap对象或一个QRegion对象，此处调用QPixmap的mask（）函数用于获得图片自身的遮罩
}

ShapeWidget::~ShapeWidget()
{

}

void ShapeWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragPosition =event->globalPos()-frameGeometry().topLeft();
        event->accept();
        /*
         *如果是鼠标左键， 保存当前鼠标所在位置相对于窗口左上角的偏移值
         */
    }
    if(event->button()==Qt::RightButton)
    {
        close();
    }
}

void ShapeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
    /*
     * event->buttons()返回鼠标的状态，若是左键，则将窗体移动到鼠标当前点
     * move函数的参数指的是窗口左上角的位置
    */
}

void ShapeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/new/prefix1/9.png"));
}
