#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include "model/Patient.h"
#include "model/personnel.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QtDebug>
#include <QSqlError>
#include "model/informaticien.h"
using namespace std;

class Utils
{
private:
    Utils();
    ~Utils();
public:
    static bool writePatientInBDD(Patient & patient);
    static bool writePersonnelInBDD(Personnel & personnel);
    static bool writeInformaticienInBDD(Informaticien & informaticien);
    static bool updatePatientInBDD(Patient & patient);
    static bool updatePersonnelInBDD(Personnel & personnel);
    static bool updateInformaticienInBDD(Informaticien & informaticien);
    static bool deletePatientFromBDD(Patient & patient);
    static bool deletePersonnelFromBDD(Personnel & personnel);
    static bool deleteInformaticienFromBDD(Informaticien & informaticien);
    static bool connectInformaticien(string & login, string & password);
    static vector<Personnel> & loadPersonnels();
    static vector<Patient> & loadPatients();
    static vector<Informaticien> & loadInformaticien();
    static void openDB();
    static void closeDB();
    static void initBD();
    static Patient getPatient(int &id);
};


#endif // UTILS_H
