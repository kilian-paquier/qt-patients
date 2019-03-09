#ifndef CENTRE_H
#define CENTRE_H

#include <iostream>
#include <string>
#include <vector>
#include "model/Patient.h"
#include "model/personnel.h"
#include "model/informaticien.h"
#include "model/utils.h"
using namespace std;

#define PATIENT_NOT_IN_LIST 6000
#define PERSONNEL_NOT_IN_LIST 7000
#define INFORMATICIEN_NOT_IN_LIST 8000

class Centre
{
private:
    vector<Patient> * patients;
    vector<Personnel> * personnels;
    vector<Informaticien> * informaticiens;
public:
    Centre();
    ~Centre();

    vector<Patient> & getPatients();
    vector<Personnel> & getPersonnels();
    vector<Informaticien> & getInformaticiens();
    void setPatients(vector<Patient> & patients);
    void setPersonnels(vector<Personnel> & personnels);
    void setInformaticiens(vector<Informaticien> & informaticiens);

    void addPatient(Patient & patient);
    void addPersonnel(Personnel & personnel);
    void deletePatient(int & idPatient);
    void deletePersonnel(int & idPersonnel);
    void addInformaticien(Informaticien & informaticien);
    void deleteInformaticien(int & idInformaticien);
    unsigned int searchPatient(int & idPatient);
    unsigned int searchPersonnel(int & idPersonnel);
    unsigned int searchInformaticien(int& idInformaticien);
};

#endif // CENTRE_H
