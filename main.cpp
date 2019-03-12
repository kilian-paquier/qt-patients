#include "view/mainwindow.h"
#include "view/loginwindow.h"
#include <QApplication>
#include <QObject>
#include "model/utils.h"
#include "model/c_init_bd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Utils::initBD();
    MainWindow w;
    LoginWindow login(&w);
    login.show();
    QObject::connect(&login, SIGNAL(accepted()), &w, SLOT(connectionSucceeded()));

    return a.exec();
}
