#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "typemedecin.h"

class Personnel
{
private:
    string nom;
    string prenom;
    TypeMedecin::personnel type;

public:
    Personnel();
    ~Personnel();

    string & getNom();
    string & getPrenom();
    TypeMedecin::personnel & getType();
    void setNom(string nom);
    void setPrenom(string prenom);
    void setType(TypeMedecin::personnel type);
};

#endif // PERSONNEL_H
