/*
 * Fahrzeug.cpp
 *
 *  Created on: 30.10.2022
 *      Author: aliihsangungoren
 */
#include <iomanip>
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Fahren.h"
#include "Parken.h"
using namespace std;




void Fahrzeug::vInitialisierenn ()
{


	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
	p_pVerhalten = nullptr;
}



void Fahrzeug::vZeichnen(const Weg& weg)
{ }




Fahrzeug::Fahrzeug(std::string new_p_sName):Simulationsobjekt(new_p_sName)
{

	vInitialisierenn();

	std::cout<<"Object created:"
	<<" Name:"<<p_sName<<" ID:"<<p_iID<<"\n";



}
Fahrzeug::Fahrzeug():Simulationsobjekt(){
    vInitialisierenn();
	std::cout<<"Default Fahrzeug ist Erzeugt\n";

}

Fahrzeug::Fahrzeug(const std::string new_p_sName,
		 const double new_p_dMaxGeschwindigkeit):Simulationsobjekt(new_p_sName)

{

	 vInitialisierenn();

	 p_dMaxGeschwindigkeit = (new_p_dMaxGeschwindigkeit>0) ? new_p_dMaxGeschwindigkeit : 0;
	std::cout<<"Object created:"
	<<" Name:"<<" ID:"<<"\n";




}


Fahrzeug::~Fahrzeug()
{std::cout<<"Deleted:"
	<<" Name:"<<" ID:"<<"\n";}




double Fahrzeug::dTanken(double dMenge){return 0;};
double Fahrzeug::dGeschwindigkeit() const{return p_dMaxGeschwindigkeit;};
//
//
//
void Fahrzeug::vKopf(){
  cout<<"ID"<<setw(space)
	  <<"Name"<<setw(space)
	  <<"MaxGeschwindigkeit"<<setw(space)
	 <<"Gesamtstrecke"<<setw(space)
	 <<"AbschnittStrecke"<<setw(space)
	 <<"Gesamtverbrauch"<<setw(space)
	 <<"Tankinhalt\n"<<setw(space)
	 <<seperator<<"\n";

}




void Fahrzeug::vSimulieren(){
//p_dGesamtStrecke += dGeschwindigkeit()/(1/zeittakt);
//p_dAbschnittStrecke += dGeschwindigkeit()/(1/zeittakt);
if(!isEqual(p_dZeit, dGlobaleZeit))


{
double d_differenz = dGlobaleZeit - p_dZeit;
p_dGesamtZeit += d_differenz;
p_dGesamtStrecke += p_pVerhalten->dStrecke(*this, d_differenz);
p_dAbschnittStrecke +=  p_pVerhalten->dStrecke(*this, d_differenz);
p_dZeit = dGlobaleZeit;

}


}



void Fahrzeug::vAusgeben(ostream& o) const{

     Simulationsobjekt::vAusgeben(o);
   o<<dGeschwindigkeit()<<setw(space)
   <<p_dGesamtStrecke<<setw(space)
   <<p_dAbschnittStrecke<<setw(space);
   }


void Fahrzeug::vNeueStrecke(Weg& w)
{
	    p_pVerhalten = std::make_unique<Fahren>(w);

		p_dAbschnittStrecke = 0;



};


void Fahrzeug::vNeueStrecke(Weg& w, double Startzeit)
{
	    p_pVerhalten = std::make_unique<Parken>(w, Startzeit);

		p_dAbschnittStrecke = 0;



};


double Fahrzeug::getdAbschnittStrecke()
{return p_dAbschnittStrecke;};






