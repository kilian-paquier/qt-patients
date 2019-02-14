#ifndef CONTROLER_H
#define CONTROLER_H

#include "model/utils.h"
#include <cctype>
#include "view/mainwindow.h"
#include "model/Patient.h"
#include "model/personnel.h"
#include "model/informaticien.h"

class Controler
{
private:
    MainWindow window;
public:
    Controler();
    ~Controler();

    MainWindow & getWindow();

    void createPatient(string & nom, string & prenom, string & adresse, string & ville, QDate & date, int & codePostal, int & dureeConsultation, int & priorite, vector<int> & identifiants, int & numeroTelephone, string & commentaires);
    void createPersonnel(int & identifiant, string & nom, string & prenom, TypeMedecin::personnel & type);
    void createInformaticien(int & identifiant, string & nom, string & prenom, TypeMedecin::personnel & type, string & login, string & password);
};

#endif // CONTROLER_H
