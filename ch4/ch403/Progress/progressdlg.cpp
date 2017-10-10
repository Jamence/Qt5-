#include "progressdlg.h"
#include <QProgressDialog>
#include <QFont>
ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    QFont font("ZYSong19030",12);
    setFont(font);
    setWindowTitle(tr("Progress"));

    FileNum=new QLabel;
    FileNum->setText(QStringLiteral("文件数目 "));
    FileNumLineEdit=new QLineEdit;
    FileNumLineEdit->setText(tr("100000"));

    ProgressType=new QLabel;
    ProgressType->setText(QStringLiteral("显示类型"));
    comboBox=new QComboBox;
    comboBox->addItem(tr("progressBar"));
    comboBox->addItem(tr("progressDialog"));

    progressBar=new QProgressBar;

    startBtn=new QPushButton();
    startBtn->setText(QStringLiteral(" 开始 "));

    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(FileNum,0,0);
    mainLayout->addWidget(FileNumLineEdit,0,1);
    mainLayout->addWidget(ProgressType,1,0);
    mainLayout->addWidget(comboBox,1,1);
    mainLayout->addWidget(progressBar,2,0,1,2);
    mainLayout->addWidget(startBtn,3,1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(startBtn,SIGNAL(clicked(bool)),this,SLOT(startProgress()));

}

ProgressDlg::~ProgressDlg()
{

}

void ProgressDlg::startProgress()
{
    bool ok;
    int num=FileNumLineEdit->text().toInt(&ok);
    //ok的作用在于先检测数据是否合理

    if(comboBox->currentIndex()==0){
//        progressBar->setRange(0,num);
        progressBar->setMinimum(0);
        progressBar->setMaximum(num);
        for(int i=1;i<num+1;i++){
               progressBar->setValue(i);
        }
    }
    else{
        QProgressDialog *progressDialog=new QProgressDialog(this);
        QFont font("ZYSong18030",12);
        progressDialog->setFont(font);

        progressDialog->setWindowModality(Qt::WindowModal);
        /*
         * 设置进度对话框采用模态方式进行显示，即显示进度的同时，其他窗口不响应输入信号
         */
        progressDialog->setMinimumDuration(1);
        /*
         * 设置进度对话框需要操作的最短时间，设定为5秒，默认是4秒
         * 如果时间短于minimumduration，则对话框无法出现
         */
        progressDialog->setWindowTitle(tr("Please Wait"));
        progressDialog->setLabelText(tr("Copying..."));
        progressDialog->setCancelButtonText(tr("Cancel"));
        /*
         *设置进度对话框的取消按钮的显示文字
         */
        progressDialog->setRange(0,num);
        for(int i=1;i<num+1;i++){
            progressDialog->setValue(i);
            if(progressDialog->wasCanceled())
                   return ;
        }
    }

}
