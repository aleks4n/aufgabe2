/*
 * Fahren.cpp
 *
 *  Created on: 30.12.2022
 *      Author: aliihsangungoren
 */

#include "Fahren.h"
#include "Verhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"

Fahren::Fahren(Weg& Weg):Verhalten(Weg){
	// TODO Auto-generated constructor stub

}

Fahren::~Fahren() {
	// TODO Auto-generated destructor stub
}


double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	double d_gefahreneStrecke = aFzg.dGeschwindigkeit() * dZeitIntervall;
    double letzteschritt = speicherweg.getLaenge()- aFzg.getdAbschnittStrecke();

    if(isEqual(letzteschritt, 0.0))
    {
    	throw Streckenende(aFzg, speicherweg);}



    return min<double>(d_gefahreneStrecke,letzteschritt);




};

