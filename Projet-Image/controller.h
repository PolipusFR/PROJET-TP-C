#pragma once
#include "sujet.h"

class Controller : public Sujet
{
private:
	// Num�ro de l'�cran actuel
	int currentScreen;

public:
	// Constructeur
	Controller();

	//Nouvel �cran � afficher
	void setScreen(const int& value);

	// Donne le num�ro de l'�cran affich�
	int getCurrentScreen();
};

