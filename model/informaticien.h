#ifndef INFORMATICIEN_H
#define INFORMATICIEN_H

#include "personnel.h"

class Informaticien : public Personnel
{
private:
    int idInformaticien;
    string password;
    string login;
public:
    Informaticien();
    ~Informaticien();

    string & getPassword();
    int & getIdInformaticien();
    string & getLogin();
    void setPassword(string & password);
    void setLogin(string & login);
    void setIdInformaticien(int & id);
};

#endif // INFORMATICIEN_H
