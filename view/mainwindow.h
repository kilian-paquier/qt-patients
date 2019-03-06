#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QTreeView>
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

private:
    Ui::MainWindow *ui;
    QStandardItemModel *modelTable;
    QStandardItemModel *modelTree;
};

#endif // MAINWINDOW_H
