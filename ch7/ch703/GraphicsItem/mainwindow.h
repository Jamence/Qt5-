#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenuBar>
#include <QGraphicsEllipseItem>
#include <QtWidgets>
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initScene();            			//初始化场景
    void createActions();       			//创建主窗体的所有动作
    void createMenus();         			//创建主窗体的菜单栏

public slots:
    void slotNew();              			//新建一个显示窗体
    void slotClear();           			//清除场景中所有的图元

    void slotAddEllipse_TextItem(int i);              //在场景中加入一个椭圆形图元
    void addLine(int start,int end);

private:
    int adj[100][100];
    //已经分配了内存空间
    QGraphicsScene *scene;
    int pos[100][100];
    QAction *newAct;
    QAction *clearAct;
    QAction *exitAct;
    QAction *addEllipseItem_TextAct;
};

#endif // MAINWINDOW_H
