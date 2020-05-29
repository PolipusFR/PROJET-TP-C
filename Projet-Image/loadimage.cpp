#include "loadimage.h"
#include <iostream>

// Constructeur
VueImage::VueImage(Controller& _controller)
	: Vue("Charger une image"), controller(_controller)
{
	controller.addObserveur(this);
}

// Notifie
void VueImage::notify()
{
	if (controller.getCurrentScreen() == 1)
		display();
}

std::string VueImage::getChemin()
{
	return adresse;
}

// Display la vue
void VueImage::display()
{
	clear();
	Vue::display();

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Entrez le chemin de l'image à charger" << std::endl;

	std::cin.clear();
	std::cin >> adresse;

	controller.setScreen(0);
}
