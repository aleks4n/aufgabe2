/*
 * Simulationsobjekt.h
 *
 *  Created on: 14.12.2022
 *      Author: aliihsangungoren
 */

#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_
#include <iostream>
#pragma once
using namespace std;
extern int space;
extern string seperator;
class Simulationsobjekt {
public:

	Simulationsobjekt();
	Simulationsobjekt(std::string p_sName);
	virtual ~Simulationsobjekt();

public:
	Simulationsobjekt(Simulationsobjekt&&) = delete;
	Simulationsobjekt(const Simulationsobjekt&) = delete;
	virtual void vAusgeben(ostream& o) const;
	void vKopf();
	virtual void vSimulieren() = 0;
	std::string getName() const;
	std::string p_sName;
	int p_iID;
	double p_dZeit;


private:

static int p_iMaxID;
double p_dGesamtZeit;
void vInitialisieren();

bool operator ==(const Simulationsobjekt& vergleichobjekt)
    {return p_iID==vergleichobjekt.p_iID ;};



};
ostream& operator << (ostream& out, const Simulationsobjekt& vergleichobjekt );






#endif /* SIMULATIONSOBJEKT_H_ */
