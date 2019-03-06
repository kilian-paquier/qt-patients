#include "view/mainwindow.h"
#include <QApplication>
#include "model/utils.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Controler c;
    w.setController(c);
    w.show();

    return a.exec();
}
