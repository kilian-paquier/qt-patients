#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "model/Patient.h"
#include "model/personnel.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QtDebug>
#include <QSqlError>
using namespace std;

class Utils
{
private:
    Utils();
    ~Utils();

    static bool writePatientInBDD(Patient & patient);
    static bool writePersonnelInBDD(Personnel & personnel);
};

#endif // UTILS_H
