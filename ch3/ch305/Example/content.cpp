#include "content.h"

Content::Content(QWidget *parent)
    :QFrame(parent)
{
    list=new QListWidget(this);
    list->insertItem(0,tr("基本信息 "));
    list->insertItem(1,tr("联系方式 "));
    list->insertItem(2,tr("详细资料" ));

    //堆栈界面
    stack =new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);
    baseInfo =new BaseInfo();
    contact =new Contact();
    detail =new Detail();
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
    ////

    //右边所有的界面
    AmendBtn =new QPushButton(tr("修改"));
    CloseBtn =new QPushButton(tr("关闭"));
    QHBoxLayout *BtnLayout =new QHBoxLayout;
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(AmendBtn);
    BtnLayout->addWidget(CloseBtn);

    QVBoxLayout *RightLayout =new QVBoxLayout;
    RightLayout->setMargin(10);
    RightLayout->setSpacing(6);
    RightLayout->addWidget(stack);
    RightLayout->addLayout(BtnLayout);
    //  //

    QHBoxLayout *mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(list);
    mainLayout->addLayout(RightLayout);
}
