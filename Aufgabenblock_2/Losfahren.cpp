/*
 * Losfahren.cpp
 *
 *  Created on: 06.01.2023
 *      Author: aliihsangungoren
 */

#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Simulationsobjekt.h"
#include "Weg.h"


Losfahren::Losfahren(Fahrzeug& fahrzeug, Weg& weg):Fahrausnahme(fahrzeug,weg){
	// TODO Auto-generated constructor stub

}

Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}

void Losfahren::vBearbeiten()
{std::cout<<"Ausnahme Losfahren"<<speicherfahrzeug<<"\n"<<speicherweg<<"\n"<<"||"<<dGlobaleZeit<<"||"<<"\n";
//speicherweg.pAbgabe(speicherfahrzeug);
speicherweg.vAnnahme(speicherweg.pAbgabe(speicherfahrzeug));

}

