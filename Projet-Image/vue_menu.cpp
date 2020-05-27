#include "vue_menu.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>


// Constructeur
VueMenu::VueMenu(Controller& _controller)
	: Vue("Menu"), controller(_controller)
{
	controller.addObserveur(this);
}


// Notifie
void VueMenu::notify()
{
	if (controller.getCurrentScreen() == 0)

		display();
}

// Display la vue



void VueMenu::display(){

	clear();
	Vue::display();
	
	setlocale(LC_ALL, "");
	std::wcout << L"                                                 ┌────────────────┐" << std::endl;
	std::wcout << L"                                                 │                │" << std::endl;
	std::wcout << L"                                                 │ PHOTO-MODIFIER │" << std::endl;
	std::wcout << L"                                                 │                │" << std::endl;
	std::wcout << L"                                                 │   by Louis²    │" << std::endl;
	std::wcout << L"                                                 └────────────────┘" << std::endl;
	std::wcout << "                                                 " << std::endl;


	std::cout << "                                                1. Charger une image" << std::endl;
	std::cout << "                                                2. Modifier l'image" << std::endl;
	std::cout << "                                                 " << std::endl;
	std::cout << "                                                     9. Quitter" << std::endl;
	std::cout << std::endl;


	int choix;
	std::cin.clear();
	std::cin >> choix;

	if (choix == 9)
	{
		choix = 42;
	}
	controller.setScreen(choix);
}
