#include "view/mainwindow.h"
#include "view/loginwindow.h"
#include <QApplication>
#include <QObject>
#include "model/utils.h"
#include "model/c_init_bd.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    map<int, string> mapTt;

    mapTt.emplace(1, "titi");
    mapTt.emplace(2, "toto");
    mapTt.emplace(3, "tutu");
    mapTt.emplace(4, "tata");

    mapTt.erase(mapTt.find(3));
    mapTt.emplace(0, "tete");

    for (map<int,string>::iterator it = mapTt.begin(); it != mapTt.end(); it++) {
        cout << (*it).second << endl;
    }

    QApplication a(argc, argv);
    // A décommenter pour créer la base de données (pour que le programme fonctionne)
    C_INIT_BD::Creation_BD();
    Utils::initBD();
    MainWindow w;
    LoginWindow login(&w);
    login.show();
    QObject::connect(&login, SIGNAL(accepted()), &w, SLOT(connectionSucceeded()));

    return a.exec();
}
