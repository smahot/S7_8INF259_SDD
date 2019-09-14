#include <iostream>
#include <string>
#include <fstream>
#include "dossierProfesseur.h"
using namespace std;

int main()
{		
	DossierProfesseur unDossier = DossierProfesseur("dossier.txt");
	cout << "Prof le plus ancien : " << unDossier.ProfeseurLeplusAncien() << endl;
	cout << "Cours le plus demande : " << unDossier.LecoursLeplusDemande() << endl;
	unDossier.afficherListe();

	//unDossier.Supprimer("MACRON Emmanuel");
	unDossier.Recopier("fichierSortie.txt");
	system("pause");
}
