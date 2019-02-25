#include "informaticien.h"

Informaticien::Informaticien()
{

}

Informaticien::~Informaticien()
{

}

string &Informaticien::getPassword()
{
    return password;
}

int &Informaticien::getIdInformaticien()
{
    return idInformaticien;
}

string &Informaticien::getLogin()
{
    return login;
}

void Informaticien::setPassword(string &password)
{
    this->password = password;
}

void Informaticien::setLogin(string &login)
{
    this->login = login;
}

void Informaticien::setIdInformaticien(int &id)
{
    this->idInformaticien = id;
}


