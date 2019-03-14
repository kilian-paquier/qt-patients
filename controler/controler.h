#ifndef CONTROLER_H
#define CONTROLER_H

#include "model/utils.h"
#include <cctype>
#include <QFileDialog>
#include "model/Patient.h"
#include "model/personnel.h"
#include "model/informaticien.h"
#include "model/centre.h"
#include <QIcon>
#include <fstream>
#include <QStandardItemModel>
#include "model/treeview.h"

class Controler
{
private:
    Centre centre;
public:
    Controler();
    ~Controler();

    void createPatient(string & nom, string & prenom, string & adresse, string & ville, QDate & date, unsigned int & codePostal, int & dureeConsultation, int & priorite, vector<int> & identifiants, string & numeroTelephone, string & commentaires);
    void createPersonnel(string & nom, string & prenom, string & type);
    void createInformaticien(string & nom, string & prenom, string & type, string & login, string & password);
    void updatePatient(int & idPatient, string & nom, string & prenom, string & adresse, string & ville, QDate & date, unsigned int & codePostal, int & dureeConsultation, int & priorite, vector<int> & identifiants, string & numeroTelephone, string & commentaires);
    void updatePersonnel(int &idPersonnel, string & nom, string & prenom, string & type);
    void updateInformaticien(int & idInformaticien, string & nom, string & prenom, string & type, string & login, string & password);
    void deletePatient();
    void deletePersonnel();
    void deleteInformaticien();
    void loadTreeView(TreeView & tree);
    //void triPrioritaire(QDate date);

    Centre & getCentre();
};

#endif // CONTROLER_H
