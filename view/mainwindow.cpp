#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":hospital.png"));

    //Table View
    model = new QSqlTableModel;
    model->setTable("TPatient");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Nom");
    model->setHeaderData(2,Qt::Horizontal,"Prénom");

    // Attach the model to the view
    ui->tableView->setModel(model);

    controller.getCentre().setPatients(Utils::loadPatients());
    controller.getCentre().setPersonnels(Utils::loadPersonnels());
    controller.getCentre().setInformaticiens(Utils::loadInformaticien());

    //Tree View
    controller.loadTreeView(tree);
    ui->treeView->setModel(&tree.getModel());
    ui->dateEdit->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete &controller.getCentre().getPatients();
    delete &controller.getCentre().getPersonnels();
    delete &controller.getCentre().getInformaticiens();
}

Controler &MainWindow::getController()
{
    return controller;
}

void MainWindow::setController(Controler &controller)
{
    this->controller = controller;
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionPatient_triggered()
{
    PatientWindow patient(this);
    patient.setControler(controller);

    QObject::connect(&patient, SIGNAL(accepted()), this, SLOT(patientCreated()));
    patient.exec();
}

void MainWindow::on_actionPersonnel_de_soins_triggered()
{
    PersonnelWindow personnel(this);
    personnel.setControler(controller);

    QObject::connect(&personnel, SIGNAL(personnelAccepted()), this, SLOT(personnelCreated()));
    QObject::connect(&personnel, SIGNAL(informaticienAccepted()), this, SLOT(informaticienCreated()));
    personnel.exec();
}

void MainWindow::on_actionA_propos_triggered()
{
    AProposWindow aPropos(this);
    aPropos.exec();
}

void MainWindow::connectionSucceeded()
{
    ui->statusBar->showMessage("Connection réussie", 3000);
}

void MainWindow::patientCreated()
{
    ui->statusBar->showMessage("Patient créé", 3000);
    model->setTable("TPatient");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Nom");
    model->setHeaderData(2,Qt::Horizontal,"Prénom");
}

void MainWindow::personnelCreated()
{
    ui->statusBar->showMessage("Personnel créé", 3000);
}

void MainWindow::informaticienCreated()
{
    ui->statusBar->showMessage("Informaticien créé", 3000);
}

void MainWindow::fileWritten()
{
     ui->statusBar->showMessage("Ecriture dans le fichier réalisée", 3000);
}


void MainWindow::on_btnRechercher_clicked()
{
    std::string id = ui->lineEditID->text().toStdString();
    std::string nom = ui->lineEditNom->text().toStdString();
    std::string prenom = ui->lineEditPrenom->text().toStdString();
    std::string date = ui->dateEdit->text().toStdString();
    bool activer = ui->radioButtonActiver->isChecked();
    if(activer == true)
    {
        QSqlQuery query = Utils::searchInBd(nom,prenom,id,date);

    }

}
