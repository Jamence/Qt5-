#include "mainwindow.h"
#include "flashitem.h"
#include "startitem.h"
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QDebug>
#include <QTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    createActions();                    	//创建主窗体的所有动作
    createMenus();                       	//创建主窗体的菜单栏

    scene = new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);

    initScene();                         	//初始化场景

    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);
    view->show();

    setCentralWidget(view);
    resize(550,450);
//    resize(1000,1000);
    setWindowTitle(tr("Graphics Items"));
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::createActions()       	//创建主窗体的所有动作
{
    newAct = new QAction(tr("NEW"),this);
    clearAct = new QAction(tr("CLEAR"),this);
    exitAct = new QAction(tr("EXIT"),this);
    addEllipseItem_TextAct = new QAction(tr("ENTER Ellipse AND TEXT"),this);
    connect(newAct,SIGNAL(triggered()),this,SLOT(slotNew()));
    connect(clearAct,SIGNAL(triggered()),this,SLOT(slotClear()));
    connect(exitAct,SIGNAL(triggered()),this,SLOT(close()));
    connect(addEllipseItem_TextAct,SIGNAL(triggered()),this,SLOT (slotAddEllipse_TextItem()));
}

void MainWindow::createMenus()         	//创建主窗体的菜单栏
{
    QMenu *fileMenu = menuBar()->addMenu(tr("FILE"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(clearAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    QMenu *itemsMenu = menuBar()->addMenu(tr("ELEMENT"));
    itemsMenu->addAction(addEllipseItem_TextAct);
}

void MainWindow::initScene()        	//初始化场景
{
    int i,n;
    for(i=1;i<=6;i++){
        slotAddEllipse_TextItem(i);
    }
    addLine(1,2);
    addLine(1,3);
    addLine(1,4);
    addLine(1,5);

}

void MainWindow::slotNew()        		//新建一个显示窗体
{
    slotClear();
    initScene();

    MainWindow *newWin = new MainWindow;
    newWin->show();
}

void MainWindow::slotClear()        	//清除场景中所有的图元
{
    QList<QGraphicsItem*> listItem = scene->items();

    while(!listItem.empty())
    {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}



void MainWindow::slotAddEllipse_TextItem(int i) 	//在场景中加入一个椭圆形图元
{

    QFont font("Times",16);
    QString string_display=QString::number(i,10);
    QGraphicsTextItem *itemText = new QGraphicsTextItem(string_display);
    itemText->setFont(font);
    itemText->setFlag(QGraphicsItem::ItemIsMovable);
    itemText->setDefaultTextColor(QColor(256,256,256));
    itemText->setPos(30,30);

    QGraphicsEllipseItem *itemEllipse = new QGraphicsEllipseItem(QRectF(0,0,60, 60));
    itemEllipse->setPen(Qt::NoPen);
    itemEllipse->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    itemEllipse->setFlag(QGraphicsItem::ItemIsMovable);

    QGraphicsItemGroup *group=new QGraphicsItemGroup();
    group->addToGroup(itemEllipse);
    group->addToGroup(itemText);
    group->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(group);
    int posx,posy;
    posx=(qrand()%int(scene->sceneRect().width()))-200;
    posy=(qrand()%int(scene->sceneRect().height()))-200;
    group->setPos(posx,posy);
    pos[i][0]=posx;
    pos[i][1]=posy;
}

void MainWindow::addLine(int start,int end)
{
    QGraphicsLineItem *line=new QGraphicsLineItem();
    QPen *pen1=new QPen();
    pen1->setColor(Qt::black);
    line->setPen(*pen1);
    line->setFlag(QGraphicsItem::ItemIsMovable);
    line->setLine(pos[start][0]+30,pos[start][1]+30,pos[end][0]+30,pos[end][1]+30);
    scene->addItem(line);
}
