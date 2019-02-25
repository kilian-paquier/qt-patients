#include "aproposwindow.h"
#include "ui_aproposwindow.h"

AProposWindow::AProposWindow (QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AProposWindow)
{
    ui->setupUi(this);
}

AProposWindow::~AProposWindow()
{
    delete ui;
}
