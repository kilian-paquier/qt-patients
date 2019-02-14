#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "typemedecin.h"
#include <string>
using namespace std;

class Personnel
{
private:
    int identifiant;
    string nom;
    string prenom;
    TypeMedecin::personnel type;

public:
    Personnel();
    ~Personnel();

    string & getNom();
    int & getIdentifiant();
    string & getPrenom();
    TypeMedecin::personnel & getType();
    void setNom(string & nom);
    void setIdentifiant(int & identifiant);
    void setPrenom(string & prenom);
    void setType(TypeMedecin::personnel & type);
};

#endif // PERSONNEL_H
