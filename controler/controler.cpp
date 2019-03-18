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

void Controler::deletePersonnel(Personnel &personnel)
{
    centre.getPersonnels().erase(centre.getPersonnels().begin() + centre.searchPersonnel(personnel.getIdentifiant()));

    Utils::deletePersonnelFromBDD(personnel);
}

void Controler::deleteInformaticien(Informaticien &informaticien)
{
    centre.getInformaticiens().erase(centre.getInformaticiens().begin() + centre.searchInformaticien(informaticien.getIdentifiant()));

    Utils::deleteInformaticienFromBDD(informaticien);
}

void Controler::loadTreeView(TreeView & tree)
{
    for (unsigned int i = 0; i < centre.getPersonnels().size(); i++) {
        Personnel & personnel = centre.getPersonnels()[i];
        string personnelString = to_string(personnel.getIdentifiant()) + " " + personnel.getNom() + " " + personnel.getPrenom();
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        if (personnel.getType().compare(tree.getMedecinA().text().toStdString()) == 0) {
            tree.getMedecinA().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getMedecinB().text().toStdString()) == 0) {
            tree.getMedecinB().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getKine().text().toStdString()) == 0) {
            tree.getKine().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getPsycho().text().toStdString()) == 0) {
            tree.getPsycho().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getRadiologue().text().toStdString()) == 0) {
            tree.getRadiologue().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
        else if (personnel.getType().compare(tree.getInfirmiere().text().toStdString()) == 0) {
            tree.getInfirmiere().appendRow(item);
            tree.getPersonnels().push_back(item);
        }
    }
    for (unsigned int i = 0; i < centre.getInformaticiens().size(); i++) {
        Informaticien & personnel = centre.getInformaticiens()[i];
        string personnelString = to_string(personnel.getIdentifiant()) + " " + personnel.getNom() + " " + personnel.getPrenom();
        QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        tree.getInformaticien().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
}

void Controler::insertInTreeView(TreeView &tree, Personnel &personnel)
{
    string personnelString = to_string(personnel.getIdentifiant()) + " " + personnel.getNom() + " " + personnel.getPrenom();
    QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    if (personnel.getType().compare(tree.getMedecinA().text().toStdString()) == 0) {
        tree.getMedecinA().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getMedecinB().text().toStdString()) == 0) {
        tree.getMedecinB().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getKine().text().toStdString()) == 0) {
        tree.getKine().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getPsycho().text().toStdString()) == 0) {
        tree.getPsycho().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getRadiologue().text().toStdString()) == 0) {
        tree.getRadiologue().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else if (personnel.getType().compare(tree.getInfirmiere().text().toStdString()) == 0) {
        tree.getInfirmiere().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
    else {
        tree.getInformaticien().appendRow(item);
        tree.getPersonnels().push_back(item);
    }
}

void Controler::modifyTreeView(TreeView &tree, Personnel &personnel)
{
    string personnelString = to_string(personnel.getIdentifiant()) + " " + personnel.getNom() + " " + personnel.getPrenom();
    QStandardItem * item = tree.searchPersonnel(personnel.getIdentifiant());
    if (item->text().compare("NOT EXISTS") == 0)
        delete item;
    else {
        item->setText(QString::fromStdString(personnelString));
        if (item->parent()->text().compare(QString::fromStdString(personnel.getType())) != 0) {
            QStandardItem * parent = item->parent();
            int row = item->row();
            tree.removePersonnel(item);
            parent->removeRow(row);
            QStandardItem * item = new QStandardItem(QString::fromStdString(personnelString));
            tree.getPersonnels().push_back(item);
            if (personnel.getType().compare(tree.getMedecinA().text().toStdString()) == 0)
                tree.getMedecinA().appendRow(item);
            else if (personnel.getType().compare(tree.getMedecinB().text().toStdString()) == 0)
                tree.getMedecinB().appendRow(item);
            else if (personnel.getType().compare(tree.getKine().text().toStdString()) == 0)
                tree.getKine().appendRow(item);
            else if (personnel.getType().compare(tree.getPsycho().text().toStdString()) == 0)
                tree.getPsycho().appendRow(item);
            else if (personnel.getType().compare(tree.getRadiologue().text().toStdString()) == 0)
                tree.getRadiologue().appendRow(item);
            else if (personnel.getType().compare(tree.getInfirmiere().text().toStdString()) == 0)
                tree.getInfirmiere().appendRow(item);
            else
                tree.getInformaticien().appendRow(item);
        }
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

    QString jour;
    if (date.day() < 10)
        jour = "0" + QString::number(date.day());
    else
        jour = QString::number(date.day());

    QString mois;
    if (date.month() < 10)
        mois = "0" + QString::number(date.month());
    else
        mois = QString::number(date.month());
    QFileDialog dialog;
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.selectFile("Planification_" + QString::number(date.day()) + QString::number(date.month()) + QString::number(date.year()));
    dialog.setWindowIcon(QIcon(":hospital.png"));

    QString fichier = dialog.getSaveFileName(nullptr, "Enregistrer la planification", "Planification_"
                                             + jour + mois + QString::number(date.year())
                                             , "Fichier texte (*.txt)");
    if (!fichier.isNull()) {
        QFile fileInput(fichier);
        if (fileInput.open(QFile::WriteOnly | QIODevice::Text)) {
            QTextStream flux(&fileInput);
            flux.setCodec("UFT-8");
            flux << "Planification du : " + jour + "/" + mois + "/" + QString::number(date.year()) << endl;
            for (unsigned int i = 0; i < patientstries.size(); i++)
                flux << QString::number(patientstries[i].getIdentifiant()) + " " + QString::fromStdString(patientstries[i].getNom()) + " "
                     + QString::fromStdString(patientstries[i].getPrenom()) << endl;
            fileInput.close();
        }
    }
}

Centre &Controler::getCentre()
{
    return centre;
}


