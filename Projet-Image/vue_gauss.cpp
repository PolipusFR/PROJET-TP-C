#include "vue_gauss.h"
#include <iostream>

//Constructeur
VueGauss::VueGauss(Controller& _controller, VueImage& _img)
	: Vue("Filtre gaussien"), controller(_controller), image(_img)
{
	controller.addObserveur(this);
}

// Notifie
void VueGauss::notify()
{
	if (controller.getCurrentScreen() == 4)
		display();
}

// Affiche la vue
void VueGauss::display()
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

	std::string windowName = "Filtre gaussien";
	Mat image_finale = FiltreGauss(image);
	affResult(image_finale, windowName);

	controller.setScreen(0);
}