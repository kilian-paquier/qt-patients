#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
using namespace std;

class Personnel
{
private:
    int identifiant;
    string nom;
    string prenom;
    string type;
    string surnom;

public:
    Personnel();
    ~Personnel();

    string & getNom();
    int & getIdentifiant();
    string & getPrenom();
    string & getType();
    void setNom(string & nom);
    void setIdentifiant(int & identifiant);
    void setPrenom(string & prenom);
    void setType(string & type);

    string & getSurnom();
    void setSurnom(string & surnom);
};

#endif // PERSONNEL_H
