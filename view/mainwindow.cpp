#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":hospital.png"));

    //Table View
    modelTable = new QStandardItemModel();
    QStandardItem *header0 = new QStandardItem("ID");
    QStandardItem *header1 = new QStandardItem("Nom");
    QStandardItem *header2 = new QStandardItem("Prénom");
    QStandardItem *header3 = new QStandardItem("Date");
    modelTable->setHorizontalHeaderItem(0,header0);
    modelTable->setHorizontalHeaderItem(1,header1);
    modelTable->setHorizontalHeaderItem(2,header2);
    modelTable->setHorizontalHeaderItem(3,header3);

    // Attach the model to the view
    ui->tableView->setModel(modelTable);

    // Generate data
    for(int row = 0; row < 4; row++)
    {
         for(int col = 0; col < 2; col++)
         {
              QModelIndex index = modelTable->index(row,col,QModelIndex());
               // 0 for all data
               modelTable->setData(index,0);
          }
     }

    //Tree View
    modelTree = new QStandardItemModel();
    QStandardItem *title = new QStandardItem("Types");
    QStandardItem *type0 = new QStandardItem("Médecin A");
    type0->setFlags(type0->flags() & ~Qt::ItemIsEditable);
    QStandardItem *type1 = new QStandardItem("Médecin B");
    type1->setFlags(type1->flags() & ~Qt::ItemIsEditable);
    QStandardItem *type2 = new QStandardItem("Radiologue");
    type2->setFlags(type2->flags() & ~Qt::ItemIsEditable);
    QStandardItem *type3 = new QStandardItem("Infirmière");
    type3->setFlags(type3->flags() & ~Qt::ItemIsEditable);
    QStandardItem *type4 = new QStandardItem("Kinésithérapeute");
    type4->setFlags(type4->flags() & ~Qt::ItemIsEditable);
    QStandardItem *type5 = new QStandardItem("Psychologue");
    type5->setFlags(type5->flags() & ~Qt::ItemIsEditable);
    QStandardItem *type6 = new QStandardItem("Informaticien");
    type6->setFlags(type6->flags() & ~Qt::ItemIsEditable);
    modelTree->setHorizontalHeaderItem(0,title);
    modelTree->appendRow(type0);
    modelTree->appendRow(type1);
    modelTree->appendRow(type2);
    modelTree->appendRow(type3);
    modelTree->appendRow(type4);
    modelTree->appendRow(type5);
    modelTree->appendRow(type6);
    ui->treeView->setModel(modelTree);

    controller.getCentre().setPatients(Utils::loadPatients());
    controller.getCentre().setPersonnels(Utils::loadPersonnels());
    controller.getCentre().setInformaticiens(Utils::loadInformaticien());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete modelTree;
    delete modelTable;
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
}

void MainWindow::personnelCreated()
{
    ui->statusBar->showMessage("Personnel créé", 3000);
}

void MainWindow::informaticienCreated()
{
    ui->statusBar->showMessage("Informaticien créé", 3000);
}

