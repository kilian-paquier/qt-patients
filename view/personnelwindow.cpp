#include "personnelwindow.h"
#include "ui_personnelwindow.h"

PersonnelWindow::PersonnelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonnelWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Ajout de personnels");

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

void PersonnelWindow::setModifiable(bool boolean)
{
    this->modifiable = boolean;
    ui->btnAjouter->setText("Modifier");
}

void PersonnelWindow::setPersonnel(Personnel &personnel)
{
    this->personnel = personnel;
    ui->lineEditPrenom->setText(QString::fromStdString(personnel.getPrenom()));
    ui->lineEditNom->setText(QString::fromStdString(personnel.getNom()));
    ui->comboBoxType->setCurrentIndex(ui->comboBoxType->findText(QString::fromStdString(personnel.getType())));
    ui->comboBoxType->removeItem(6);
}

Personnel &PersonnelWindow::getPersonnel()
{
    return personnel;
}

void PersonnelWindow::setInformaticien(Informaticien &informaticien)
{
    this->informaticien = informaticien;
    ui->lineEditPrenom->setText(QString::fromStdString(informaticien.getPrenom()));
    ui->lineEditNom->setText(QString::fromStdString(informaticien.getNom()));
    ui->comboBoxType->clear();
    ui->comboBoxType->addItem("Informaticien");
    ui->comboBoxType->setCurrentIndex(0);
    ui->lineEditLogin->setText(QString::fromStdString(informaticien.getLogin()));
    ui->lineEditMDP->setText(QString::fromStdString(informaticien.getPassword()));
    this->setWindowTitle("Modification de personnels");
    ui->label_19->setText("Modifer un Personnel de soins");
}

Informaticien &PersonnelWindow::getInformaticien()
{
    return informaticien;
}

bool PersonnelWindow::isModifiable()
{
    return modifiable;
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
        std::string login = ui->lineEditLogin->text().toStdString();
        std::string mdp = ui->lineEditMDP->text().toStdString();

        if (ui->btnAjouter->text().compare("Ajouter") == 0) {
            if (ui->comboBoxType->currentText().toStdString().compare("Informaticien") != 0) {
                c.createPersonnel(nom, prenom, type);
                personnelAccepted();
            }
            else {
                c.createInformaticien(nom, prenom, type, login, mdp);
                informaticienAccepted();
            }
        }
        else {
            if (ui->comboBoxType->currentText().toStdString().compare("Informaticien") != 0) {
                c.updatePersonnel(personnel.getIdentifiant(), nom, prenom, type);
                personnelUpdated();
                this->hide();
            }
            else {
                c.updateInformaticien(informaticien.getIdentifiant(), nom, prenom, type, login, mdp);
                informaticienUpdated();
                this->hide();
            }
        }

        ui->lineEditNom->setText("");
        ui->lineEditPrenom->setText("");
        ui->lineEditMDP->setText("");
        ui->lineEditLogin->setText("");
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
