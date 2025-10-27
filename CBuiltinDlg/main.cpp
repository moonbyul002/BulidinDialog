#include "cbuiltindlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cbuiltindlg w;
    w.show();
    return a.exec();
}
