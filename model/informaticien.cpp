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

string &Informaticien::getLogin()
{
    return login;
}

void Informaticien::setPassword(string password)
{
    this->password = password;
}

void Informaticien::setLogin(string login)
{
    this->login = login;
}


