/*
 * Kreuzung.cpp
 *
 *  Created on: 18.01.2023
 *      Author: aliihsangungoren
 */

#include "Kreuzung.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <random>
#include <list>
#include <iterator>
using namespace std;
Kreuzung::Kreuzung(std::string name): Simulationsobjekt(name) {
	// TODO Auto-generated constructor stub
	p_dTankstelle = 0;
	p_pWeg = {};

}

Kreuzung::~Kreuzung() {

}


Kreuzung::Kreuzung(std::string name, double tankinhalt): Simulationsobjekt(name)
{p_dTankstelle = tankinhalt;}


void Kreuzung::vTanken(Fahrzeug& fahrzeug) {
	if (p_dTankstelle > 0.0) {
		double tankmenge = fahrzeug.dTanken();
		p_dTankstelle -= tankmenge;
	}
		else{
			p_dTankstelle = 0.0;
		}

}


void Kreuzung::vAnnahme(unique_ptr<Fahrzeug> fahrzeug, double zeit)
{

	    vTanken(*fahrzeug);
		auto weg = p_pWeg.front();
		weg->vAnnahme(move(fahrzeug), zeit);
}

void Kreuzung::vSimulieren()
{


	for(auto const& weg : p_pWeg)
     {weg->vSimulieren();}


}

void Kreuzung::vVerbinde(std::string hin, std::string zur,
			double weglaenge, shared_ptr<Kreuzung> startkreuzung,
			shared_ptr<Kreuzung> zielkreuzung,  Tempolimit tempo,
			bool verbot)
{


	std::shared_ptr<Weg> weghin = std::make_shared<Weg>(hin, weglaenge, tempo, zielkreuzung);
	std::shared_ptr<Weg> wegzur = make_shared<Weg>(zur, weglaenge,tempo, startkreuzung);

	weghin->setRueckweg(wegzur);
	wegzur->setRueckweg(weghin);

	weghin->setZielkreuzung(zielkreuzung);
	wegzur->setZielkreuzung(startkreuzung);


	startkreuzung->p_pWeg.push_back(weghin);
	zielkreuzung->p_pWeg.push_back(wegzur);

}



shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& weg)
{



	if(p_pWeg.size()==1)
	{return p_pWeg.front();}

	else{
	std::mt19937 gen;
	std::uniform_int_distribution<size_t> dist (0, p_pWeg.size () - 1);
    list<shared_ptr<Weg>>::iterator begin = p_pWeg.begin();
	auto zufallig = std::next(begin, rand() % p_pWeg.size());
    return *zufallig;
	}
}


double Kreuzung::getTankstelle()
{
return p_dTankstelle;
}






