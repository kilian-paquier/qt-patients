#ifndef INFORMATICIEN_H
#define INFORMATICIEN_H

#include "personnel.h"

class Informaticien : public Personnel
{
private:
    string password;
    string login;
public:
    Informaticien();
    ~Informaticien();

    string & getPassword();
    string & getLogin();
    void setPassword(string password);
    void setLogin(string login);
};

#endif // INFORMATICIEN_H
