#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include <QDate>

class Patient
{
private:
    int identifiant;
	string nom;
	string prenom;
	string adresse;
	string ville;
	string commentairesMaladie;
    QDate date;

    unsigned int codePostal;
    string numeroTelephone;
	int dureeConsultation;
	int priorite;

	vector<int> identifiantsRessources;
public:
	Patient();
	~Patient();

	string & getNom();
	string & getPrenom();
	string & getAdresse();
	string & getVille();
	string & getCommentaires();
    QDate & getDate();
    int & getIdentifiant();
	
    unsigned int & getCodePostal();
    string & getNumeroTelephone();
    int & getDureeConsultation();
    int & getPriorite();

    vector<int> & getIdentifiantsRessources();
    void setIdentifiantsRessources(vector<int> &identifiants);
    void addIdentifiantRessources(int &identifiant);

    void setNom(string & nom);
    void setPrenom(string & prenom);
    void setAdresse(string & adresse);
    void setVille(string & ville);
    void setCommentaires(string & commentaires);
    void setDate(QDate & date);
    void setIdentifiant(int & identifiant);

    void setCodePostal(unsigned int & codePostal);
    void setNumeroTelephone(string & numeroTelephone);
    void setDureeConsultation(int & dureeConsultation);
    void setPriorite(int & priorite);

    bool operator<(const Patient & patient2) const;
	void transform();
	string toString();
};

