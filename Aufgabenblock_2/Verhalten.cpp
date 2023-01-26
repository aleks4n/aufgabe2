/*
 * Verhalten.cpp
 *
 *  Created on: 30.12.2022
 *      Author: aliihsangungoren
 */

#include "Verhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"


Verhalten::Verhalten(Weg& weg):speicherweg(weg)
{};

Verhalten::~Verhalten() {
	// TODO Auto-generated destructor stub
}


double Verhalten::getMaxGeschwindigkeit()
{return speicherweg.getTempolimit();}



