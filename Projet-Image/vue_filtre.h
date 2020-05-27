#pragma once
#include "vue.h"
#include "observeur.h"
#include "controller.h"

class VueFiltre : public Vue
{
private:
	Controller& controller;
public:
	// Constructeur
	VueFiltre(Controller& _controller);

	// Notification de la vue
	virtual void notify();

	// display de la vue
	virtual void display();
};

