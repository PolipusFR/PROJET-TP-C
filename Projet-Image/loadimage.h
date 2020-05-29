#pragma once
#include "vue.h"
#include "controller.h"

class VueImage : public Vue
{
private:
	// Controlleur de l'application
	Controller& controller;
	std::string adresse;

public:
	// Constructeur
	VueImage(Controller& _controller);

	virtual void notify();

	std::string getChemin();

	// Affiche la vue
	virtual void display();

};

