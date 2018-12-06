#include "level1.h"
#include <QApplication>
#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu m;
    m.show();
    //MainWindow w;
    //w.show();

    return a.exec();
}
