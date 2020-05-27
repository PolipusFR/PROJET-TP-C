#pragma once
#include "controller.h"
#include "vue_menu.h"
#include "vue_filtre.h"
#include "vue_loadimage.h"
#include "vue_median.h"
#include "vue_gauss.h"
#include "vue_sobel.h"
#include "vue_dilatation.h"
#include "vue_ero.h"
#include "vue_canny.h"
#include "vue_seuil.h"

class Application
{
private:
	Controller controller;
	VueMenu viewMenu;
	VueImage viewIm;
	VueFiltre viewFi;
	VueMedian viewMed;
	VueGauss viewGauss;
	VueSobel viewSob;
	VueDilatation viewDil;
	VueEro viewEro;
	VueCanny viewCanny;
	VueSeuil viewSeuil;

public:
	// Constructeur
	Application();

	// Lance l'application
	void run();
};

