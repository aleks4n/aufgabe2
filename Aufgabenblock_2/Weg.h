/*
 * Weg.h
 *
 *  Created on: 20.12.2022
 *      Author: aliihsangungoren
 */

#ifndef WEG_H_
#define WEG_H_
#pragma once
#include "Simulationsobjekt.h"
#include <list>
class Fahrzeug;
class Simulationsobjekt;
class Kreuzung;
#include "vertagt_liste.h"
#include "Tempolimit.h"

class Weg: public Simulationsobjekt {
public:
	Weg();
	Weg(std::string p_sName);

	Weg(std::string p_sName, double lange, const Tempolimit tempolimit = Tempolimit::Autobahn);
	//Weg(std::string p_sName, double p_dLaenge, const Tempolimit tempolimit = Tempolimit::Autobahn);
	Weg(std::string p_sName,
			double p_dLaenge,
			const Tempolimit tempolimit ,
			weak_ptr<Kreuzung> Zielkreuzung
			);
	virtual ~Weg();
	void vKopf();
	void vAnnahme(unique_ptr<Fahrzeug> Fahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug> Fahrzeug, double Startzeit);
	double getLaenge() const;
	void vSimulieren();
	double getTempolimit() const;
	void vFahrzeugeZeichnen();
	unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug& fahrzeug);
	shared_ptr<Weg> getRueckweg();
	shared_ptr<Kreuzung> getZielkreuzung();
    vertagt::VListe<unique_ptr<Fahrzeug>> p_pFahrzeuge;



    weak_ptr<Weg> Rueckweg;
    weak_ptr<Kreuzung> Zielkreuzung; //buraya bakkk ;


    void setZielkreuzung(shared_ptr<Kreuzung> ziel);
    void setRueckweg(shared_ptr<Weg> Rueck);

private:

	    double p_dLaenge;
		Tempolimit p_eTemplimit;
	   // std::list<unique_ptr<Fahrzeug>> p_pFahrzeuge;
	    void vAusgeben(ostream& o) const;



};

#endif /* WEG_H_ */
