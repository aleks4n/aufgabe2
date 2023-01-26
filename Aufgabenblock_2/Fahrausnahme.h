/*
 * Fahrausnahme.h
 *
 *  Created on: 06.01.2023
 *      Author: aliihsangungoren
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_
class Simulationsobjekt;
class Fahrzeug;
class Weg;
#include <exception>
#include <iostream>

class Fahrausnahme: public std::exception {
public:
	Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg);
	virtual void vBearbeiten() = 0;
	virtual ~Fahrausnahme();
	 Weg&  speicherweg;
	 Fahrzeug& speicherfahrzeug;

};

#endif /* FAHRAUSNAHME_H_ */
