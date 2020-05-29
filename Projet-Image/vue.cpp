#include "vue.h"
#include <cstdlib>
#include <iostream>

// Constructeur
Vue::Vue(const std::string& _title)
	:title(_title)
{

}

// Vide la console
void Vue::clear() const
{
	system("CLS");
}

// Affiche l'écran
void Vue::display() const
{
	std::cout << title << std::endl << std::endl;
}
