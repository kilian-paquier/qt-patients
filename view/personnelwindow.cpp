#include "personnelwindow.h"
#include "ui_personnelwindow.h"

PersonnelWindow::PersonnelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonnelWindow)
{
    ui->setupUi(this);
}

PersonnelWindow::~PersonnelWindow()
{
    delete ui;
}
