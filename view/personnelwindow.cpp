#include "personnelwindow.h"
#include "ui_personnelwindow.h"
#include "model/typemedecin.h"
#include "controler/controler.h"

PersonnelWindow::PersonnelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonnelWindow)
{
    ui->setupUi(this);

    ui->comboBoxType->addItem("Medecin A",TypeMedecin::Medecin_A);
    ui->comboBoxType->addItem("Medecin B",TypeMedecin::Medecin_B);
    ui->comboBoxType->addItem("Radiologue",TypeMedecin::Radiologue);
    ui->comboBoxType->addItem("Infirmiere",TypeMedecin::Infirmiere);
    ui->comboBoxType->addItem("Kine",TypeMedecin::Kine);
    ui->comboBoxType->addItem("Psychologue",TypeMedecin::Psychologue);
    ui->comboBoxType->addItem("Informaticien",TypeMedecin::Informaticien);
}

PersonnelWindow::~PersonnelWindow()
{
    delete ui;
}



void PersonnelWindow::on_btnAnnuler_clicked()
{
    close();
}

void PersonnelWindow::on_btnAjouter_clicked()
{
    if (verifier() == true)
    {

    }
    else
    {

    }
}

bool PersonnelWindow::verifier()
{
    bool resultat = false;
    std::string nom = ui->lineEditNom->text().toStdString();
    std::string prenom = ui->lineEditPrenom->text().toStdString();
    std::string type = ui->comboBoxType->currentText().toStdString();
    std::string login = ui->lineEditLogin->text().toStdString();
    std::string mdp = ui->lineEditMDP->text().toStdString();

    if(nom != "" && prenom != "")
    {
        if (type == "informaticien")
        {
            if(login != "" && mdp != "")
                resultat = true;
        }
        else {
            resultat = true;
        }
    }
    return resultat;
}

void PersonnelWindow::on_comboBoxType_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Informaticien")
    {
        ui->lineEditLogin->setEnabled(true);
        ui->lineEditLogin->setReadOnly(false);
        ui->lineEditMDP->setEnabled(true);
        ui->lineEditMDP->setReadOnly(false);
        ui->mdp->setEnabled(true);
        ui->login->setEnabled(true);
    }
    else
    {
        ui->lineEditLogin->setEnabled(false);
        ui->lineEditLogin->setReadOnly(true);
        ui->lineEditLogin->setText("");
        ui->lineEditMDP->setEnabled(false);
        ui->lineEditMDP->setReadOnly(true);
        ui->lineEditMDP->setText("");
        ui->mdp->setEnabled(false);
        ui->login->setEnabled(false);
    }
}
