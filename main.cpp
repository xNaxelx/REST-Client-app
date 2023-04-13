#include "Source/MyMainQtGUI.h"
#include <QtWidgets/QApplication>
#include "Source/RESTClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RESTClient restClient(argv[1]);
    MyMainQtGUI w(&restClient);
    w.show();
    return a.exec();
}
