/*
 * Fahrzeug.h
 *
 *  Created on: 30.10.2022
 *      Author: aliihsangungoren
 */


#include <iostream>
#include <iomanip>
#include <cmath>
#include "Simulationsobjekt.h"
//#include "Verhalten.h"
#pragma once
using namespace std;
extern double processingtime;
extern double dGlobaleZeit;
extern double zeittakt;
extern bool isEqual(double a, double b);

class Weg;
class Verhalten;
class Fahrzeug: public Simulationsobjekt {

protected:

double p_dMaxGeschwindigkeit;
double p_dGesamtZeit;
double p_dZeit;
unique_ptr<Verhalten> p_pVerhalten;
double p_dAbschnittStrecke;




private :



public:

    double p_dGesamtStrecke;



	Fahrzeug();
	Fahrzeug(std::string p_sName);
	Fahrzeug(const std::string p_sName, const double p_dMaxGeschwindigkeit);



    virtual ~Fahrzeug();
    Fahrzeug(Fahrzeug&&) = delete;
    Fahrzeug(const Fahrzeug&) = delete;



    static void vKopf();
    virtual void vSimulieren();
    void vAusgeben(ostream& o) const;
    void vInitialisierenn();
    virtual double dTanken(double dMenge = std::numeric_limits<size_t>::max());
    virtual void vZeichnen(const Weg& weg);
    virtual double dGeschwindigkeit() const;
    bool operator <(const Fahrzeug& vergleichfahrzeug)
    {return p_dGesamtStrecke< vergleichfahrzeug.p_dGesamtStrecke ;};
    void operator =(const Fahrzeug& copyfahrzeug)
        {this->p_sName = copyfahrzeug.p_sName;
        this->p_iID = copyfahrzeug.p_iID;
        this->p_dMaxGeschwindigkeit = copyfahrzeug.p_dMaxGeschwindigkeit;};
    void vNeueStrecke(Weg& w);
    void vNeueStrecke(Weg& w, double dStartzeit);
    double getdAbschnittStrecke();




};


//Const problem here








