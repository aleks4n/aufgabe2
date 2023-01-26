/*
 * Streckenende.h
 *
 *  Created on: 06.01.2023
 *      Author: aliihsangungoren
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"
class Fahrzeug;
class Simulationsobjekt;
class Weg;
class Streckenende: public Fahrausnahme {
public:
	Streckenende(Fahrzeug& fahrzeug, Weg& weg);
	void vBearbeiten();
	virtual ~Streckenende();
};

#endif /* STRECKENENDE_H_ */
