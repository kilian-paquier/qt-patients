#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QTreeView>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include "patientwindow.h"
#include "personnelwindow.h"
#include "aproposwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Controler controller;
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

public slots:
    void connectionSucceeded();

    void patientCreated();

    void personnelCreated();

    void informaticienCreated();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QStandardItemModel *modelTree;
};

#endif // MAINWINDOW_H
