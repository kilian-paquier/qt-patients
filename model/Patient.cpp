#include "Patient.h"

Patient::Patient()
{
}


Patient::~Patient()
{
}

string & Patient::getNom()
{
	return nom;
}

string & Patient::getPrenom()
{
	return prenom;
}

string & Patient::getAdresse()
{
	return adresse;
}

string & Patient::getVille()
{
	return ville;
}

string & Patient::getCommentaires()
{
	return commentairesMaladie;
}

unsigned int & Patient::getCodePostal()
{
	return codePostal;
}

string & Patient::getNumeroTelephone()
{
	return numeroTelephone;
}

int & Patient::getDureeConsultation()
{
	return dureeConsultation;
}

int & Patient::getPriorite()
{
	return priorite;
}

vector<int> & Patient::getIdentifiantsRessources()
{
	return identifiantsRessources;
}

void Patient::setIdentifiantsRessources(vector<int> &identifiants)
{
	(*this).identifiantsRessources = identifiants;
}

void Patient::addIdentifiantRessources(int &identifiant)
{
	(*this).identifiantsRessources.push_back(identifiant);
}

void Patient::setNom(string &nom)
{
	(*this).nom = nom;
}

void Patient::setPrenom(string &prenom)
{
	(*this).prenom = prenom;
}

void Patient::setAdresse(string &adresse)
{
	(*this).adresse = adresse;
}

void Patient::setVille(string &ville)
{
	(*this).ville = ville;
}

void Patient::setCommentaires(string &commentaires)
{
	(*this).commentairesMaladie = commentaires;
}

void Patient::setCodePostal(unsigned int &codePostal)
{
	(*this).codePostal = codePostal;
}

void Patient::setNumeroTelephone(string &numeroTelephone)
{
	(*this).numeroTelephone = numeroTelephone;
}

void Patient::setDureeConsultation(int &dureeConsultation)
{
	(*this).dureeConsultation = dureeConsultation;
}

void Patient::setPriorite(int &priorite)
{
	(*this).priorite = priorite;
}

bool Patient::operator<(Patient & patient)
{
    int contraignanceThis = priorite * 100 + static_cast<int>(identifiantsRessources.size()) * 10 + dureeConsultation;
    int contraignancePatient = patient.getPriorite() * 100 + static_cast<int>(patient.getIdentifiantsRessources().size()) * 10 + patient.getDureeConsultation();
	return contraignanceThis < contraignancePatient;
}

void Patient::transform()
{
	sort(identifiantsRessources.begin(), identifiantsRessources.end());
}

string Patient::toString()
{
	return string();
}

QDate & Patient::getDate() {
    return date;
}

int &Patient::getIdentifiant()
{
    return identifiant;
}

void Patient::setDate(QDate &date) {
    this->date = date;
}

void Patient::setIdentifiant(int &identifiant)
{
    this->identifiant = identifiant;
}
