#include "personnelwindow.h"
#include "ui_personnelwindow.h"

PersonnelWindow::PersonnelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonnelWindow)
{
    ui->setupUi(this);

    ui->comboBoxType->addItem("Médecin A");
    ui->comboBoxType->addItem("Médecin B");
    ui->comboBoxType->addItem("Radiologue");
    ui->comboBoxType->addItem("Infirmière");
    ui->comboBoxType->addItem("Kinésithérapeute");
    ui->comboBoxType->addItem("Psychologue");
    ui->comboBoxType->addItem("Informaticien");
}

PersonnelWindow::~PersonnelWindow()
{
    delete ui;
}

void PersonnelWindow::setControler(Controler &c)
{
    this->c = c;
}

void PersonnelWindow::on_btnAnnuler_clicked()
{
    close();
}

void PersonnelWindow::on_btnAjouter_clicked()
{
    bool success = verifier();
    if (success) {
        std::string nom = ui->lineEditNom->text().toStdString();
        std::string prenom = ui->lineEditPrenom->text().toStdString();
        std::string type = ui->comboBoxType->currentText().toStdString();

        if (ui->comboBoxType->currentText().toStdString().compare("Informaticien") != 0) {
            c.createPersonnel(nom, prenom, type);
            personnelAccepted();
        }
        else {
            std::string login = ui->lineEditLogin->text().toStdString();
            std::string mdp = ui->lineEditMDP->text().toStdString();
            c.createInformaticien(nom, prenom, type, login, mdp);
            informaticienAccepted();
        }
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

    if(nom.compare("") != 0 && prenom.compare("") != 0)
    {
        if (type.compare("Informaticien") == 0)
        {
            if(login.compare("") != 0 && mdp.compare("") != 0)
                resultat = true;
            else {
                QMessageBox::warning(this,"Attention","Un champ obligatoire n'a pas été rempli");
            }
        }
        else {
            resultat = true;
        }
    }
    else {
        QMessageBox::warning(this,"Attention","Un champ obligatoire n'a pas été rempli");
    }
    return resultat;
}

void PersonnelWindow::on_comboBoxType_currentIndexChanged(const QString &arg1)
{
    if (arg1.compare("Informaticien") == 0)
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
