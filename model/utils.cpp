#include "utils.h"

Utils::Utils()
{

}

Utils::~Utils()
{

}

bool Utils::writePatientInBDD(Patient &patient)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");

    db.open();

    QSqlQuery query(db);

    bool success = query.exec("SELECT MAX(Id) FROM TPatient");
    int id = 0;
    if (success) {
        while (query.next()) {
            id = query.value(0).toInt();
        }
    }
    else {
        qDebug() << query.lastError().text();
        qDebug() << "Select dans la table TPatient impossible ! \n";
        return false;
    }
    id += 1;
    patient.setIdentifiant(id);

    QString queryString("INSERT INTO TPatient (Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite) values(?,?,?,?,?,?,?,?,?,?,?)");
    query.prepare(queryString);
    query.bindValue(0, patient.getIdentifiant());
    query.bindValue(1, QVariant(QString::fromStdString(patient.getNom())));
    query.bindValue(2, QVariant(QString::fromStdString(patient.getPrenom())));
    query.bindValue(3, QVariant(QString::fromStdString(patient.getAdresse())));
    query.bindValue(4, QVariant(QString::fromStdString(patient.getVille())));
    query.bindValue(5, patient.getCodePostal());
    query.bindValue(6, QVariant(QString::fromStdString(patient.getCommentaires())));
    query.bindValue(7, QVariant(QString::fromStdString(patient.getNumeroTelephone())));
    query.bindValue(8, patient.getDate());
    query.bindValue(9, patient.getDureeConsultation());
    query.bindValue(10, patient.getPriorite());

    success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Insertion de données dans TPatient impossible !\n";
        return false;
    }

    success = query.exec("SELECT MAX(Id) FROM Tconsult");
    if (success) {
        while (query.next()) {
            id = query.value(0).toInt();
        }
    }
    else {
        qDebug() << query.lastError().text();
        qDebug() << "Select dans la table TPatient impossible ! \n";
        return false;
    }

    for (unsigned int i = 0; i < patient.getIdentifiantsRessources().size(); i++) {
        id += 1;
        query.prepare("INSERT INTO TConsult (Id, IdPatient, IdRessource) values(?,?,?)");
        query.bindValue(0, id);
        query.bindValue(1, patient.getIdentifiant());
        query.bindValue(2, patient.getIdentifiantsRessources()[i]);
        success = query.exec();
        if (!success) {
            qDebug() << query.lastError().text();
            qDebug() << "Insertion de données dans TConsult impossible !\n";
            return false;
        }
    }

    db.close();
    return true;
}

bool Utils::writePersonnelInBDD(Personnel &personnel)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");

    db.open();

    QSqlQuery typeQuery(db);
    typeQuery.prepare("SELECT Id FROM TType WHERE Label = ?");
    typeQuery.bindValue(0, QVariant(QString::fromStdString(personnel.getType())));
    bool success = typeQuery.exec();
    if (!success) {
        qDebug() << typeQuery.lastError().text();
        qDebug() << "Select dans TType impossible !\n";
        return false;
    }
    int idType = 1;
    while (typeQuery.next()) {
        idType = typeQuery.value(0).toInt();
    }

    QSqlQuery query(db);

    success = query.exec("SELECT MAX(Id) FROM TRessource");
    int id = 0;
    if (success) {
        while (query.next())
            id = query.value(0).toInt();
    }
    else {
        qDebug() << query.lastError().text();
        qDebug() << "Select dans la table TRessource impossible ! \n";
        return false;
    }
    id += 1;
    personnel.setIdentifiant(id);

    QString queryString("INSERT INTO TRessource (Id, Nom, Prenom, IdType) values(?,?,?,?)");

    query.prepare(queryString);
    query.bindValue(0, personnel.getIdentifiant());
    query.bindValue(1, QVariant(QString::fromStdString(personnel.getNom())));
    query.bindValue(2, QVariant(QString::fromStdString(personnel.getPrenom())));
    query.bindValue(3, idType);

    success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Insertion de données dans TRessource impossible !\n";
        return false;
    }

    db.close();

    return true;
}

