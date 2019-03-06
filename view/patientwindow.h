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

    void on_btnAjouter_clicked();

private:
    Ui::PatientWindow *ui;
};

#endif // AJOUTERPATIENT_H
