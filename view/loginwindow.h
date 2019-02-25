#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <string>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:

    void on_Connexion_clicked();

    void on_Annuler_clicked();

    bool authentifier();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
