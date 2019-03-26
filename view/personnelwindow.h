#ifndef PERSONNELWINDOW_H
#define PERSONNELWINDOW_H

#include <QDialog>
#include "../controler/controler.h"
#include <QMessageBox>

namespace Ui {
class PersonnelWindow;
}

class PersonnelWindow : public QDialog
{
    Q_OBJECT

private:
    Controler c;
    bool modifiable;
    Personnel personnel;
    Informaticien informaticien;
public:
    explicit PersonnelWindow(QWidget *parent = nullptr);
    ~PersonnelWindow();
    void setControler(Controler &c);
    void setModifiable(bool boolean);
    void setPersonnel(Personnel & personnel);
    Personnel & getPersonnel();
    void setInformaticien(Informaticien & informaticien);
    Informaticien & getInformaticien();
    bool isModifiable();
    void setMedecinA();

signals:
    void personnelAccepted();
    void informaticienAccepted();
    void personnelUpdated();
    void informaticienUpdated();

private slots:

    void on_btnAnnuler_clicked();

    void on_btnAjouter_clicked();

    bool verifier();

    void on_comboBoxType_currentIndexChanged(const QString &arg1);

private:
    Ui::PersonnelWindow *ui;
};

#endif // PERSONNELWINDOW_H
