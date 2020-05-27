//Constructeur
#include "vue_sobel.h"
#include <iostream>

//Constructeur
VueSobel::VueSobel(Controller& _controller, VueImage& _img)
	: Vue("Sobel"), controller(_controller), image(_img)
{
	controller.addObserveur(this);
}

// Notifie
void VueSobel::notify()
{
	if (controller.getCurrentScreen() == 5)
		display();
}

// Affiche la vue
void VueSobel::display()
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

	std::string windowName = "Gradient";
	Mat image_finale = FiltreSobel(image);
	affResult(image_finale, windowName);

	controller.setScreen(0);
}