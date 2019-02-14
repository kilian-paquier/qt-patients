#ifndef CENTRE_H
#define CENTRE_H

#include <iostream>
#include <string>
#include <vector>
#include "model/Patient.h"
#include "model/personnel.h"
using namespace std;

class Centre
{
private:
    vector<Patient> patients;
    vector<Personnel> personnels;
public:
    Centre();
    ~Centre();

    vector<Patient> & getPatients();
    vector<Personnel> & getPersonnels();
    void setPatients(vector<Patient> & patients);
    void setPersonnels(vector<Personnel> & personnels);

    void addPatient(Patient & patient);
    void addPersonnel(Personnel & personnel);
    void deletePatient(Patient & patient);
    void deletePersonnel(Personnel & personnel);
};

#endif // CENTRE_H
