#include "utils.h"

Utils::Utils()
{

}

Utils::~Utils()
{

}

bool Utils::writePatientInBDD(Patient &patient)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("password");

    db.setDatabaseName("base_tmp.sqli");
    db.open();

    QSqlQuery query(db);
    QString queryString("INSERT INTO TPatient (Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite) values(?,?,?,?,?,?,?,?,?,?)");
    query.prepare(queryString);
    query.bindValue(0, QVariant(QString::fromStdString(patient.getNom())));
    query.bindValue(1, QVariant(QString::fromStdString(patient.getPrenom())));
    query.bindValue(2, QVariant(QString::fromStdString(patient.getAdresse())));
    query.bindValue(3, QVariant(QString::fromStdString(patient.getVille())));
    query.bindValue(4, patient.getCodePostal());
    query.bindValue(5, QVariant(QString::fromStdString(patient.getCommentaires())));
    query.bindValue(6, patient.getNumeroTelephone());
    query.bindValue(9, QVariant(patient.getDate()));
    query.bindValue(8, patient.getDureeConsultation());
    query.bindValue(9, patient.getPriorite());

    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Insertion de données dans TPatient impossible !\n";
        return false;
    }

    success = query.exec("SELECT max(IdPatient) FROM TPatient");
    int id = 0;
    if (success) {
        while (query.next())
            id = query.value(0).Int;
    }
    else {
        qDebug() << query.lastError().text();
        qDebug() << "Select dans la table TPatient impossible ! \n";
        return false;
    }
    patient.setIdentifiant(id);

    for (unsigned int i = 0; i < patient.getIdentifiantsRessources().size(); i++) {
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

    db.close();
    db.removeDatabase("QSQLITE");
    return true;
}

bool Utils::writePersonnelInBDD(Personnel &personnel)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("password");

    db.setDatabaseName("base_tmp.sqli");
    db.open();

    QSqlQuery query(db);
    QString queryString("INSERT INTO TRessource (Nom, Prenom, IdType) values(?,?,?)");
    query.prepare(queryString);
    query.bindValue(0, QVariant(QString::fromStdString(personnel.getNom())));
    query.bindValue(1, QVariant(QString::fromStdString(personnel.getPrenom())));
    query.bindValue(2, personnel.getType());
    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Insertion de données dans TRessource impossible !\n";
        return false;
    }

    success = query.exec("SELECT max(IdRessource) FROM TRessource");
    int id = 0;
    if (success) {
        while (query.next())
            id = query.value(0).Int;
    }
    else {
        qDebug() << query.lastError().text();
        qDebug() << "Select dans la table TRessource impossible ! \n";
        return false;
    }
    personnel.setIdentifiant(id);

    db.close();
    db.removeDatabase("QSQLITE");

    return true;
}

bool Utils::writeInformaticienInBDD(Informaticien &informaticien)
{

}

bool Utils::updatePatientInBDD(Patient &patient)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("password");

    db.setDatabaseName("base_tmp.sqli");
    db.open();

    QSqlQuery query(db);
    QString queryString("UPDATE TPatient SET ");
    query.prepare(queryString);

    return true;
}

bool Utils::updatePersonnelInBDD(Personnel &personnel)
{

    return true;
}

bool Utils::updateInformaticienInBDD(Informaticien &informaticien)
{

}

bool Utils::deletePatientFromBDD(Patient &patient)
{

    return true;
}

bool Utils::deletePersonnelFromBDD(Personnel &personnel)
{

    return true;
}

bool Utils::deleteInformaticienFromBDD(Informaticien &informaticien)
{

}
