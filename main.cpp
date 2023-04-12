#include "Source/MyMainQtGUI.h"
#include <QtWidgets/QApplication>
#include "Source/RESTClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainQtGUI w;
    RESTClient("wad");
    w.show();
    return a.exec();
}
