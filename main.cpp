#include "Source/MyMainQtGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainQtGUI w;
    w.show();
    return a.exec();
}
