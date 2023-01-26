/*
 * Fahrrad.h
 *
 *  Created on: 08.11.2022
 *      Author: aliihsangungoren
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"



class Fahrrad: public Fahrzeug {
public:
	Fahrrad(string p_sName,double p_dMaxGeschwindigkeit);
	 ~Fahrrad();
	 void vZeichnen(const Weg& weg);


private:

	        double dGeschwindigkeit() const;
	        static double zwischenstrecke;



};

#endif /* FAHRRAD_H_ */
