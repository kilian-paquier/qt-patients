#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <string>


LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

bool LoginWindow::authentifier()
{
    bool resultat = false;
    std::string login = ui->Login->text().toStdString();
    std::string password = ui->Password->text().toStdString();

    if(login == "admin" && password == "admin123")
    {
        resultat = true;
    }

    return resultat;
}

void LoginWindow::on_Connexion_clicked()
{
    if(authentifier())
    {
        this->hide();
        parentWidget()->show();
    }
    else {
        QMessageBox::warning(this,"Attention","Login ou Password incorrect");
    }
}

void LoginWindow::on_Annuler_clicked()
{
    close();
}