bool Utils::writeInformaticienInBDD(Informaticien &informaticien)
{
    bool success = writePersonnelInBDD(informaticien);
    if (success) {
        QSqlDatabase db = QSqlDatabase::database("QSQLITE");

        db.open();

        QSqlQuery query(db);

        success = query.exec("SELECT MAX(Id) FROM TCompte");
        int id = 0;
        if (success) {
            while (query.next())
                id = query.value(0).toInt();
        }
        else {
            qDebug() << query.lastError().text();
            qDebug() << "Select dans la table TCompte impossible ! \n";
            return false;
        }
        id += 1;
        informaticien.setIdInformaticien(id);

        QString queryString("INSERT INTO TCompte (Id, IdRessource, Login, MdP) values(?,?,?)");
        query.prepare(queryString);
        query.bindValue(0, informaticien.getIdInformaticien());
        query.bindValue(0, informaticien.getIdentifiant());
        query.bindValue(1, QVariant(QString::fromStdString(informaticien.getLogin())));
        query.bindValue(2, QVariant(QString::fromStdString(informaticien.getPassword())));
        bool success = query.exec();
        if (!success) {
            qDebug() << query.lastError().text();
            qDebug() << "Insertion de données dans TCompte impossible !\n";
            return false;
        }

        db.close();


        return true;
    }
    else {
        return false;
    }
}

bool Utils::updatePatientInBDD(Patient &patient)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");

    db.open();

    QSqlQuery query(db);
    QString queryString("UPDATE TPatient set Nom = ?, Prenom = ?, Adresse = ?, Ville = ?, CP = ?, Commentaire = ?, Tel = ?, DateConsultation = ?, DureeConsultation = ?, Priorite = ? where Id = ?");
    query.prepare(queryString);
    query.bindValue(0, QVariant(QString::fromStdString(patient.getNom())));
    query.bindValue(1, QVariant(QString::fromStdString(patient.getPrenom())));
    query.bindValue(2, QVariant(QString::fromStdString(patient.getAdresse())));
    query.bindValue(3, QVariant(QString::fromStdString(patient.getVille())));
    query.bindValue(4, patient.getCodePostal());
    query.bindValue(5, QVariant(QString::fromStdString(patient.getCommentaires())));
    query.bindValue(6, QVariant(QString::fromStdString(patient.getNumeroTelephone())));
    query.bindValue(9, patient.getDate());
    query.bindValue(8, patient.getDureeConsultation());
    query.bindValue(9, patient.getPriorite());
    query.bindValue(10, patient.getIdentifiant());

    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Insertion de données dans TPatient impossible !\n";
        return false;
    }

    for (unsigned int i = 0; i < patient.getIdentifiantsRessources().size(); i++) {
        query.prepare("DELETE FROM TConsulte where IdPatient = ?");
        query.bindValue(0, patient.getIdentifiant());
        success = query.exec();
        if (success) {
            query.prepare("INSERT INTO TConsult (IdPatient, IdRessource) values(?,?)");
            query.bindValue(0, patient.getIdentifiant());
            query.bindValue(1, patient.getIdentifiantsRessources()[i]);
            success = query.exec();
            if (!success) {
                qDebug() << query.lastError().text();
                qDebug() << "Insertion de données dans TConsult impossible !\n";
                return false;
            }
        }
        else {
            qDebug() << query.lastError().text();
            qDebug() << "Suppression de données dans TConsult impossible !\n";
            return false;
        }
    }

    db.close();
    return true;
}

bool Utils::updatePersonnelInBDD(Personnel &personnel)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");

    db.open();

    QSqlQuery typeQuery(db);
    typeQuery.prepare("SELECT Id FROM TType WHERE Label = ?");
    typeQuery.bindValue(0, QVariant(QString::fromStdString(personnel.getType())));
    bool success = typeQuery.exec();
    if (!success) {
        qDebug() << typeQuery.lastError().text();
        qDebug() << "Select dans TType impossible !\n";
        return false;
    }
    int idType = 1;
    while (typeQuery.next()) {
        idType = typeQuery.value(0).toInt();
    }

    QSqlQuery query(db);
    QString queryString("UPDATE TRessource set Nom = ?, Prenom = ?, IdType = ? where Id = ?");
    query.prepare(queryString);
    query.bindValue(0, QVariant(QString::fromStdString(personnel.getNom())));
    query.bindValue(1, QVariant(QString::fromStdString(personnel.getPrenom())));
    query.bindValue(2, idType);
    query.bindValue(3, personnel.getIdentifiant());
    success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Insertion de données dans TRessource impossible !\n";
        return false;
    }

    db.close();

    return true;
}

