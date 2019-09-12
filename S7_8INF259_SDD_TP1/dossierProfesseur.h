#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct cours {
	char* sigle;
	int nbEtudints;
	cours* suivant;
};

struct Professeur{
	char* nom;
	int anciennete;
	cours* listeCours;
	Professeur* suivant;
};
