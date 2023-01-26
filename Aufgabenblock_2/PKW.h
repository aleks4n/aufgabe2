/*
 * PKW.h
 *
 *  Created on: 08.11.2022
 *      Author: aliihsangungoren
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"


using namespace std;

class PKW: public Fahrzeug{
public:
	PKW(const string p_sName,
			const double p_sdMaxGeschwindigkeit, const double p_dVerbrauch,
			const double p_dTankvolumen = 55);
	      ~PKW();

	        double dTanken(double dMenge = std::numeric_limits<size_t>::max());

	        double dGeschwindigkeit() const;
			void vAusgeben(ostream& o) const;
			double p_dTankvolumen;
			double getTankinhalt();
		    void vZeichnen(const Weg& weg);
		    void vSimulieren();
private:

	    double p_dVerbrauch; //Liter 100Km
	    double p_dTankinhalt;
		double p_dGesamtverbrauch;

};

#endif /* PKW_H_ */
