#include <iostream>
#include <string>
#include <fstream>
#include "dossierProfesseur.h"
using namespace std;

int main()
{		
	DossierProfesseur unDossier = DossierProfesseur("dossier.txt");

	cout << "Prof le plus ancien : " << unDossier.ProfeseurLeplusAncien();

	unDossier.afficherListe();
	unDossier.Supprimer("MACRON Emmanuel");
	unDossier.afficherListe();
	
	system("pause");
}
