#include "controller.h"

Controller::Controller()
{
}

// D�finie l'�cran actuel � afficher
void Controller::setScreen(const int& value)
{
	if (value >= 0 && value <= 99)
		currentScreen = value;

	notify();
}

// Retourne le num�ro de l'�cran affich�
int Controller::getCurrentScreen()
{
	return currentScreen;
}
