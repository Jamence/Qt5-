#include <QTextCodec>
#include "content.h"
#include <QApplication>
#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec * BianMa = QTextCodec::codecForName ( "GBK" );
//    QMessageBox::information(this, "提示", BianMa->toUnicode("中文显示!"));
//    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    Content w;
    w.show();

    return a.exec();
}
