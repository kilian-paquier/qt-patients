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

    success = query.exec("SELECT LAST_INSERT_ID() FROM TPatient");
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

    success = query.exec("SELECT LAST_INSERT_ID() FROM TRessource");
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
    bool success = writePersonnelInBDD(informaticien);
    if (success) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");

        db.setDatabaseName("base_tmp.sqli");
        db.open();

        QSqlQuery query(db);
        QString queryString("INSERT INTO TCompte (Login, MdP) values(?,?)");
        query.prepare(queryString);
        query.bindValue(0, QVariant(QString::fromStdString(informaticien.getLogin())));
        query.bindValue(1, QVariant(QString::fromStdString(informaticien.getPassword())));
        bool success = query.exec();
        if (!success) {
            qDebug() << query.lastError().text();
            qDebug() << "Insertion de données dans TCompte impossible !\n";
            return false;
        }

        success = query.exec("SELECT LAST_INSERT_ID() FROM TCompte");
        int id = 0;
        if (success) {
            while (query.next())
                id = query.value(0).Int;
        }
        else {
            qDebug() << query.lastError().text();
            qDebug() << "Select dans la table TCompte impossible ! \n";
            return false;
        }
        informaticien.setIdInformaticien(id);

        db.close();
        db.removeDatabase("QSQLITE");

        return true;
    }
    else {
        return false;
    }
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
    QString queryString("UPDATE TPatient set Nom = ?, Prenom = ?, Adresse = ?, Ville = ?, CP = ?, Commentaire = ?, Tel = ?, DateConsultation = ?, DureeConsultation = ?, Priorite = ? where Id = ?");
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
    db.removeDatabase("QSQLITE");
    return true;
}

bool Utils::updatePersonnelInBDD(Personnel &personnel)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("password");

    db.setDatabaseName("base_tmp.sqli");
    db.open();

    QSqlQuery query(db);
    QString queryString("UPDATE TRessource set Nom = ?, Prenom = ?, IdType = ? where Id = ?");
    query.prepare(queryString);
    query.bindValue(0, QVariant(QString::fromStdString(personnel.getNom())));
    query.bindValue(1, QVariant(QString::fromStdString(personnel.getPrenom())));
    query.bindValue(2, personnel.getType());
    query.bindValue(3, personnel.getIdentifiant());
    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError().text();
        qDebug() << "Insertion de données dans TRessource impossible !\n";
        return false;
    }

    db.close();
    db.removeDatabase("QSQLITE");

    return true;
}

bool Utils::updateInformaticienInBDD(Informaticien &informaticien)
{
    bool success = updatePersonnelInBDD(informaticien);
    if (success) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");

        db.setDatabaseName("base_tmp.sqli");
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
        db.removeDatabase("QSQLITE");

        return true;
    }
    else {
        return false;
    }
}

bool Utils::deletePatientFromBDD(Patient &patient)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("password");

    db.setDatabaseName("base_tmp.sqli");
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
    db.removeDatabase("QSQLITE");
    return true;
}

bool Utils::deletePersonnelFromBDD(Personnel &personnel)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("password");

    db.setDatabaseName("base_tmp.sqli");
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
    db.removeDatabase("QSQLITE");

    return true;
}

bool Utils::deleteInformaticienFromBDD(Informaticien &informaticien)
{
    bool success = deletePersonnelFromBDD(informaticien);
    if (success) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");

        db.setDatabaseName("base_tmp.sqli");
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
        db.removeDatabase("QSQLITE");

        return true;
    }
    else {
        return false;
    }
}
