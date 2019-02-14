#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#include <QDate>

class Patient
{
private:
	string nom;
	string prenom;
	string adresse;
	string ville;
	string commentairesMaladie;
    QDate date;

	int codePostal;
	int numeroTelephone;
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
	
	int & getCodePostal();
	int & getNumeroTelephone();
	int & getDureeConsultation();
	int & getPriorite();

	vector<int> & getIdentifiantsRessources();
	void setIdentifiantsRessources(vector<int> identifiants);
	void addIdentifiantRessources(int identifiant);

    void setNom(string & nom);
    void setPrenom(string & prenom);
    void setAdresse(string & adresse);
    void setVille(string & ville);
    void setCommentaires(string & commentaires);
    void setDate(QDate & date);

	void setCodePostal(int codePostal);
	void setNumeroTelephone(int numeroTelephone);
	void setDureeConsultation(int dureeConsultation);
	void setPriorite(int priorite);

	bool operator<(Patient & patient);
	void transform();
	string toString();
};

