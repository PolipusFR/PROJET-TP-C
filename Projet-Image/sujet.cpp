#include "sujet.h"

// Constructeur
Sujet::Sujet()
{
}

// Ajoute un observeur à la collection
void Sujet::addObserveur(Observeur* observeur)
{
	observeurs.push_back(observeur);
}

// Notifie tout les observeurs
void Sujet::notify()
{
	for (int iObserveur = 0; iObserveur < observeurs.size(); ++iObserveur)
	{
		observeurs[iObserveur]->notify();
	}
}
