#include "drawer.h"
#include <QGroupBox>
#include <QVBoxLayout>

Drawer::Drawer(QWidget *parent, Qt::WindowFlags f)
    :QToolBox(parent,f)
{
    setWindowTitle(tr("My QQ"));

    toolBtn1_1 =new QToolButton;
    toolBtn1_1->setText(QStringLiteral("张三"));
    toolBtn1_1->setIcon(QPixmap(":/new/1.png"));
    toolBtn1_1->setIconSize(QPixmap(":/new/1.png").size());
    toolBtn1_1->setAutoRaise(true);//当鼠标离开时，按钮自动恢复为弹起状态
    toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //设置按钮的ToolButtonStyle属性
    /*
     *有四种属性：
     * Qt::ToolButtonIconOnly只显示图标
     * Qt::ToolButtonTextOnly只显示文字
     * Qt::ToolButtonTextBesideIcon文字显示在图标旁边
     * Qt::ToolButtonTextUnderIcon文字显示在图标下面
     * Qt::ToolButtonFollowStyle遵循style标准
     */

    toolBtn1_2 =new QToolButton;
    toolBtn1_2->setText(QStringLiteral("李四"));
    toolBtn1_2->setIcon(QPixmap(":/new/2.png"));
    toolBtn1_2->setIconSize(QPixmap(":/new/2.png").size());
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_3 =new QToolButton;
    toolBtn1_3->setText(QStringLiteral("王五"));
    toolBtn1_3->setIcon(QPixmap(":/new/3.png"));
    toolBtn1_3->setIconSize(QPixmap(":/new/3.png").size());
    toolBtn1_3->setAutoRaise(true);
    toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_4 =new QToolButton;
    toolBtn1_4->setText(QStringLiteral("小赵"));
    toolBtn1_4->setIcon(QPixmap(":/new/4.png"));
    toolBtn1_4->setIconSize(QPixmap(":/new/4.png").size());
    toolBtn1_4->setAutoRaise(true);
    toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_5 =new QToolButton;
    toolBtn1_5->setText(QStringLiteral("小孙"));
    toolBtn1_5->setIcon(QPixmap(":/new/5.png"));
    toolBtn1_5->setIconSize(QPixmap(":/new/5.png").size());
    toolBtn1_5->setAutoRaise(true);
    toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox1=new QGroupBox;
    QVBoxLayout *layout1=new QVBoxLayout(groupBox1);    //(groupBox1);
    layout1->setMargin(10);                             //布局中各窗体的显示间距
    layout1->setAlignment(Qt::AlignHCenter);            //布局中各窗体的显示位置
    layout1->addWidget(toolBtn1_1);
    layout1->addWidget(toolBtn1_2);
    layout1->addWidget(toolBtn1_3);
    layout1->addWidget(toolBtn1_4);
    layout1->addWidget(toolBtn1_5);
    layout1->addStretch();
    //插入一个占位符，使得所有按钮能够靠上对齐，并且在整个抽屉大小发生改变时保证按钮的大小不发生变化


    toolBtn2_1 =new QToolButton;
    toolBtn2_1->setText(QStringLiteral("小王"));
    toolBtn2_1->setIcon(QPixmap(":/new/6.png"));
    toolBtn2_1->setIconSize(QPixmap(":/new/6.png").size());
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn2_2 =new QToolButton;
    toolBtn2_2->setText(QStringLiteral("小张"));
    toolBtn2_2->setIcon(QPixmap(":/new/7.png"));
    toolBtn2_2->setIconSize(QPixmap(":/new/7.png").size());
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox2=new QGroupBox;
    QVBoxLayout *layout2=new QVBoxLayout(groupBox2);
    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignHCenter);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);

    toolBtn3_1 =new QToolButton;
    toolBtn3_1->setText(QStringLiteral("小陈"));
    toolBtn3_1->setIcon(QPixmap(":/new/8.png"));
    toolBtn3_1->setIconSize(QPixmap(":/new/8.png").size());
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn3_2 =new QToolButton;
    toolBtn3_2->setText(QStringLiteral("小李"));
    toolBtn3_2->setIcon(QPixmap(":/new/9.png"));
    toolBtn3_2->setIconSize(QPixmap(":/new/9.png").size());
    toolBtn3_2->setAutoRaise(true);
    toolBtn3_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox3=new QGroupBox;
    QVBoxLayout *layout3=new QVBoxLayout(groupBox3);
    layout3->setMargin(10);
    layout3->setAlignment(Qt::AlignHCenter);
    layout3->addWidget(toolBtn3_1);
    layout3->addWidget(toolBtn3_2);

    this->addItem((QWidget*)groupBox1,QStringLiteral("我的好友"));
    this->addItem((QWidget*)groupBox2,QStringLiteral("陌生人"));
    this->addItem((QWidget*)groupBox3,QStringLiteral("黑名单"));
}
