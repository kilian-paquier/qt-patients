#include "treeview.h"

TreeView::TreeView()
{
    model = new QStandardItemModel();
    title = new QStandardItem("Types de personnel");
    kine = new QStandardItem("Kinésithérapeute");
    informaticien = new QStandardItem("Informaticien");
    radiologue = new QStandardItem("Radiologue");
    medecinA = new QStandardItem("Médecin A");
    medecinB = new QStandardItem("Médecin B");
    infirmiere = new QStandardItem("Infirmière");
    psycho = new QStandardItem("Psychologue");

    title->setFlags(title->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);

    kine->setFlags(kine->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
    infirmiere->setFlags(infirmiere->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
    psycho->setFlags(psycho->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
    medecinB->setFlags(medecinB->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
    medecinA->setFlags(medecinA->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
    radiologue->setFlags(radiologue->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
    informaticien->setFlags(informaticien->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);

    model->appendRow(title);
    title->appendRow(kine);
    title->appendRow(medecinA);
    title->appendRow(medecinB);
    title->appendRow(radiologue);
    title->appendRow(infirmiere);
    title->appendRow(psycho);
    title->appendRow(informaticien);
}

TreeView::~TreeView()
{
    for (unsigned int i = 0; i < personnels.size(); i++)
        delete personnels[i];
    delete kine;
    delete informaticien;
    delete radiologue;
    delete medecinA;
    delete medecinB;
    delete psycho;
    delete infirmiere;
    delete title;
    delete model;
}

QStandardItemModel &TreeView::getModel()
{
    return *model;
}

QStandardItem &TreeView::getMedecinA()
{
    return *medecinA;
}

QStandardItem &TreeView::getMedecinB()
{
    return *medecinB;
}

QStandardItem &TreeView::getKine()
{
    return * kine;
}

QStandardItem &TreeView::getPsycho()
{
    return * psycho;
}

QStandardItem &TreeView::getInfirmiere()
{
    return * infirmiere;
}

QStandardItem &TreeView::getInformaticien()
{
    return * informaticien;
}

QStandardItem &TreeView::getRadiologue()
{
    return * radiologue;
}

QStandardItem &TreeView::getTitle()
{
    return * title;
}

QStandardItem *TreeView::searchPersonnel(int identifiant)
{
    for (unsigned int i = 0; i < personnels.size(); i++) {
        int id = personnels[i]->text().split(" ")[0].toInt();
        if (id == identifiant)
            return personnels[i];
    }
    return new QStandardItem("NOT EXISTS");
}

void TreeView::removePersonnel(QStandardItem * personnel)
{
    for (unsigned int i = 0; i < personnels.size(); i++) {
        if (personnels[i]->text().compare(personnel->text()) == 0) {
            personnels.erase(personnels.begin() + i);
            delete personnel;
            break;
        }
    }
}

vector<QStandardItem *> &TreeView::getPersonnels()
{
    return personnels;
}
