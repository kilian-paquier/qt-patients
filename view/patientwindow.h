#ifndef PATIENTWINDOW_H
#define PATIENTWINDOW_H

#include <QDialog>
#include <string>
#include "../controler/controler.h"
#include <QMessageBox>

namespace Ui {
class PatientWindow;
}

class PatientWindow : public QDialog
{
    Q_OBJECT

private:
    Controler c;
public:
    explicit PatientWindow(QWidget *parent = nullptr);
    explicit PatientWindow(QWidget *parent,int &id);
    ~PatientWindow();
    bool verification();
    void setControler(Controler & c);
    void setId(int &id);
    int getId();

private slots:
    void on_btnAnnuler_clicked();

    void on_btnAjouterListe_clicked();

    void on_btnAjouter_clicked();

private:
    Ui::PatientWindow *ui;
    int id = 0;
};

#endif // AJOUTERPATIENT_H
