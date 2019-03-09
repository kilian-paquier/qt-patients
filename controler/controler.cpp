#include "controler.h"

Controler::Controler()
{

}

Controler::~Controler()
{

}

void Controler::createPatient(string &nom, string &prenom, string &adresse, string &ville, QDate &date, unsigned int &codePostal, int &dureeConsultation, int &priorite, vector<int> &identifiants, string &numeroTelephone, string &commentaires)
{
    Patient patient;
    // Formatage du nom, prénom
    nom[0] = char(toupper(int(nom[0])));
    prenom[0] = char(toupper(int(prenom[0])));
    patient.setNom(nom);
    patient.setPrenom(prenom);
    patient.setAdresse(adresse);
    patient.setVille(ville);
    patient.setDate(date);
    patient.setCodePostal(codePostal);
    patient.setDureeConsultation(dureeConsultation);
    patient.setPriorite(priorite);
    patient.setIdentifiantsRessources(identifiants);

    patient.setCommentaires(commentaires);
    patient.setNumeroTelephone(numeroTelephone);

    bool success = Utils::writePatientInBDD(patient);
    if (success)
        centre.addPatient(patient);
}

void Controler::createPersonnel(string &nom, string &prenom, string &type)
{
    Personnel personnel;
    nom[0] = char(toupper(int(nom[0])));
    prenom[0] = char(toupper(int(prenom[0])));
    personnel.setNom(nom);
    personnel.setPrenom(prenom);
    personnel.setType(type);
    bool success = Utils::writePersonnelInBDD(personnel);
    if (success)
        centre.addPersonnel(personnel);
}

void Controler::createInformaticien(string &nom, string &prenom, string &type, string &login, string &password)
{
    Informaticien personnel;
    nom[0] = char(toupper(int(nom[0])));
    prenom[0] = char(toupper(int(prenom[0])));
    personnel.setNom(nom);
    personnel.setPrenom(prenom);
    personnel.setType(type);
    personnel.setLogin(login);
    personnel.setPassword(password);
    bool success = Utils::writeInformaticienInBDD(personnel);
    if (success)
        centre.addInformaticien(personnel);
}

// ERREUR CREER FONCTION UTILS CPP
void Controler::updatePatient(int & idPatient, string &nom, string &prenom, string &adresse, string &ville, QDate &date, unsigned int &codePostal, int &dureeConsultation, int &priorite, vector<int> &identifiants, string &numeroTelephone, string &commentaires)
{
    Patient & patient = centre.getPatients()[centre.searchPatient(idPatient)];
    nom[0] = char(toupper(int(nom[0])));
    prenom[0] = char(toupper(int(prenom[0])));
    patient.setNom(nom);
    patient.setPrenom(prenom);
    patient.setAdresse(adresse);
    patient.setVille(ville);
    patient.setDate(date);
    patient.setCodePostal(codePostal);
    patient.setDureeConsultation(dureeConsultation);
    patient.setPriorite(priorite);
    patient.setIdentifiantsRessources(identifiants);

    patient.setCommentaires(commentaires);
    patient.setNumeroTelephone(numeroTelephone);

    Utils::updatePatientInBDD(patient);
}

void Controler::updatePersonnel(int &idPersonnel, string &nom, string &prenom, string &type)
{
    Personnel & personnel = centre.getPersonnels()[centre.searchPersonnel(idPersonnel)];
    nom[0] = char(toupper(int(nom[0])));
    prenom[0] = char(toupper(int(prenom[0])));
    personnel.setNom(nom);
    personnel.setPrenom(prenom);
    personnel.setType(type);

    Utils::updatePersonnelInBDD(personnel);
}

void Controler::updateInformaticien(int &idInformaticien, string &nom, string &prenom, string &type, string &login, string &password)
{
    Informaticien & informaticien = centre.getInformaticiens()[centre.searchInformaticien(idInformaticien)];
    nom[0] = char(toupper(int(nom[0])));
    prenom[0] = char(toupper(int(prenom[0])));
    informaticien.setNom(nom);
    informaticien.setPrenom(prenom);
    informaticien.setType(type);
    informaticien.setLogin(login);
    informaticien.setPassword(password);

    Utils::updateInformaticienInBDD(informaticien);
}

Centre &Controler::getCentre()
{
    return centre;
}


