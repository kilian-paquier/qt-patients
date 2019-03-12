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

vector<QStandardItem *> &TreeView::getPersonnels()
{
    return personnels;
}
