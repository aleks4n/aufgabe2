/*
 * Kreuzung.h
 *
 *  Created on: 18.01.2023
 *      Author: aliihsangungoren
 */

#ifndef KREUZUNG_H_
#define KREUZUNG_H_

#include "Simulationsobjekt.h"
#include "Tempolimit.h"
#include <list>
class Weg;
class Fahrzeug;

class Kreuzung: public Simulationsobjekt {
public:
	Kreuzung(std::string name);
	Kreuzung(std::string name, double tankinhalt);
    ~Kreuzung();

	static void vVerbinde
	        (std::string hin, std::string zur,
			double weglaenge, shared_ptr<Kreuzung> startkreuzung,
			shared_ptr<Kreuzung> zielkreuzung, const Tempolimit tempo,
			bool verbot);
	void vTanken(Fahrzeug& fahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug> fahrzeug, double zeit);
	void vSimulieren();
	shared_ptr<Weg> pZufaelligerWeg(Weg& weg);
	double getTankstelle();

private:
	    list<shared_ptr<Weg>> p_pWeg;
		double p_dTankstelle;
};

#endif /* KREUZUNG_H_ */

