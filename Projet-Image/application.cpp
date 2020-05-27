#include "application.h"

// Constructeur
Application::Application()
	: controller(), viewMenu(controller), viewIm(controller), viewFi(controller), viewMed(controller, viewIm)
	, viewGauss(controller, viewIm), viewSob(controller, viewIm), viewDil(controller, viewIm), viewEro(controller, viewIm), viewCanny(controller, viewIm), viewSeuil(controller, viewIm)
{
}

// Lance l'application
void Application::run()
{
	controller.notify();
}
