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

private slots:
    void on_pushButton_clicked();

private:
    Ui::PatientWindow *ui;
};

#endif // AJOUTERPATIENT_H
