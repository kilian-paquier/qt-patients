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

    for (unsigned int i = 0; i < patient.getIdentifiantsRessources().size(); i++) {
        query.prepare("INSERT INTO TConsult (IdPatient, IdRessource) values(?,?)");
        query.bindValue(0, 0); // TODO TROUVER ID PATIENT
        query.bindValue(1, patient.getIdentifiantsRessources()[i]);
    }

    return true;
}

bool Utils::writePersonnelInBDD(Personnel &personnel)
{

}
