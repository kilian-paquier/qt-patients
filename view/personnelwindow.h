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
    void on_pushButton_2_clicked();

private:
    Ui::PersonnelWindow *ui;
};

#endif // PERSONNELWINDOW_H
