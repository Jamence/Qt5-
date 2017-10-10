#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QtWidgets>
class dialog : public QDialog
{
    Q_OBJECT

public:
    dialog(QWidget *parent = 0);
    ~dialog();
private:
    QLabel *label1,*label2;
    QLineEdit *lineEdit;
    QPushButton *button;
private slots:
    void showArea();
};

#endif // DIALOG_H
