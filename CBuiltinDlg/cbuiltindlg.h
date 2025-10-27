#ifndef CBUILTINDLG_H
#define CBUILTINDLG_H

#include <QDialog>
#include<QtWidgets>
#include<QPushButton>
#include<QTextEdit>
QT_BEGIN_NAMESPACE
namespace Ui {
class cbuiltindlg;
}
QT_END_NAMESPACE

class cbuiltindlg : public QDialog
{
    Q_OBJECT

public:
    cbuiltindlg(QWidget *parent = nullptr);
    ~cbuiltindlg();

private:
    Ui::cbuiltindlg *ui;
    QTextEdit   *displayTextEdit;
    QPushButton *colorPushBtn;
    QPushButton *errorPushBtn;
    QPushButton *filePushBtn;
    QPushButton *fontPushBtn;
    QPushButton *inputPushBtn;
    QPushButton *pagePushBtn;
    QPushButton *progressPushBtn;
    QPushButton *printPushBtn;
};
#endif // CBUILTINDLG_H
