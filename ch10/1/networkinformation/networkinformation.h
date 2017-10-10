#ifndef NETWORKINFORMATION_H
#define NETWORKINFORMATION_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QHostInfo>
#include <QNetworkInterface>

class networkinformation : public QWidget
{
    Q_OBJECT

public:
    networkinformation(QWidget *parent = 0);
    ~networkinformation();
    void getHostInformation();
public slots:
    void slotDetail();
private:
    QLabel *hostLabel;
    QLineEdit *LineEditLocalHostName;
    QLabel *ipLabel;
    QLineEdit *LineEditAddress;

    QPushButton *detailBtn;
    QGridLayout *mainLayout;
};

#endif // NETWORKINFORMATION_H
