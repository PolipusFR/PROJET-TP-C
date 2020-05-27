#pragma once
#include "vue.h"
#include "controller.h"
#include "Header.h"
#include "observeur.h"
#include "vue_loadimage.h"

class VueSobel : public Vue
{
private:
	// Controlleur de application
	Controller& controller;
	VueImage& image;

public:
	// Constructeur
	VueSobel(Controller& _controller, VueImage& _img);

	virtual void notify();

	// Affiche la vue
	virtual void display();
};