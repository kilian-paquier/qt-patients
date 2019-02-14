#ifndef TYPEMEDECIN_H
#define TYPEMEDECIN_H

#include <string>
using namespace std;

namespace TypeMedecin {
    typedef enum {
        Medecin_A,
        Medecin_B,
        Radiologue,
        Infirmiere,
        Kine,
        Psychologue,
        Informaticien
    } personnel;
string & toString(TypeMedecin::personnel);
TypeMedecin::personnel & parseFromString(string & typeMedecin);
}

#endif // TYPEMEDECIN_H
