#include "centre.h"

Centre::Centre()
{

}

Centre::~Centre()
{

}

vector<Patient> &Centre::getPatients()
{
    return patients;
}

vector<Personnel> &Centre::getPersonnels()
{
    return personnels;
}

vector<Informaticien> &Centre::getInformaticiens()
{
    return informaticiens;
}

void Centre::setPatients(vector<Patient> &patients)
{
    this->patients = patients;
}

void Centre::setPersonnels(vector<Personnel> &personnels)
{
    this->personnels = personnels;
}

void Centre::setInformaticiens(vector<Informaticien> &informaticiens)
{
    this->informaticiens = informaticiens;
}

void Centre::addPatient(Patient &patient)
{
    patients.push_back(patient);
}

void Centre::addPersonnel(Personnel &personnel)
{
    personnels.push_back(personnel);
}

void Centre::deletePatient(int & idPatient)
{
    patients.erase(patients.begin() + searchPatient(idPatient));
}

void Centre::deletePersonnel(int & idPersonnel)
{
    personnels.erase(personnels.begin() + searchPersonnel(idPersonnel));
}

void Centre::addInformaticien(Informaticien &informaticien)
{
    informaticiens.push_back(informaticien);
}

void Centre::deleteInformaticien(int & idInformaticien)
{
    informaticiens.erase(informaticiens.begin() + searchInformaticien(idInformaticien));
}

unsigned int Centre::searchPatient(int & idPatient)
{
    for (unsigned int i = 0; i < patients.size(); i++) {
        if (patients[i].getIdentifiant() == idPatient)
            return i;
    }
    return PATIENT_NOT_IN_LIST;
}

unsigned int Centre::searchPersonnel(int &idPersonnel)
{
    for (unsigned int i = 0; i < personnels.size(); i++) {
        if (personnels[i].getIdentifiant() == idPersonnel)
            return i;
    }
    return PERSONNEL_NOT_IN_LIST;
}

unsigned int Centre::searchInformaticien(int &idInformaticien)
{
    for (unsigned int i = 0; i < informaticiens.size(); i++) {
        if (informaticiens[i].getIdentifiant() == idInformaticien)
            return i;
    }
    return INFORMATICIEN_NOT_IN_LIST;
}
