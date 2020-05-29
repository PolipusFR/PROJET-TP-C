#pragma once
#include <string>
#include "observeur.h"

// Vue de base

class Vue : public Observeur
{
private:
	// Titre de la vue
	std::string title;
public:

	// Constructeur
	Vue(const std::string& _title);

	// Vider la console
	void clear() const;

	// Ecran
	virtual void display() const;
};



