#include "controler.h"

Controler::Controler()
{

}

Controler::~Controler()
{

}

MainWindow &Controler::getWindow()
{
    return window;
}

void Controler::createPatient(string &nom, string &prenom, string &adresse, string &ville, QDate &date, int &codePostal, int &dureeConsultation, int &priorite, vector<int> &identifiants, int &numeroTelephone, string &commentaires)
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
}

void Controler::createPersonnel(int &identifiant, string &nom, string &prenom, TypeMedecin::personnel &type)
{
    Personnel personnel;
    personnel.setIdentifiant(identifiant);
    personnel.setNom(nom);
    personnel.setPrenom(prenom);
    personnel.setType(type);
}

void Controler::createInformaticien(int &identifiant, string &nom, string &prenom, TypeMedecin::personnel &type, string &login, string &password)
{
    Informaticien personnel;
    personnel.setIdentifiant(identifiant);
    personnel.setNom(nom);
    personnel.setPrenom(prenom);
    personnel.setType(type);
    personnel.setLogin(login);
    personnel.setPassword(password);
}


