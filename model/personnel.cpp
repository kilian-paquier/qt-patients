#include "personnel.h"

Personnel::Personnel()
{

}

string &Personnel::getNom()
{
    return nom;
}

string &Personnel::getPrenom()
{
    return prenom;
}

TypeMedecin::personnel &Personnel::getType()
{
    return type;
}

void Personnel::setNom(string nom)
{
    this->nom = nom;
}

void Personnel::setPrenom(string prenom)
{
    this->prenom = prenom;
}

void Personnel::setType(TypeMedecin::personnel type)
{
    this->type = type;
}
