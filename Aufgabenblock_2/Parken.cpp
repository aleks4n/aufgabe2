/*
 * Parken.cpp
 *
 *  Created on: 30.12.2022
 *      Author: aliihsangungoren
 */

#include "Parken.h"
#include "Fahrzeug.h"
#include <math.h>
#include "Losfahren.h"

Parken::Parken(Weg& Weg, double p_dStartzeitpunkt):Verhalten(Weg){
	// TODO Auto-generated constructor stub
	Startzeitpunkt = p_dStartzeitpunkt;

}

Parken::~Parken() {
	// TODO Auto-generated destructor stub
}

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){
	if(abs(dGlobaleZeit-Startzeitpunkt)>0.01 && dGlobaleZeit < Startzeitpunkt)
	{
		return 0.0;
	}
	else if(abs(dGlobaleZeit-Startzeitpunkt)<0.01 || dGlobaleZeit > Startzeitpunkt)
	{throw Losfahren(aFzg, speicherweg);}
}

