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

void Controler::loadTreeView(TreeView & tree)
{
    for (unsigned int i = 0; i < centre.getPersonnels().size(); i++) {
        Personnel & personnel = centre.getPersonnels()[i];
        string personnelString = personnel.getNom() + " " + personnel.getPrenom();
        if (personnel.getType().compare(tree.getMedecinA().text().toStdString()) == 0) {
            QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
            tree.getMedecinA().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getMedecinB().text().toStdString()) == 0) {
            QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
            tree.getMedecinB().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getKine().text().toStdString()) == 0) {
            QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
            tree.getKine().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getPsycho().text().toStdString()) == 0) {
            QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
            tree.getPsycho().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getRadiologue().text().toStdString()) == 0) {
            QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
            tree.getRadiologue().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getInfirmiere().text().toStdString()) == 0) {
            QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
            tree.getInfirmiere().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
    }
    for (unsigned int i = 0; i < centre.getInformaticiens().size(); i++) {
        Informaticien & personnel = centre.getInformaticiens()[i];
        string personnelString = personnel.getNom() + " " + personnel.getPrenom();
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        tree.getInformaticien().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
}

void Controler::updateTreeView(TreeView &tree, Personnel &personnel)
{
    string personnelString = personnel.getNom() + " " + personnel.getPrenom();
    if (personnel.getType().compare(tree.getMedecinA().text().toStdString()) == 0) {
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        tree.getMedecinA().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getMedecinB().text().toStdString()) == 0) {
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        tree.getMedecinB().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getKine().text().toStdString()) == 0) {
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        tree.getKine().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getPsycho().text().toStdString()) == 0) {
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        tree.getPsycho().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getRadiologue().text().toStdString()) == 0) {
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        tree.getRadiologue().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getInfirmiere().text().toStdString()) == 0) {
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        tree.getInfirmiere().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else {
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        tree.getInformaticien().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
}

void Controler::triPrioritaire(QDate date)
{
    vector<Patient> patientstries;
    for (unsigned int i = 0; i < centre.getPatients().size(); i++) {
        if (centre.getPatients()[i].getDate() == date) {
            patientstries.push_back(centre.getPatients()[i]);
            centre.getPatients()[i].transform();
        }
    }
    sort(centre.getPatients().begin(), centre.getPatients().end());

    QFileDialog dialog;
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setWindowIcon(QIcon(":hospital.png"));
    dialog.exec();

    string fichier = dialog.getSaveFileName().toStdString();
    ofstream fileInput(fichier, ios::out | ios::trunc);
    if (fileInput) {
        fileInput << "Consultations pour le jour : " << date.toString().toStdString() << endl;
        for (unsigned int i = 0; i < patientstries.size(); i++)
            fileInput << patientstries[i].getIdentifiant() << " " << patientstries[i].getNom() << " " << patientstries[i].getPrenom() << " Durée : " << patientstries[i].getDureeConsultation() << " minutes" << endl;
        fileInput.close();
    }
}

Centre &Controler::getCentre()
{
    return centre;
}


