#include "vue_ero.h"
#include <iostream>

//Constructeur
VueEro::VueEro(Controller& _controller, VueImage& _img)
	: Vue("Erosion"), controller(_controller), image(_img)
{
	controller.addObserveur(this);
}

// Notifie
void VueEro::notify()
{
	if (controller.getCurrentScreen() == 7)
		display();
}

// Affiche la vue
void VueEro::display()
{
	clear();
	Vue::display();

	std::string chemin = image.getChemin();
	Mat image = imread(chemin);

	// Verifier si l'image existe bien
	if (image.empty())
	{
		std::cout << "Le fichier n'a pas été ouvert" << std::endl;
		std::cin.get();
	}

	std::string windowName = "Erosion";
	Mat image_finale = FiltreErosion(image);
	affResult(image_finale, windowName);

	controller.setScreen(0);
}