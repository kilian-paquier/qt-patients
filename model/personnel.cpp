#include "personnel.h"

Personnel::Personnel()
{

}

Personnel::~Personnel()
{

}


string &Personnel::getNom()
{
    return nom;
}

int &Personnel::getIdentifiant()
{
    return identifiant;
}

string &Personnel::getPrenom()
{
    return prenom;
}

string &Personnel::getType()
{
    return type;
}

void Personnel::setNom(string & nom)
{
    this->nom = nom;
}

void Personnel::setIdentifiant(int &identifiant)
{
    this->identifiant = identifiant;
}

void Personnel::setPrenom(string & prenom)
{
    this->prenom = prenom;
}

void Personnel::setType(string & type)
{
    this->type = type;
}