bool Utils::updateInformaticienInBDD(Informaticien &informaticien)
{
    bool success = updatePersonnelInBDD(informaticien);
    if (success) {
        QSqlDatabase db = QSqlDatabase::database("QSQLITE");

        db.open();

        QSqlQuery query(db);
        QString queryString("UPDATE TCompte set Login = ?, MdP = ? where Id = ?");
        query.prepare(queryString);
        query.bindValue(0, QVariant(QString::fromStdString(informaticien.getLogin())));
        query.bindValue(1, QVariant(QString::fromStdString(informaticien.getPassword())));
        query.bindValue(2, informaticien.getIdInformaticien());
        bool success = query.exec();
        if (!success) {
            qDebug() << query.lastError().text();
            qDebug() << "Insertion de données dans TCompte impossible !\n";
            return false;
        }

        db.close();

        return true;
    }
    else {
        return false;
    }
}

bool Utils::deletePatientFromBDD(Patient &patient)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    db.open();

    QSqlQuery query(db);

    QString queryString("DELETE FROM TConsult where IdPatient = ?");
    query.prepare(queryString);
    query.bindValue(0, patient.getIdentifiant());

    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Suppression de données dans TConsult impossible !\n";
        return false;
    }

    query.prepare("DELETE FROM TPatient where Id = ?");
    query.bindValue(0, patient.getIdentifiant());

    success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Suppression de données dans TPatient impossible !\n";
        return false;
    }

    db.close();
    return true;
}

bool Utils::deletePersonnelFromBDD(Personnel &personnel)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");

    db.open();

    QSqlQuery query(db);
    QString queryString("DELETE FROM TConsult where IdRessource = ?");
    query.prepare(queryString);
    query.bindValue(0, personnel.getIdentifiant());
    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Suppression de données dans TConsult impossible !\n";
        return false;
    }

    query.prepare("DELETE FROM TRessource where Id = ?");
    query.bindValue(0, personnel.getIdentifiant());
    success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Suppression de données dans TRessource impossible !\n";
        return false;
    }

    db.close();

    return true;
}

bool Utils::deleteInformaticienFromBDD(Informaticien &informaticien)
{
    bool success = deletePersonnelFromBDD(informaticien);
    if (success) {
        QSqlDatabase db = QSqlDatabase::database("QSQLITE");
        db.open();

        QSqlQuery query(db);
        QString queryString("DELETE FROM TCompte where Id = ?");
        query.prepare(queryString);
        query.bindValue(0, informaticien.getIdInformaticien());
        bool success = query.exec();
        if (!success) {
            qDebug() << query.lastError().text();
            qDebug() << "Suppression de données dans TCompte impossible !\n";
            return false;
        }

        db.close();

        return true;
    }
    else {
        return false;
    }
}

bool Utils::connectInformaticien(string &login, string &password)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    db.open();

    QSqlQuery query(db);
    QString queryString("SELECT * FROM TCompte where Login = ? and MdP = ?");
    query.prepare(queryString);
    query.bindValue(0, QVariant(QString::fromStdString(login)));
    query.bindValue(1, QVariant(QString::fromStdString(password)));
    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Select dans TCompte impossible !\n";
        return false;
    }
    else {
        success = false;
        while (query.next()) {
            success = true;
        }
    }

    db.close();

    return success;
}

