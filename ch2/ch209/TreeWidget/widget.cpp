#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget,SIGNAL(itemChanged(QTreeWidgetItem*, int)),
                this, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
    /*
     * itemChanged(QTreeWidgetItem*, int)
     * 信号表示：
     *
     * This signal is emitted when the contents of the column in the specified item changes.
     * 表示只有选中了其中一个树形选框，才能发出信号
     */
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->treeWidget->clear();
    /*
     * Clears the tree widget by removing all of its items and selections.
     */
    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "group1");
    /*
     * void QTreeWidgetItem::setText(int column, const QString &text)
     *
     * Sets the text to be displayed in the given column to the given text.
     */
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt:: ItemIsSelectable);
    /*
     * void QTreeWidgetItem::setFlags(Qt::ItemFlags flags)
     *
     * Sets the flags for the item to the given flags.
     * These determine whether the item can be selected or modified.
     * This is often used to disable an item.
     *
     * Qt::ItemIsUserCheckable
     * 表示：It can be checked or unchecked by the user.
     *
     * Qt::ItemIsEnabled
     * 表示：The user can interact with the item.
     *
     * Qt:: ItemIsSelectable
     * 表示：It can be selected.
     */
    group1->setCheckState(0, Qt::Unchecked);
    /*
     * void QTreeWidgetItem::setCheckState(int column, Qt::CheckState state)
     * Sets the item in the given column check state to be state.
     *
     * Qt::Unchecked
     * 表示：The item is unchecked.
     * 是指初始状态是有没有被选中，
     * 如果是checked,表示被选中
     * 如果是Unchecked，表示没有被选中
     */
    QTreeWidgetItem *subItem11 = new QTreeWidgetItem(group1);
    subItem11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt:: ItemIsSelectable);
    subItem11->setText(0, "subItem11");
    subItem11->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem12 = new QTreeWidgetItem(group1);
    subItem12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt:: ItemIsSelectable);
    subItem12->setText(0, "subItem12");
    subItem12->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem13 = new QTreeWidgetItem(group1);
    subItem13->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem13->setText(0, "subItem13");
    subItem13->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem14 = new QTreeWidgetItem(group1);
    subItem14->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt:: ItemIsSelectable);
    subItem14->setText(0, "subItem14");
    subItem14->setCheckState(0, Qt::Unchecked);
    //加上group2
    QTreeWidgetItem *group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0, "group2");
    group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt:: ItemIsSelectable);
    group2->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem21 = new QTreeWidgetItem(group2);
    subItem21->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt:: ItemIsSelectable);
    subItem21->setText(0, "subItem21");
    subItem21->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem22 = new QTreeWidgetItem(group2);
    subItem22->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt:: ItemIsSelectable);
    subItem22->setText(0, "subItem22");
    subItem22->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem23 = new QTreeWidgetItem(group2);
    subItem23->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt:: ItemIsSelectable);
    subItem23->setText(0, "subItem23");
    subItem23->setCheckState(0, Qt::Unchecked);
}

void Widget::treeItemChanged(QTreeWidgetItem* item, int column)
{
    qDebug()<<"调用"<<'\n';
    QString itemText = item->text(0);
    //表示选中的树形框的名称
    QString itemText1=item->text(1);
//    qDebug()<<itemText<<"  "<<itemText1<<'\n';
    //如果选中了，打了勾
    if (Qt::Checked == item->checkState(0))
    {
           QTreeWidgetItem* parent = item->parent();
           int count = item->childCount();//表示子树的树形框的个数
           if (count > 0)
           {
                for (int i = 0; i < count; i++)
                {
                      item->child(i)->setCheckState(0, Qt::Checked);
                }
           }
           else
           {
                updateParentItem(item);
           }
    }
    //选中了，但是没有打勾
    else if (Qt::Unchecked == item->checkState(0))
    {
           int count = item->childCount();
           if (count > 0)
           {
                for (int i = 0; i < count; i++)
                {
                 item->child(i)->setCheckState(0, Qt::Unchecked);
                }
           }
           else
           {
                updateParentItem(item);
           }
    }
}

void Widget::updateParentItem(QTreeWidgetItem* item)
{
    QTreeWidgetItem *parent = item->parent();
    if (parent == NULL)
    {
         return;
    }
    int selectedCount = 0;
    int childCount = parent->childCount();
    for (int i = 0; i < childCount; i++)
    {
         QTreeWidgetItem *childItem = parent->child(i);
         if (childItem->checkState(0) == Qt::Checked)
         {
                selectedCount++;
         }
    }
    if (selectedCount <= 0)
    {
         parent->setCheckState(0, Qt::Unchecked);
    }
    else if (selectedCount > 0 && selectedCount < childCount)
    {
         parent->setCheckState(0, Qt::PartiallyChecked);
    }
    else if (selectedCount == childCount)
    {
         parent->setCheckState(0, Qt::Checked);
    }
}
