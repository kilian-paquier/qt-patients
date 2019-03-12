#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QStandardItemModel>

class TreeView
{
private:
    QStandardItemModel * model;
    QStandardItem * title;
    QStandardItem * medecinA;
    QStandardItem * medecinB;
    QStandardItem * kine;
    QStandardItem * psycho;
    QStandardItem * infirmiere;
    QStandardItem * radiologue;
    QStandardItem * informaticien;
public:
    TreeView();
    ~TreeView();

    QStandardItemModel & getModel();
    QStandardItem & getMedecinA();
    QStandardItem & getMedecinB();
    QStandardItem & getKine();
    QStandardItem & getPsycho();
    QStandardItem & getInfirmiere();
    QStandardItem & getInformaticien();
    QStandardItem & getRadiologue();
};

#endif // TREEVIEW_H