vector<Personnel> & Utils::loadPersonnels()
{
    vector<Personnel> * personnels = new vector<Personnel>;
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");

    db.open();

    QSqlQuery query(db);
    QString queryString("SELECT * FROM TRessource where IdType != (SELECT Id FROM TType where Label = 'Informaticien')");
    query.prepare(queryString);
    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Select dans TRessource impossible !\n";
        return *personnels;
    }
    else {
        while (query.next()) {
            Personnel personnel;
            int id = query.value(0).toInt();
            int idType = query.value(3).toInt();
            string nom = query.value(1).toString().toStdString();
            string prenom = query.value(2).toString().toStdString();
            QSqlQuery queryType(db);
            queryType.prepare("SELECT Label FROM TType where Id = ?");
            queryType.bindValue(0, idType);
            queryType.exec();
            string type;
            while (queryType.next()) {
                type = queryType.value(0).toString().toStdString();
            }
            personnel.setNom(nom);
            personnel.setIdentifiant(id);
            personnel.setPrenom(prenom);
            personnel.setType(type);
            personnels->push_back(personnel);
        }
    }

    db.close();

    return *personnels;
}

vector<Patient> & Utils::loadPatients()
{
    vector<Patient> * patients = new vector<Patient>;
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");

    db.open();

    QSqlQuery query(db);
    QString queryString("SELECT * FROM TPatient");
    query.prepare(queryString);
    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Select dans TPatient impossible !\n";
        return *patients;
    }
    else {
        while (query.next()) {
            Patient patient;
            int id = query.value(0).toInt();
            QSqlQuery consultations(db);
            consultations.prepare("SELECT IdRessource FROM TConsult where IdPatient = ?");
            consultations.bindValue(0, id);
            consultations.exec();
            vector<int> ressources;
            while (consultations.next()) {
                ressources.push_back(consultations.value(0).toInt());
            }
            string nom = query.value(1).toString().toStdString();
            string prenom = query.value(2).toString().toStdString();
            string adresse = query.value(3).toString().toStdString();
            string ville = query.value(4).toString().toStdString();
            unsigned int codePostal = query.value(5).toUInt();
            string commentaire = query.value(6).toString().toStdString();
            string tel = query.value(7).toString().toStdString();
            QDate dateConsult = query.value(8).toDate();
            int duree = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            patient.setNom(nom);
            patient.setIdentifiant(id);
            patient.setPrenom(prenom);
            patient.setVille(ville);
            patient.setAdresse(adresse);
            patient.setCodePostal(codePostal);
            patient.setCommentaires(commentaire);
            patient.setNumeroTelephone(tel);
            patient.setDate(dateConsult);
            patient.setDureeConsultation(duree);
            patient.setPriorite(priorite);
            patient.setIdentifiantsRessources(ressources);
            patients->push_back(patient);
        }
    }

    db.close();

    return *patients;
}

vector<Informaticien> & Utils::loadInformaticien()
{
    vector<Informaticien> * personnels = new vector<Informaticien>;
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    db.open();

    QSqlQuery query(db);
    QString queryString("SELECT * FROM TRessource INNER JOIN TCompte ON TRessource.Id = TCompte.IdRessource where IdType = (SELECT Id FROM TType where Label = 'Informaticien')");
    query.prepare(queryString);
    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Select dans TRessource - TCompte impossible !\n";
        return *personnels;
    }
    else {
        while (query.next()) {
            Informaticien personnel;
            int id = query.value(0).toInt();
            string nom = query.value(1).toString().toStdString();
            string prenom = query.value(2).toString().toStdString();
            string type = "Informaticien";
            int idInfo = query.value(4).toInt();
            string login = query.value(5).toString().toStdString();
            string password = query.value(6).toString().toStdString();
            personnel.setNom(nom);
            personnel.setIdentifiant(id);
            personnel.setPrenom(prenom);
            personnel.setType(type);
            personnel.setLogin(login);
            personnel.setPassword(password);
            personnel.setIdInformaticien(idInfo);
            personnels->push_back(personnel);
        }
    }

    db.close();

    return *personnels;
}

void Utils::openDB()
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    db.open();
}

void Utils::closeDB()
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    db.close();
}

void Utils::initBD()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("password");
    db.setDatabaseName("base_tmp.sqli");
}
