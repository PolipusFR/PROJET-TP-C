#include "vue_seuil.h"
#include <iostream>

//Constructeur
VueSeuil::VueSeuil(Controller& _controller, VueImage& _img)
	: Vue("Seuillage"), controller(_controller), image(_img)
{
	controller.addObserveur(this);
}

// Notifie
void VueSeuil::notify()
{
	if (controller.getCurrentScreen() == 9)
		display();
}

// Affiche la vue
void VueSeuil::display()
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

	std::string windowName = "Seuillage";
	Mat image_finale = FiltreSeuil(image);
	affResult(image_finale, windowName);

	controller.setScreen(0);
}