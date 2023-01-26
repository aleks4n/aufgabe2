/*
 * Verhalten.h
 *
 *  Created on: 30.12.2022
 *      Author: aliihsangungoren
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_
class Weg;
class Fahrzeug;
class Verhalten{
public:
	Verhalten(Weg& Weg);
	virtual ~Verhalten();
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;
	 Weg &speicherweg;
	 double getMaxGeschwindigkeit();


private:

};

#endif /* VERHALTEN_H_ */
