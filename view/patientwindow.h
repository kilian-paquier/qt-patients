#ifndef PATIENTWINDOW_H
#define PATIENTWINDOW_H

#include <QDialog>

namespace Ui {
class PatientWindow;
}

class PatientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PatientWindow(QWidget *parent = nullptr);
    ~PatientWindow();
    bool verification();


private slots:


    void on_btnAnnuler_clicked();

    void on_btnAjouterListe_clicked();

private:
    Ui::PatientWindow *ui;
};

#endif // AJOUTERPATIENT_H
