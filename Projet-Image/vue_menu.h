#pragma once
#include "observeur.h"
#include "vue.h"
#include "controller.h"

class VueMenu : public Vue
{
private:
	// Controller de l'application
	Controller& controller;
public:
	//Constructeur
	VueMenu(Controller& _controller);

	// Notification de la vue
	virtual void notify();

	// Display de la vue
	virtual void display();
};