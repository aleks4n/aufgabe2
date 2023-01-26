/*
 * Fahrrad.cpp
 *
 *  Created on: 08.11.2022
 *      Author: aliihsangungoren
 */

#include "Fahrrad.h"
#include "Simuclient.h"
#include "Weg.h"

double Fahrrad::zwischenstrecke =0;

Fahrrad::Fahrrad(const string new_p_sName,
		 const double new_p_dMaxGeschwindigkeit)
   :Fahrzeug(new_p_sName, new_p_dMaxGeschwindigkeit)

{std::cout<<"Fahrrad created:"
	<<" Name:"<<p_sName<<" ID:"<<p_iID<<"\n";}
	// TODO Auto-generated constructor stub



Fahrrad::~Fahrrad() {
	// TODO Auto-generated destructor stub
	std::cout<<"Fahrrad deleted:"
		<<" Name:"<<p_sName<<" ID:"<<p_iID<<"\n";
}


double Fahrrad::dGeschwindigkeit() const{

    double dSpeed = p_dMaxGeschwindigkeit;
	int anzahl20 = p_dGesamtStrecke/20;
	dSpeed = pow(0.9, anzahl20)*dSpeed;

	   if(dSpeed<=12){
		   dSpeed = 12;
	   }


	return dSpeed;
}


void Fahrrad::vZeichnen(const Weg& weg)
{ bZeichneFahrrad(p_sName, weg.getName(), getdAbschnittStrecke()/weg.getLaenge(), dGeschwindigkeit());}













