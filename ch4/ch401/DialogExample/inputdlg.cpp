#include "inputdlg.h"
#include <QInputDialog>
InputDlg::InputDlg(QWidget *parent):
    QDialog(parent)
{
    setWindowTitle(tr(""));

    nameLabel1 =new QLabel;
    nameLabel1->setText(QStringLiteral(" 标准输入对话框的实例 "));
    nameLabel2 =new QLabel;
    nameLabel2->setText(QStringLiteral(" 姓名 "));
    nameLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    nameBtn =new QPushButton;
    nameBtn->setText(QStringLiteral(" 修改姓名 "));

    sexLabel1 =new QLabel;
    sexLabel1->setText(QStringLiteral(" 性别 "));
    sexLabel2 =new QLabel;
    sexLabel2->setText(QStringLiteral(" 男 "));
    sexLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    sexBtn =new QPushButton;
    sexBtn->setText(QStringLiteral(" 修改性别 "));

    ageLabel1 =new QLabel;
    ageLabel1->setText(QStringLiteral("年龄： "));
    ageLabel2 =new QLabel;
    ageLabel2->setText(tr("21"));
    ageLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    ageBtn =new QPushButton;
    ageBtn->setText(QStringLiteral(" 修改年龄 "));

    scoreLabel1 =new QLabel;
    scoreLabel1->setText(QStringLiteral(" 成绩 "));
    scoreLabel2 =new QLabel;
    scoreLabel2->setText(tr("80"));
    scoreLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    scoreBtn =new QPushButton;
    scoreBtn->setText(QStringLiteral(" 修改成绩 "));

    mainLayout =new QGridLayout(this);
    mainLayout->addWidget(nameLabel1,0,0);
    mainLayout->addWidget(nameLabel2,0,1);
    mainLayout->addWidget(nameBtn,0,2);

    mainLayout->addWidget(sexLabel1,1,0);
    mainLayout->addWidget(sexLabel2,1,1);
    mainLayout->addWidget(sexBtn,1,2);

    mainLayout->addWidget(ageLabel1,2,0);
    mainLayout->addWidget(ageLabel2,2,1);
    mainLayout->addWidget(ageBtn,2,2);

    mainLayout->addWidget(scoreLabel1,3,0);
    mainLayout->addWidget(scoreLabel2,3,1);
    mainLayout->addWidget(scoreBtn,3,2);

    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(nameBtn,SIGNAL(clicked()),this,SLOT(ChangeName()));
    connect(sexBtn,SIGNAL(clicked()),this,SLOT(ChangeSex()));
    connect(ageBtn,SIGNAL(clicked()),this,SLOT(ChangeAge()));
    connect(scoreBtn,SIGNAL(clicked()),this,SLOT(ChangeScore()));
}
InputDlg::~InputDlg()
{

}

void InputDlg::ChangeName()
{
    bool ok;
    QString text=QInputDialog::getText(this,tr(" "),tr(" "), QLineEdit::Normal,nameLabel2->text(),&ok);
    if (ok && !text.isEmpty())
        nameLabel2->setText(text);
}
void InputDlg::ChangeSex()
{
    QStringList SexItems;
    SexItems << tr(" ") << tr(" ");

    bool ok;
    QString SexItem = QInputDialog::getItem(this, tr(" "),
      tr(" "), SexItems, 0, false, &ok);
    if (ok && !SexItem.isEmpty())
        sexLabel2->setText(SexItem);
}
void InputDlg::ChangeAge()
{
    bool ok;
    int age = QInputDialog::getInt(this, tr(" "),
     tr(" "), ageLabel2->text().toInt(&ok), 0, 100, 1, &ok);
    if (ok)
        ageLabel2->setText(QString(tr("%1")).arg(age));
}
void InputDlg::ChangeScore()
{
    bool ok;
    double score = QInputDialog::getDouble(this, tr(" "),
     tr(" "),scoreLabel2->text().toDouble(&ok), 0, 100, 1, &ok);
    if(ok)
        scoreLabel2->setText(QString(tr("%1")).arg(score));
}
