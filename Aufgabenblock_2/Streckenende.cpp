/*
 * Streckenende.cpp
 *
 *  Created on: 06.01.2023
 *      Author: aliihsangungoren
 */

#include "Streckenende.h"
#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg):Fahrausnahme(fahrzeug, weg){
	// TODO Auto-generated constructor stub

}

Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}
void Streckenende::vBearbeiten()
{std::cout<<"Ausnahme Streckenende"<<speicherfahrzeug<<"\n"<<speicherweg<<"\n";
unique_ptr<Fahrzeug> lokalspeicher = speicherweg.pAbgabe(speicherfahrzeug);
shared_ptr<Kreuzung> zielkrz = speicherweg.getZielkreuzung();
shared_ptr<Weg>  neueweg = zielkrz->pZufaelligerWeg(speicherweg);

zielkrz->vTanken(speicherfahrzeug);
lokalspeicher->vNeueStrecke(*neueweg);
neueweg->vAnnahme(move(lokalspeicher));


cout<<"[Zeit]           :"<< dGlobaleZeit<<"\n";
cout<<"[Kreuzung]           :"<< zielkrz->p_sName<<"\n";
cout<<"[Wechsel]           :"<< neueweg->p_sName<<"\n";
cout<<"[Fahrzeug]           :"<< speicherfahrzeug<<"\n";


}

