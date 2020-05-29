#pragma once
#include <vector>
#include "observeur.h"

class Sujet
{
private:
	//Collection d'observeurs
	std::vector<Observeur*> observeurs;
public:
	// Constructeur
	Sujet();

	// Ajoute un observeur à la collection
	void addObserveur(Observeur* observer);

	// Notifie tout les observeurs
	void notify();
};

