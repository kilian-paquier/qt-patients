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
public:
    explicit PersonnelWindow(QWidget *parent = nullptr);
    ~PersonnelWindow();
    void setControler(Controler &c);

signals:
    void personnelAccepted();
    void informaticienAccepted();

private slots:

    void on_btnAnnuler_clicked();

    void on_btnAjouter_clicked();

    bool verifier();

    void on_comboBoxType_currentIndexChanged(const QString &arg1);

private:
    Ui::PersonnelWindow *ui;
};

#endif // PERSONNELWINDOW_H
