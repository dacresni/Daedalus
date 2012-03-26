#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //we're going to get the paper size now from a dialoug for graphics view size
    MainWindow w;
    w.show();
    
    return a.exec();
}
