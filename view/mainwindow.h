#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QTreeView>
#include <QObject>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include "patientwindow.h"
#include "personnelwindow.h"
#include "aproposwindow.h"
#include "model/treeview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Controler controller;
    TreeView tree;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Controler & getController();
    void setController(Controler & controller);

private slots:
    void on_actionQuitter_triggered();

    void on_actionPatient_triggered();

    void on_actionPersonnel_de_soins_triggered();

    void on_actionA_propos_triggered();

    void on_btnRechercher_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_btnSupprimerPersonnel_clicked();

    void on_btnPlanifier_clicked();

public slots:
    void connectionSucceeded();

    void patientCreated();

    void personnelCreated();

    void informaticienCreated();

    void personnelUpdated();

    void informaticienUpdated();

    void fileWritten();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
