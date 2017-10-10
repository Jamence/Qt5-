#ifndef PALETTE_H
#define PALETTE_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>

class Palette : public QDialog
{
    Q_OBJECT

public:
    Palette(QWidget *parent = 0);
    ~Palette();
    void createCtrlFrame();				//瀹屾垚绐椾綋宸﹀崐閮ㄥ垎棰滆壊閫夋嫨鍖虹殑鍒涘缓
    void createContentFrame();			//瀹屾垚绐椾綋鍙冲崐閮ㄥ垎鐨勫垱寤?
    void fillColorList(QComboBox *);	//瀹屾垚鍚戦鑹蹭笅鎷夊垪琛ㄦ涓彃鍏ラ鑹茬殑宸ヤ綔
private slots:
    void ShowWindow();
    void ShowWindowText();
    void ShowButton();
    void ShowButtonText();
    void ShowBase();
private:
    QFrame *ctrlFrame;                  //棰滆壊閫夋嫨闈㈡澘
    QLabel *windowLabel;
    QComboBox *windowComboBox;
    QLabel *windowTextLabel;
    QComboBox *windowTextComboBox;
    QLabel *buttonLabel;
    QComboBox *buttonComboBox;
    QLabel *buttonTextLabel;
    QComboBox *buttonTextComboBox;
    QLabel *baseLabel;
    QComboBox *baseComboBox;
    QFrame *contentFrame;              	//鍏蜂綋鏄剧ず闈㈡澘
    QLabel *label1;
    QComboBox *comboBox1;
    QLabel *label2;
    QLineEdit *lineEdit2;
    QTextEdit *textEdit;
    QPushButton *OkBtn;
    QPushButton *CancelBtn;
};

#endif // PALETTE_H
