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
    ui->treeView->expandAll();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEditPlanifier->setDate(QDate::currentDate());
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
    controller.insertInTreeView(tree, controller.getCentre().getPersonnels().back());
}

void MainWindow::informaticienCreated()
{
    ui->statusBar->showMessage("Informaticien créé", 3000);
    controller.insertInTreeView(tree, controller.getCentre().getInformaticiens().back());
}

void MainWindow::personnelUpdated()
{
    ui->statusBar->showMessage("Personnel mis à jour", 3000);
    QVariant item = ui->treeView->currentIndex().data();
    int idPersonnel = item.toString().split(" ")[0].toInt();
    Personnel perso = controller.getCentre().getPersonnels()[controller.getCentre().searchPersonnel(idPersonnel)];
    controller.modifyTreeView(tree, perso);
}

void MainWindow::informaticienUpdated()
{
    ui->statusBar->showMessage("Informaticien mis à jour", 3000);
    QVariant item = ui->treeView->currentIndex().data();
    int idPersonnel = item.toString().split(" ")[0].toInt();
    Informaticien informaticien = controller.getCentre().getInformaticiens()[controller.getCentre().searchInformaticien(idPersonnel)];
    controller.modifyTreeView(tree, informaticien);
}

void MainWindow::fileWritten()
{
     ui->statusBar->showMessage("Ecriture dans le fichier réalisée", 3000);
}


void MainWindow::on_btnRechercher_clicked()
{
    QString id = ui->lineEditID->text();
    QString nom = ui->lineEditNom->text();
    QString prenom = ui->lineEditPrenom->text();
    QDate date = ui->dateEdit->date();

    bool activer = ui->radioButtonActiver->isChecked();


    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    db.open();

    model->setFilter(QString("ID like '%1%%' AND NOM like '%2%%' AND PRENOM like '%3%%'").arg(id).arg(nom).arg(prenom));

    if(activer == true)
    {
        model->setFilter(QString("ID like '%1%%' AND NOM like '%2%%' AND PRENOM like '%3%%' AND DateConsultation like '%4%' ").arg(id).arg(nom).arg(prenom).arg(date.toString("yyyy-MM-dd")));
    }

    ui->tableView->setModel(model);
    db.close();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row = ui->tableView->currentIndex().row();
    QString information = ui->tableView->model()->data(ui->tableView->model()->index(row,2)).toString();
    QMessageBox::information(
        this,
        tr("Application Name"),
        tr("An information message.") );

}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    QVariant item = index.data();
    if (item.toString().compare(tree.getKine().text()) != 0 && item.toString().compare(tree.getPsycho().text()) != 0 &&
            item.toString().compare(tree.getMedecinA().text()) != 0 && item.toString().compare(tree.getMedecinB().text()) != 0 &&
            item.toString().compare(tree.getInfirmiere().text()) != 0 && item.toString().compare(tree.getInformaticien().text()) != 0 &&
            item.toString().compare(tree.getRadiologue().text()) != 0 && item.toString().compare(tree.getTitle().text()) != 0) {

        PersonnelWindow personnel(this);
        personnel.setControler(controller);
        personnel.setModifiable(true);
        int idPersonnel = item.toString().split(" ")[0].toInt();

        if (index.parent().data().toString().compare(tree.getInformaticien().text()) == 0) {
            personnel.setInformaticien(controller.getCentre().getInformaticiens()[controller.getCentre().searchInformaticien(idPersonnel)]);
            Informaticien informaticien = personnel.getInformaticien();
            QObject::connect(&personnel, SIGNAL(informaticienUpdated()), this, SLOT(informaticienUpdated()));
            personnel.exec();

        }
        else {
            personnel.setPersonnel(controller.getCentre().getPersonnels()[controller.getCentre().searchPersonnel(idPersonnel)]);
            Personnel perso = personnel.getPersonnel();
            QObject::connect(&personnel, SIGNAL(personnelUpdated()), this, SLOT(personnelUpdated()));
            personnel.exec();

        }
    }
}

void MainWindow::on_btnSupprimerPersonnel_clicked()
{
    QModelIndex item = ui->treeView->currentIndex();
    int id = item.data().toString().split(" ")[0].toInt();
    if (item.parent().data().toString().compare("Informaticien") == 0) {
        if (item.parent().model()->rowCount() == 1)
            QMessageBox::warning(this, "Attention", "Vous ne pouvez pas supprimer le seul informaticien pouvant se connecter à l'application");
        else {
            Informaticien informaticien = controller.getCentre().getInformaticiens()[controller.getCentre().searchInformaticien(id)];
            controller.deleteInformaticien(informaticien);

            QStandardItem * treeItem = tree.searchPersonnel(id);
            if (treeItem->text().compare("NOT EXISTS") == 0)
                delete treeItem;
            QStandardItem * parent = treeItem->parent();
            int row = treeItem->row();
            tree.removePersonnel(treeItem);
            parent->removeRow(row);

            ui->statusBar->showMessage("Informaticien correctement supprimé");
        }
    }
    else {
        Personnel personnel = controller.getCentre().getPersonnels()[controller.getCentre().searchPersonnel(id)];
        controller.deletePersonnel(personnel);

        QStandardItem * treeItem = tree.searchPersonnel(id);
        if (treeItem->text().compare("NOT EXISTS") == 0)
            delete treeItem;
        QStandardItem * parent = treeItem->parent();
        int row = treeItem->row();
        tree.removePersonnel(treeItem);
        parent->removeRow(row);

        ui->statusBar->showMessage("Personnel correctement supprimé");
    }
}
