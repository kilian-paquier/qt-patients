#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QStandardItemModel>
#include <vector>
using namespace std;

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

    vector<QStandardItem *> personnels;
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
    QStandardItem & getTitle();
    QStandardItem * searchPersonnel(int identifiant);
    void removePersonnel(QStandardItem * personnel);

    vector<QStandardItem *> & getPersonnels();
};

#endif // TREEVIEW_H
