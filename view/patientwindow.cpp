#include "patientwindow.h"
#include "ui_patientwindow.h"

PatientWindow::PatientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientWindow)
{
    ui->setupUi(this);
}

PatientWindow::~PatientWindow()
{
    delete ui;
}

bool PatientWindow::verification()
{
    bool resultat = false;
    std::string nom = ui->lineEditNom->text().toStdString();
    std::string prenom = ui->lineEditPrenom->text().toStdString();
    std::string adresse = ui->lineEditAdresse->text().toStdString();
    std::string ville = ui->lineEditVille->text().toStdString();
    unsigned int codePostal = static_cast<unsigned int>(ui->lineEditCodePostal->text().toInt());
    int dureeConsult = ui->spinDureeConsultation->value();
    int priorite = ui->spinPriorite->value();
    QDate date = ui->dateConsultation->
    std::string telephone = ui->lineEditTelephone->text().toStdString();
    std::string commentaire = ui->textEditCommentaire->toPlainText().toStdString();

    if(nom != "" && prenom != "")
    {

    }
    return resultat;
}

void PatientWindow::on_btnAnnuler_clicked()
{
    close();
}
