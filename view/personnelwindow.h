#ifndef PERSONNELWINDOW_H
#define PERSONNELWINDOW_H

#include <QDialog>

namespace Ui {
class PersonnelWindow;
}

class PersonnelWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PersonnelWindow(QWidget *parent = nullptr);
    ~PersonnelWindow();

private slots:


    void on_btnAnnuler_clicked();

    void on_btnAjouter_clicked();

    bool verifier();

    void on_comboBoxType_currentIndexChanged(const QString &arg1);

private:
    Ui::PersonnelWindow *ui;
};

#endif // PERSONNELWINDOW_H
