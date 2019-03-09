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
    int dureeConsult = ui->spinDureeConsultation->value();
    int priorite = ui->spinPriorite->value();
    QDate date = ui->dateConsultation->date();
    std::string telephone = ui->lineEditTelephone->text().toStdString();
    std::string commentaire = ui->textEditCommentaire->toPlainText().toStdString();

    // PARSING DES RESSOURCES

    if(nom.compare("") != 0 && prenom.compare("") != 0 && adresse.compare("") != 0 && ville.compare("") != 0)
    {
        if (QDate::currentDate() > date)
            QMessageBox::warning(this,"Attention","La date saisie est avant la date d'aujourd'hui");
        else if (dureeConsult <= 0)
            QMessageBox::warning(this,"Attention","Le patient possède une durée de consultation de 0 minutes");
        else if (priorite <= 0)
            QMessageBox::warning(this,"Attention","La priorité ne peut pas être de 0");
        else
            resultat = true;
    }
    else {
        QMessageBox::warning(this,"Attention","Un champ obligatoire n'a pas été rempli");
    }
    return resultat;
}

void PatientWindow::setControler(Controler &c)
{
    this->c = c;
    for (unsigned int i = 0; i < c.getCentre().getPersonnels().size(); i++)
        ui->comboBoxPersonnelSoins->addItem(QString::fromStdString(to_string(c.getCentre().getPersonnels()[i].getIdentifiant())));
}

void PatientWindow::on_btnAnnuler_clicked()
{
    close();
}


void PatientWindow::on_btnAjouterListe_clicked()
{
    QString idPersonnel = ui->comboBoxPersonnelSoins->currentText();
    ui->listPersonnelSoins->addItem(idPersonnel);
    ui->comboBoxPersonnelSoins->removeItem(ui->comboBoxPersonnelSoins->currentIndex());
}

void PatientWindow::on_btnAjouter_clicked()
{
    bool success = verification();
    if (success) {
        std::string nom = ui->lineEditNom->text().toStdString();
        std::string prenom = ui->lineEditPrenom->text().toStdString();
        std::string adresse = ui->lineEditAdresse->text().toStdString();
        std::string ville = ui->lineEditVille->text().toStdString();
        unsigned int codePostal = static_cast<unsigned int>(ui->lineEditCodePostal->text().toInt());
        int dureeConsult = ui->spinDureeConsultation->value();
        int priorite = ui->spinPriorite->value();
        QDate date = ui->dateConsultation->date();
        std::string telephone = ui->lineEditTelephone->text().toStdString();
        std::string commentaire = ui->textEditCommentaire->toPlainText().toStdString();
        vector<int> ressources;

        c.createPatient(nom, prenom, adresse, ville, date, codePostal, dureeConsult, priorite, ressources, telephone, commentaire);
        accepted();
    }
}
