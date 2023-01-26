/*
 * Losfahren.h
 *
 *  Created on: 06.01.2023
 *      Author: aliihsangungoren
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"
class Fahrzeug;
class Simulationsobjekt;

class Losfahren: public Fahrausnahme {
public:
	Losfahren(Fahrzeug& fahrzeug, Weg& weg);
	void vBearbeiten();
	virtual ~Losfahren();
};

#endif /* LOSFAHREN_H_ */
