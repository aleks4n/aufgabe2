/*
 * Parken.h
 *
 *  Created on: 30.12.2022
 *      Author: aliihsangungoren
 */

#ifndef PARKEN_H_
#define PARKEN_H_

#include "Verhalten.h"

class Parken: public Verhalten {
public:
	Parken(Weg& Weg, double Startezeitpunkt);
	virtual ~Parken();
	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);
	double Startzeitpunkt;
};

#endif /* PARKEN_H_ */
