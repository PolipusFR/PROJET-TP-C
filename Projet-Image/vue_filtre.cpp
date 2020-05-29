#include "vue_filtre.h"
#include <iostream>

// Constructeur
VueFiltre::VueFiltre(Controller& _controller)
	: Vue("Filtres"), controller(_controller)
{
	controller.addObserveur(this);
}

// Notifie
void VueFiltre::notify()
{
	if (controller.getCurrentScreen() == 2)
		display();
}

// Display la vue
void VueFiltre::display()
{
	clear();
	Vue::display();

	std::cout << "\tQuel filtre souhaitez-vous appliquer ?" << std::endl;
	std::cout << "\t1. Filtre median" << std::endl;
	std::cout << "\t2. Filtre gaussien" << std::endl;
	std::cout << "\t3. Gradient Sobel" << std::endl;
	std::cout << "\t4. Dilatation" << std::endl;
	std::cout << "\t5. Erosion" << std::endl;
	std::cout << "\t6. Detecteur de contour Canny" << std::endl;
	std::cout << "\t7. Seuillage" << std::endl;

	int choix;
	std::cin >> choix;

	controller.setScreen(choix + 2);
}
