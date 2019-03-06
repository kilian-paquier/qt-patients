#ifndef PATIENTWINDOW_H
#define PATIENTWINDOW_H

#include <QDialog>
#include <string>
#include "../controler/controler.h"

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
    ~PatientWindow();
    bool verification();
    void setControler(Controler & c);

private slots:
    void on_btnAnnuler_clicked();

<<<<<<< HEAD
    void on_btnAjouterListe_clicked();
=======
    void on_btnAjouter_clicked();
>>>>>>> 726d1df40ec224d76672f18dda3be7c9a0e57917

private:
    Ui::PatientWindow *ui;
};

#endif // AJOUTERPATIENT_H
