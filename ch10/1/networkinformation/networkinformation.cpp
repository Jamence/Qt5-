#include "networkinformation.h"

networkinformation::networkinformation(QWidget *parent)
    : QWidget(parent)
{
    hostLabel=new QLabel(tr("LocalHost: "));
    LineEditLocalHostName=new QLineEdit;
    ipLabel=new QLabel(tr("IP Adress is: "));
    LineEditAddress=new QLineEdit;

    detailBtn=new QPushButton(tr("DETAIL"));

    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(hostLabel,0,0);
    mainLayout->addWidget(LineEditLocalHostName,0,1);
    mainLayout->addWidget(ipLabel,1,0);
    mainLayout->addWidget(LineEditAddress,1,1);
    mainLayout->addWidget(detailBtn,2,0,1,2);

    getHostInformation();
    connect(detailBtn,SIGNAL(clicked(bool)),this,SLOT(slotDetail()));
}

networkinformation::~networkinformation()
{

}

void networkinformation::getHostInformation()
{
    QString localHostName=QHostInfo::localHostName();
    LineEditLocalHostName->setText(localHostName);

    QHostInfo hostInfo=QHostInfo::fromName(localHostName);
    QList<QHostAdress>listAddress=hostInfo.addresses();

    if(!listAddress.isEmpty()){
        LineEditAddress->setText(listAddress.first().toString());
    }
}
