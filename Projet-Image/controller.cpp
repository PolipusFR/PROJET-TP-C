#include "controller.h"

Controller::Controller()
{
}

// Définie l'écran actuel à afficher
void Controller::setScreen(const int& value)
{
	if (value >= 0 && value <= 99)
		currentScreen = value;

	notify();
}

// Retourne le numéro de l'écran affiché
int Controller::getCurrentScreen()
{
	return currentScreen;
}
