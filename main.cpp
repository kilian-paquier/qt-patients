#include "controler/controler.h"
#include "model/c_init_bd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controler controler;
    controler.getWindow().show();
    C_INIT_BD::Creation_BD();

    return a.exec();
}
