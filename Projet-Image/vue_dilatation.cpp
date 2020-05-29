#include "vue_dilatation.h"
#include <iostream>

//Constructeur
VueDilatation::VueDilatation(Controller& _controller, VueImage& _img)
	: Vue("Dilatation"), controller(_controller), image(_img)
{
	controller.addObserveur(this);
}

// Notifie
void VueDilatation::notify()
{
	if (controller.getCurrentScreen() == 6)
		display();
}

// Affiche la vue
void VueDilatation::display()
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

	std::string windowName = "Dilatation";
	Mat image_finale = FiltreDilatation(image);
	affResult(image_finale, windowName);

	controller.setScreen(0);
}