/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *centralWidget;
    QLabel *radiusLabel;
    QLabel *areaLabel_1;
    QLabel *areaLabel_2;
    QLineEdit *radiusLineEdit;
    QPushButton *countBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        centralWidget = new QWidget(Dialog);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        radiusLabel = new QLabel(centralWidget);
        radiusLabel->setObjectName(QStringLiteral("radiusLabel"));
        radiusLabel->setGeometry(QRect(0, 120, 54, 12));
        areaLabel_1 = new QLabel(centralWidget);
        areaLabel_1->setObjectName(QStringLiteral("areaLabel_1"));
        areaLabel_1->setGeometry(QRect(160, 120, 54, 12));
        areaLabel_2 = new QLabel(centralWidget);
        areaLabel_2->setObjectName(QStringLiteral("areaLabel_2"));
        areaLabel_2->setGeometry(QRect(210, 120, 54, 12));
        areaLabel_2->setFrameShape(QFrame::Panel);
        areaLabel_2->setFrameShadow(QFrame::Sunken);
        radiusLineEdit = new QLineEdit(centralWidget);
        radiusLineEdit->setObjectName(QStringLiteral("radiusLineEdit"));
        radiusLineEdit->setGeometry(QRect(60, 120, 81, 20));
        countBtn = new QPushButton(centralWidget);
        countBtn->setObjectName(QStringLiteral("countBtn"));
        countBtn->setGeometry(QRect(120, 180, 75, 23));
        Dialog->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Dialog);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        Dialog->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Dialog);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Dialog->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Dialog);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Dialog->setStatusBar(statusBar);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QMainWindow *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        radiusLabel->setText(QApplication::translate("Dialog", "\345\215\212\345\276\204\357\274\232", Q_NULLPTR));
        areaLabel_1->setText(QApplication::translate("Dialog", "\351\235\242\347\247\257\357\274\232", Q_NULLPTR));
        areaLabel_2->setText(QString());
        countBtn->setText(QApplication::translate("Dialog", "\350\256\241\347\256\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
