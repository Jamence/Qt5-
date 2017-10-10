//主界面
#include <QStackedWidget>
#include <QPushButton>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"
#include <QListWidget>
class Content : public QFrame
{
    Q_OBJECT
public:
    Content(QWidget *parent=0);
    QStackedWidget *stack;
    QPushButton *AmendBtn;
    QPushButton *CloseBtn;

    QListWidget *list;
    BaseInfo  *baseInfo;
    Contact *contact;
    Detail *detail;
};
