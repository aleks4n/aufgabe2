/*
 * Fahren.h
 *
 *  Created on: 30.12.2022
 *      Author: aliihsangungoren
 */

#ifndef FAHREN_H_
#define FAHREN_H_
#include "Verhalten.h"
extern bool isEqual(double a, double b);
class Fahren: public Verhalten {
public:
	Fahren(Weg& Weg);
	virtual ~Fahren();
	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);

};

#endif /* FAHREN_H_ */
