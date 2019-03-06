#ifndef CONTROLER_H
#define CONTROLER_H

#include "model/utils.h"
#include <cctype>
#include "model/Patient.h"
#include "model/personnel.h"
#include "model/informaticien.h"
#include "model/centre.h"

#define PATIENT_CREATED 6001
#define PATIENT_UPDATE 6002
#define PATIENT_DELETED 6003
#define PERSONNEL_CREATED 7001
#define PERSONNEL_UPDATE 7002
#define PERSONNEL_DELETED 7003
#define INFORMATICIEN_CREATED 8001
#define INFORMATICIEN_UPDATED 8002
#define INFORMATICIEN_DELETED 8003
#define ACTION_FAILED 9000

class Controler
{
private:
    Centre centre;
public:
    Controler();
    ~Controler();

    void createPatient(string & nom, string & prenom, string & adresse, string & ville, QDate & date, int & codePostal, int & dureeConsultation, int & priorite, vector<int> & identifiants, int & numeroTelephone, string & commentaires);
    void createPersonnel(string & nom, string & prenom, string & type);
    void createInformaticien(string & nom, string & prenom, string & type, string & login, string & password);
    void updatePatient(int & idPatient, string & nom, string & prenom, string & adresse, string & ville, QDate & date, int & codePostal, int & dureeConsultation, int & priorite, vector<int> & identifiants, int & numeroTelephone, string & commentaires);
    void updatePersonnel(int &idPersonnel, string & nom, string & prenom, string & type);
    void updateInformaticien(int & idInformaticien, string & nom, string & prenom, string & type, string & login, string & password);
    void deletePatient();
    void deletePersonnel();
    void deleteInformaticien();
};

#endif // CONTROLER_H
