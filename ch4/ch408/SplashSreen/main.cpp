#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QPixmap pixmap(":/new/prefix1/9.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();//表示程序在显示启动动画的同时还可以响应鼠标等操作


    MainWindow w;
    w.show();
    splash.finish(&w);
    //表示在主窗口对象初始化完成后，结束启动动画

    return a.exec();
}
