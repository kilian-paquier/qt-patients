#include "patientwindow.h"
#include "ui_patientwindow.h"

PatientWindow::PatientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Données de la personne"); // Modification point 1 CC
    ui->dateConsultation->setDate(QDate::currentDate());
}

PatientWindow::PatientWindow(QWidget *parent,int &id) :
    QDialog(parent),
    ui(new Ui::PatientWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Modification de patients");
    Patient patient = Utils::getPatient(id);
    ui->lineEditNom->setText(QString::fromStdString(patient.getNom()));
    ui->lineEditPrenom->setText(QString::fromStdString(patient.getPrenom()));
    ui->lineEditAdresse->setText(QString::fromStdString(patient.getAdresse()));
    ui->lineEditVille->setText(QString::fromStdString(patient.getVille()));
    ui->lineEditTelephone->setText(QString::fromStdString(patient.getNumeroTelephone()));
    ui->lineEditCodePostal->setText(QString::number(patient.getCodePostal()));
    ui->spinPriorite->setValue(patient.getPriorite());
    ui->spinDureeConsultation->setValue(patient.getDureeConsultation());
    ui->dateConsultation->setDate(patient.getDate());
    ui->textEditCommentaire->setText(QString::fromStdString(patient.getCommentaires()));
    ui->label_19->setText("Modifier un Patient");
    ui->btnAjouter->setText("Modifier");
    setId(id);

    for (vector<int>::iterator monIte = patient.getIdentifiantsRessources().begin(); monIte != patient.getIdentifiantsRessources().end(); monIte++)
        {
            ui->listPersonnelSoins->addItem(QString::number(*monIte));
        }
}

PatientWindow::~PatientWindow()
{
    delete ui;
}

int PatientWindow::getId()
{
    return id;
}

void PatientWindow::setId(int &id)
{
    this->id = id;
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
    int id = getId();

    // Modification 2 - CC
    QDate todayPlusThree = QDate::currentDate();
    todayPlusThree = todayPlusThree.addDays(3);

    if(nom.compare("") != 0 && prenom.compare("") != 0 && adresse.compare("") != 0 && ville.compare("") != 0)
    {
        if (todayPlusThree > date && id == 0)
            QMessageBox::warning(this,"Attention","La date saisie est avant la date d'aujourd'hui (moins trois jours)");
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
    int count = ui->listPersonnelSoins->count();
    bool doublon = false;

    for (int i = 0; i < count; i++)
    {
        if (!ui->listPersonnelSoins->item(i)->text().compare(idPersonnel))
            doublon = true;
    }

    if (!doublon)
    {
        ui->listPersonnelSoins->addItem(idPersonnel);
    }

    ui->comboBoxPersonnelSoins->removeItem(ui->comboBoxPersonnelSoins->currentIndex());
}

void PatientWindow::on_btnAjouter_clicked()
{
    bool success = verification();
    QString btn = ui->btnAjouter->text();

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

        for (int i = 0; i < ui->listPersonnelSoins->count(); i++)
        {
            int idResource = ui->listPersonnelSoins->item(i)->text().toInt();
            ressources.push_back(idResource);
        }

        if (!btn.compare("Ajouter"))
        {
            c.createPatient(nom, prenom, adresse, ville, date, codePostal, dureeConsult, priorite, ressources, telephone, commentaire);
            accepted();

            ui->lineEditNom->setText("");
            ui->lineEditPrenom->setText("");
            ui->lineEditAdresse->setText("");
            ui->lineEditVille->setText("");
            ui->lineEditCodePostal->setText("");
            ui->spinDureeConsultation->setValue(60);
            ui->spinPriorite->setValue(1);
            ui->dateConsultation->setDate(QDate::currentDate());
            ui->lineEditTelephone->setText("");
            ui->textEditCommentaire->setText("");
            ui->listPersonnelSoins->clear();
        }
        else {
            int id = getId();

            c.updatePatient(id,nom, prenom, adresse, ville, date, codePostal, dureeConsult, priorite, ressources, telephone, commentaire);
            accepted();
            close();
        }

        for (unsigned int i = 0; i < c.getCentre().getPersonnels().size(); i++)
            ui->comboBoxPersonnelSoins->addItem(QString::fromStdString(to_string(c.getCentre().getPersonnels()[i].getIdentifiant())));

    }
}
