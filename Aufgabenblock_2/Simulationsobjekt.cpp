/*
 * Fahrzeug.cpp
 *
 *  Created on: 30.10.2022
 *      Author: aliihsangungoren
 */

#include "Simulationsobjekt.h"
#include <iomanip>
int Simulationsobjekt::p_iMaxID = 0;





Simulationsobjekt::Simulationsobjekt(std::string new_p_sName) {
	// TODO Auto-generated constructor stub
	vInitialisieren();
	p_sName =new_p_sName;

}

Simulationsobjekt::Simulationsobjekt(){}

Simulationsobjekt::~Simulationsobjekt() {
	// TODO Auto-generated destructor stub
	cout<<"Simulationsobjekt ist geloscht mit id:"<<p_iID<<"\n";
}

void Simulationsobjekt::vInitialisieren(){
  p_sName = "";
  p_iID = p_iMaxID;
  p_iMaxID++;
}

void Simulationsobjekt::vAusgeben(ostream& o) const{


	  o<<p_iID<<setw(space)
	   <<p_sName<<setw(space);
	   }

ostream& operator << (ostream& out, const Simulationsobjekt& vergleichobjekt)
{
	vergleichobjekt.vAusgeben(out);
	out<<"\n";
	return out;
}

std::string Simulationsobjekt::getName() const
{return p_sName;}









