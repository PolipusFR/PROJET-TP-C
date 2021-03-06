#include "vue_canny.h"
#include <iostream>

//Constructeur
VueCanny::VueCanny(Controller& _controller, VueImage& _img)
	: Vue("Contours canny"), controller(_controller), image(_img)
{
	controller.addObserveur(this);
}

// Notifie
void VueCanny::notify()
{
	if (controller.getCurrentScreen() == 8)
		display();
}

// Affiche la vue
void VueCanny::display()
{
	clear();
	Vue::display();

	std::string chemin = image.getChemin();
	Mat image = imread(chemin);

	// Verifier si l'image existe bien
	if (image.empty())
	{
		std::cout << "Le fichier n'a pas �t� ouvert" << std::endl;
		std::cin.get();
	}

	std::string windowName = "Contour canny";
	Mat image_finale = FiltreCanny(image);
	affResult(image_finale, windowName);

	controller.setScreen(0);
}