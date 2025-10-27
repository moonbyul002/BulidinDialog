#include "cbuiltindlg.h"
#include "ui_cbuiltindlg.h"
#include<QGridLayout>
#include<QtWidgets>
cbuiltindlg::cbuiltindlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cbuiltindlg)
{
    QGridLayout *gridLayout=new QGridLayout;
    displayTextEdit =new QTextEdit(QStringLiteral("Qt標準通用對話盒"));
    colorPushBtn    =new QPushButton(QStringLiteral("顏色對話盒"));
    errorPushBtn    =new QPushButton(QStringLiteral("錯誤對話盒"));
    filePushBtn     =new QPushButton(QStringLiteral("檔案對話盒"));
    fontPushBtn     =new QPushButton(QStringLiteral("字體對話盒"));
    inputPushBtn    =new QPushButton(QStringLiteral("輸入對話盒"));
    pagePushBtn     =new QPushButton(QStringLiteral("頁面設定對話盒"));
    progressPushBtn =new QPushButton(QStringLiteral("進度對話盒"));
    printPushBtn    =new QPushButton(QStringLiteral("列印對話盒"));
    gridLayout->addWidget (colorPushBtn,0,0,1,1);
    gridLayout->addWidget (errorPushBtn,0,1,1,1);
    gridLayout->addWidget (filePushBtn,0,2,1,1);
    gridLayout->addWidget (fontPushBtn,1,0,1,1);
    gridLayout->addWidget(inputPushBtn,1,1,1,1);
    gridLayout->addWidget (pagePushBtn,1,2,1,1);
    gridLayout->addWidget (progressPushBtn,2,0,1,1);
    gridLayout->addWidget (printPushBtn,2,1,1,1);
    gridLayout->addWidget (displayTextEdit, 3,0,3,3);
    setLayout (gridLayout);
    setWindowTitle (QStringLiteral("內建對話盒展示"));
    resize (400,300);
    connect (colorPushBtn, SIGNAL (clicked()), this, SLOT (doPushBtn()));
    connect (errorPushBtn, SIGNAL (clicked()),this, SLOT (doPushBt()));
    connect (filePushBtn, SIGNAL(clicked()), this, SLOT (doPushBtn()));
    connect (fontPushBtn, SIGNAL (clicked()), this, SLOT (doPushBtn()));
    connect (inputPushBtn, SIGNAL (clicked()),this, SLOT (doPushBtn()));
    connect (progressPushBtn, SIGNAL (clicked()),this, SLOT (doPushBtn()));
    connect (pagePushBtn, SIGNAL (clicked()), this, SLOT (doPushBtn()));
    connect (printPushBtn, SIGNAL (clicked()),this, SLOT (doPushBtn()));
    ui->setupUi(this);
}
void cbuiltindlg::doPushBtn(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    if (btn == colorPushBtn)
    {
        QPalette palette=displayTextEdit->palette();
        const QColor& color=
            QColorDialog::getColor(palette.color (QPalette::Base),
                                   this, QStringLiteral("設定背景顏色"));
        if (color.isValid())
        {
            palette.setColor(QPalette:: Base, color);
            displayTextEdit->setPalette (palette);
        }
    }
if (btn == errorPushBtn)
{
QErrorMessage box (this);
box.setWindowTitle (QStringLiteral("錯誤訊息盒"));
box.showMessage (QStringLiteral("錯誤訊息盒實例xx:"));
box.showMessage (QStringLiteral("錯誤訊息盒實例yy:"));
box.showMessage (QStringLiteral("錯誤訊息盒實例zz:"));
box.exec();
}
}
cbuiltindlg::~cbuiltindlg()
{
    delete ui;
}
