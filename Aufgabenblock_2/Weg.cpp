/*
 * Weg.cpp
 *
 *  Created on: 20.12.2022
 *      Author: aliihsangungoren
 */
#include "Fahrzeug.h"
#include "Weg.h"
#include "Fahrausnahme.h"
#include "Kreuzung.h"
#include <iomanip>
#include <list>
//Weg::Weg(std::string new_p_sName, double new_p_dLaenge, const Tempolimit new_tempolimit)
//:Simulationsobjekt(new_p_sName)
//{p_dLaenge = new_p_dLaenge;
// p_eTemplimit = new_tempolimit;
//p_dZeit = 0.0;}


Weg::Weg(std::string p_sName):Simulationsobjekt(p_sName){}

//Weg::Weg(std::string p_sName, double lange):Simulationsobjekt(p_sName), p_dLaenge(lange){}

Weg::Weg(std::string p_sName, double lange, Tempolimit tempo):Simulationsobjekt(p_sName), p_dLaenge(lange), p_eTemplimit(tempo){}

Weg::Weg(std::string p_sName,
		double dLaenge,
		const Tempolimit tempolimit,
		weak_ptr<Kreuzung> zielkreuzung)
:Simulationsobjekt(p_sName),p_dLaenge(dLaenge), p_eTemplimit(tempolimit), Zielkreuzung(zielkreuzung)
{}



Weg::Weg() {
	// TODO Auto-generated constructor stub

}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

//buraya bak
shared_ptr<Weg> Weg::getRueckweg(){

	return Rueckweg.lock();
}
//buraya bak
shared_ptr<Kreuzung> Weg::getZielkreuzung(){

	return Zielkreuzung.lock();
}


void Weg::setRueckweg(shared_ptr<Weg> Rueck)
{ Rueckweg = Rueck; }

void Weg::setZielkreuzung(shared_ptr<Kreuzung> ziel)
{Zielkreuzung = ziel; }





double Weg::getTempolimit() const
{return double(p_eTemplimit);}


void Weg::vFahrzeugeZeichnen() {
	for (auto const& f : p_pFahrzeuge) {
		f->vZeichnen(*this);
	}
}


void Weg::vSimulieren()
{for(auto const& i : p_pFahrzeuge){
	       try
			{
				i->vSimulieren();
			}
			catch (Fahrausnahme& ausnahme)
			{
				ausnahme.vBearbeiten();
			}

	//i->vSimulieren();
}
p_dZeit = dGlobaleZeit;
p_pFahrzeuge.vAktualisieren();
vFahrzeugeZeichnen();
}

double Weg::getLaenge() const
{return p_dLaenge;};

void Weg::vAusgeben(ostream& o) const{
	Simulationsobjekt::vAusgeben(o);

	o<<p_dLaenge<<setw(space)<<"(";

	for(auto const& i : p_pFahrzeuge){
		o<<i->p_sName<<" ";
	}

	o<<")";
}




void Weg::vAnnahme(unique_ptr<Fahrzeug> Fahrzeug)
{   Fahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(move(Fahrzeug));
};


void Weg::vKopf()
{std::cout<<"ID"<<setw(space)<<"Name"<<setw(space)<<"Laenge"<<setw(space)<<"Fahrzeuge"<<"\n"
	<<seperator;}


void Weg::vAnnahme(unique_ptr<Fahrzeug> Fahrzeug, double dStartzeit)
{
	Fahrzeug->vNeueStrecke(*this, dStartzeit);
	p_pFahrzeuge.push_front(move(Fahrzeug));
}




//buraxa bak
unique_ptr<Fahrzeug> Weg::pAbgabe(const Fahrzeug& fahrzeug)
{
//for(list<unique_ptr<Fahrzeug>>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it)

	auto it = find_if(p_pFahrzeuge.begin(), p_pFahrzeuge.end(), [&](std::unique_ptr<Fahrzeug>& a) {return a.get() == &fahrzeug; });
	unique_ptr<Fahrzeug> lokal = move(*it);
	if (it != p_pFahrzeuge.end())
	{
		p_pFahrzeuge.erase(it);
		return lokal;
	}

	else{
		return make_unique<Fahrzeug>(nullptr);}

	p_pFahrzeuge.vAktualisieren();
}










