#include "vue_median.h"
#include <iostream>

//Constructeur
VueMedian::VueMedian(Controller& _controller, VueImage& _img)
	: Vue("Filtre médian"), controller(_controller), image(_img)
{
	controller.addObserveur(this);
}

// Notifie
void VueMedian::notify()
{
	if (controller.getCurrentScreen() == 3)
		display();
}

// Affiche la vue
void VueMedian::display()
{
	clear();
	Vue::display();

	std::string chemin = image.getChemin();
	std::cout << chemin << std::endl;
	Mat image = imread(chemin);

	// Verifier si l'image existe bien
	if (image.empty())
	{
		std::cout << "Le fichier n'a pas été ouvert" << std::endl;
		std::cin.get();
	}

	std::cout << chemin;
	std::string windowName = "Filtre médian";
	affResult(image, windowName);
	Mat image_finale = FiltreMedian(image);
	affResult(image_finale, windowName);

	controller.setScreen(0);
}