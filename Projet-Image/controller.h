#pragma once
#include "sujet.h"

class Controller : public Sujet
{
private:
	// Numéro de l'écran actuel
	int currentScreen;

public:
	// Constructeur
	Controller();

	//Nouvel écran à afficher
	void setScreen(const int& value);

	// Donne le numéro de l'écran affiché
	int getCurrentScreen();
};

