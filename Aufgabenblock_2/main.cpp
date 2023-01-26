#include <iostream>

#include <memory>
#include <vector>
#include <cstdio>
#include <ctime>
#include <list>
#include <random>


#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Tempolimit.h"
#include "SimuClient.h"
#include "vertagt_aktion.h"
#include "vertagt_liste.h"
#include "Kreuzung.h"
#include "Tempolimit.h"


//Unsere Globale Variablen
using namespace std;
double processingtime = 0.0;
double dGlobaleZeit = 0.0;
string seperator= "------------------------------------"
   			  "-----------------------------------------------------------------------\n";
double zeittakt = 0.4;
int space = 20;

bool isEqual(double a, double b)
{if(abs(a-b)<0.001){return true;}
else{return false;}}




//Testaufgabe fur die Konstruktoren und Destruktoren
void vAufgabe(){

    Fahrzeug* a = new Fahrzeug("a",4);
    Fahrzeug f("b",2);
    delete a;
    std::unique_ptr<Fahrzeug> uniquecar1 = std::make_unique<Fahrzeug>("car1",3);
    std::unique_ptr<Fahrzeug> uniquecar2 = std::make_unique<Fahrzeug>("car2",10);
    std::shared_ptr<Fahrzeug> sharedcar1 = std::make_shared<Fahrzeug>("car3",20);
    std::shared_ptr<Fahrzeug> sharedcar2 = std::make_shared<Fahrzeug>("car4",30);

    std::vector<std::unique_ptr<Fahrzeug>> uniquevector;

  uniquevector.push_back(std::move(uniquecar1));
  uniquevector.push_back(std::move(uniquecar2));

  uniquevector.clear();


  std::vector<std::shared_ptr<Fahrzeug>> sharedvector;
  sharedvector = {sharedcar1};
  sharedvector.push_back(std::move(sharedcar2));

  std::cout<<"Vector Size: "<<sharedvector.size()<<"\n";

}




//Basis Aufgabe
void vAufgabe_1a(){
	std::unique_ptr<Fahrzeug>  aufgabecar1 =
				std::make_unique<Fahrzeug>("Mercedes",19);

	std::unique_ptr<Fahrzeug>  aufgabecar2 =
			std::make_unique<Fahrzeug>("BMW",4);

	std::unique_ptr<Fahrzeug>  aufgabecar3 =
			std::make_unique<Fahrzeug>("Porsche",5);


	 std::vector<std::unique_ptr<Fahrzeug>> aufgabevector;


     aufgabevector.push_back(move(aufgabecar1));
     aufgabevector.push_back(move(aufgabecar2));
     aufgabevector.push_back(move(aufgabecar3));
    aufgabevector[0]->vKopf();
	while(true){

        //vAusgeben ist verandert deswegen ist diese Zeile auch rausgelassen
		aufgabevector[0]->vAusgeben(cout);
		cout<<"\n";
		aufgabevector[0]->vSimulieren();
	}



}

//Tanken Funktion und Geschwindigkeit Funktion, Unterklassen
void vAufgabe_2(){

     int pkwnummer = 0;
     int fahrradnummer = 0;
     double simulationdauer;
	cout<<"Fuer wie viele Stunden soll die Simulation laufen?: ;"<<endl;
	cin>>simulationdauer;

   cout<<"Nummer von PKWs: ";
   cin>>pkwnummer;
   cout<<endl;
   cout<<"Nummer von Fahrradern;   ";
   cin>>fahrradnummer;




	vector<unique_ptr<Fahrzeug>> aufgabe2vector;


	for(int i=0; i<pkwnummer; i++){
		 unique_ptr<PKW> pkws(new PKW("Auto" + to_string(i), 100, 30, 120 ));
		 aufgabe2vector.push_back(move(pkws));
	 }

	for(int i=0; i<fahrradnummer; i++){
			 unique_ptr<Fahrrad> fahrrad(new Fahrrad("Fahrrad" + to_string(i), 40 ));
			 aufgabe2vector.push_back(move(fahrrad));
		 }







     cout<<"Anzahl von Fahrzeugen:   "<<aufgabe2vector.size()<<"\n";

     aufgabe2vector[0]->vKopf();
   for(dGlobaleZeit=0; dGlobaleZeit<simulationdauer; dGlobaleZeit+=zeittakt){
    	for(int i=0; i<aufgabe2vector.size(); i++){
    		aufgabe2vector[i]->vSimulieren();
    		aufgabe2vector[i]->vAusgeben(cout);


    		if (fabs(dGlobaleZeit - 3.0) < zeittakt/2)
    		           {
    		               aufgabe2vector[i]->dTanken();
    		           }



    cout<<endl;
    	}

    }





}


void vAufgabe_AB1() {

   int l = 0; // Laufindex für gezielte AUsgabe
   vector<int> ausgabe{15};
   double dTakt = 0.3;

   std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
   vecFahrzeuge.push_back(make_unique <PKW>("Audi", 217, 10.7));
   vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 21.4));
   PKW bils("Audi",217,10.7);
   cout<<bils.p_dTankvolumen<<"\n";
   for(dGlobaleZeit = 0; dGlobaleZeit < 6; dGlobaleZeit += dTakt)
   {
       auto itL = find(ausgabe.begin(), ausgabe.end(), l);
       if (itL != ausgabe.end()) {
           std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
           Fahrzeug::vKopf();
       }

       for (int i = 0; i < (int) vecFahrzeuge.size(); i++)
       {
           vecFahrzeuge[i]->vSimulieren();

           if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
           {
               vecFahrzeuge[i]->dTanken();
           }
           if (itL != ausgabe.end()) {
               std::cout << *vecFahrzeuge[i] << endl;
           }
       }
       l++;
   }
   char c;
   std::cin >> c;
}






//Uberladene Funktionen
void vAufgabe_3(){
	PKW teslatruck("Tesla Truck",100,30,120);
	PKW mercedestruck("Mercedes Truck",120,30,120);

      teslatruck.vKopf();


		for(int i=0; i<2; i++){
			 teslatruck.vSimulieren();
			 mercedestruck.vSimulieren();

			 cout<<teslatruck;
			 	  cout<<endl;
			 	  cout<<mercedestruck;
			 	  cout<<endl;
		}
       bool x =  teslatruck<(mercedestruck);
       cout<< "Ergebnis:   " << x<<"\n";
       mercedestruck=(teslatruck);

       cout<<"Final Mercedes Truck:"<<mercedestruck;
       cout<<endl;


}


void vAufgabe4()
{Weg weg("weg",50);
weg.vKopf();
std::cout<<weg;}


void vAufgabe5()
{
	PKW teslatruck("Tesla Truck",100,30,120);
	cout<<"jo\n";
     cout<<dGlobaleZeit<<"\n";

	Weg weg("weg",500);

	unique_ptr<Fahrzeug> aufgabecar(new Fahrzeug("Mercedes", 90));
	//unique_ptr<Fahrzeug> aufgabecar2(new Fahrzeug("BMW", 95));

std::unique_ptr<Fahrzeug>  aufgabecar1 =
std::make_unique<Fahrzeug>("Mercedes",90);
std::unique_ptr<Fahrzeug>  aufgabecar2 =
std::make_unique<Fahrzeug>("BMW",95);
weg.vAnnahme(move(aufgabecar1));
weg.vAnnahme(move(aufgabecar2));
weg.vKopf();
double dTakt = 0.5;
for(dGlobaleZeit = 0 ;dGlobaleZeit<3; dGlobaleZeit += zeittakt)
{
	weg.vSimulieren();}

cout<<"jo\n";
cout<<weg;
}



void vAufgabe6()
{

	PKW teslatruck("Tesla Truck",100,30,120);


 Weg weghin("strassehin", 500, Tempolimit::Landstrasse);
 Weg wegzur("strassezur" ,500 ,Tempolimit::Landstrasse);

 std::unique_ptr<Fahrzeug> MercedesTruck(new PKW("MercedesTruck",150,5));
 std::unique_ptr<Fahrzeug> VolvoTruck(new PKW("VolvoTruck",100,3));
 std::unique_ptr<Fahrzeug> ParkingTesla(new PKW("ParkingTesla",100,3));
 int koordinaten[] = {500,250,100,250};

 //PKW mercedestruck("MercedesTruck",50,5);

 bInitialisiereGrafik(800, 500);
 bZeichneStrasse(weghin.getName(), wegzur.getName(), 500, 2, koordinaten);
 //bZeichnePKW(mercedestruck.getName() , weghin.getName(), /*mercedestruck.getdAbschnittStrecke()*/ 200/weghin.getLaenge() , mercedestruck.dGeschwindigkeit() , mercedestruck.getTankinhalt());
 //weghin.vKopf();
 //weg1.vAnnahme(MercedesTruck);  //@suppress("Invalid arguments")
 //weg1.vAnnahme(VolvoTruck);
 weghin.vAnnahme(move(MercedesTruck));
 weghin.vAnnahme(move(VolvoTruck), 4);



 for(dGlobaleZeit = 0 ;dGlobaleZeit<=7; dGlobaleZeit += zeittakt)
 {
	vSetzeZeit(dGlobaleZeit);

	weghin.vSimulieren();
 	weghin.vFahrzeugeZeichnen();

 	vSleep(700);}


 }



void vAufgabe_6a()
{

	     static std::mt19937 device(0);
	     std::uniform_int_distribution<int> dist(1, 10);
	     int zuf = dist(device);

vertagt::VListe<int> asd;
for(int i=0;i<10;i++)
{ int zuf = dist(device);
	asd.push_back(zuf); }
asd.vAktualisieren();
for (auto x : asd)  {
std::cout<<x<<",";
}
cout<<"\n";

for (auto it = asd.begin(); it != asd.end(); ++it)
{
	if(*it>5)
	{asd.erase(it);}
}

for (auto x : asd)  {
std::cout<<x<<",";
}
cout<<"\n";
asd.vAktualisieren();

for (auto x : asd)  {
std::cout<<x<<",";
}
cout<<"\n";

asd.push_back(zuf);
int zuf1 = dist(device);
asd.push_front(zuf1);
asd.vAktualisieren();

for (auto x : asd)  {
std::cout<<x<<",";
}

}

void vAufgabe_7()

{

	std::unique_ptr<Fahrzeug> MercedesTruck(new PKW("MercedesTruck",150,5));

	 Fahrzeug* a = new Fahrzeug("a",4);

//    Weg aa("aa");
//
//	 Weg W12("W12", 40, Tempolimit::Innerorts);
//	 Weg W21("W21", 40, Tempolimit::Innerorts);
//
//	 Weg W23a("W23a", 115, Tempolimit::Autobahn);
//	 Weg W32a("W32a", 115, Tempolimit::Autobahn);
//
//	 Weg W23b("W23b", 40, Tempolimit::Innerorts);
//	 Weg W32b("W32b", 40, Tempolimit::Innerorts);
//
//	 Weg W24("W24", 55, Tempolimit::Innerorts);
//	 Weg W42("W42", 55, Tempolimit::Innerorts);
//
//	 Weg W34("W34", 85, Tempolimit::Autobahn);
//	 Weg W43("W43", 85, Tempolimit::Autobahn);
//
//	 Weg W44a("W44a", 130, Tempolimit::Landstrasse);
//	 Weg W44b("W44b", 130, Tempolimit::Landstrasse);

	 int strasse1[] = {680,40,680,300};
     int strasse2 [] = {680,300,850,300,970,390,970,500,850,570,680,570};
     int strasse3 [] = {680,300,680,570};
     int strasse4 [] = {680,300,320,300};
     int strasse5 [] = {320,300,320,420,350,510,500,570,680,570};
     int strasse6 [] = {320,300,320,150,200,60,80,90,70,250,170,300,320,300};


     std::shared_ptr<Kreuzung> Kr1 = std::make_shared<Kreuzung>("Kr1");
     std::shared_ptr<Kreuzung> Kr2 = std::make_shared<Kreuzung>("Kr2");
     std::shared_ptr<Kreuzung> Kr3 = std::make_shared<Kreuzung>("Kr3");
     std::shared_ptr<Kreuzung> Kr4 = std::make_shared<Kreuzung> ("Kr4");


      Kr1->vVerbinde("W12", "W21", 40, Kr1, Kr2, Tempolimit::Innerorts, false);

      Kr2->vVerbinde("W23a", "W32a", 115, Kr2, Kr3, Tempolimit::Autobahn, false);
      Kr2->vVerbinde("W23b", "W32b", 40, Kr2, Kr3, Tempolimit::Innerorts, false);
      Kr2->vVerbinde("W24", "W42", 55, Kr2, Kr4, Tempolimit::Innerorts, false);

      Kr3->vVerbinde("W34", "W43", 85, Kr4, Kr3, Tempolimit::Autobahn, false);
      Kr4->vVerbinde("W44a", "W44b", 130, Kr4, Kr4, Tempolimit::Landstrasse, false);





	bInitialisiereGrafik(1000, 1000);
	bZeichneKreuzung(680, 40);	 //Kr1
    bZeichneKreuzung(680, 300);	 //Kr2
	bZeichneKreuzung(680, 570);	 //Kr3
	bZeichneKreuzung(320, 300);	 //Kr4
	bZeichneStrasse("W12", "W21", 40, 2, strasse1);
	bZeichneStrasse("W23a", "W32a", 115, 6, strasse2);
	bZeichneStrasse("W23b", "W32b", 40, 2, strasse3);
	bZeichneStrasse("W24", "W42", 55, 2, strasse4);
	bZeichneStrasse("W34", "W43", 85, 5, strasse5);
	bZeichneStrasse("W44a", "W44b", 130, 7, strasse6);



	unique_ptr<PKW> f1 = make_unique<PKW>("BMW", 10, 0.5);
	unique_ptr<PKW> f2 = make_unique<PKW>("Mercedes", 15, 0.1);
	unique_ptr<Fahrrad> f3 = make_unique<Fahrrad>("Torino", 40);
	Kr1->vAnnahme(move(f1), 0.0);
	Kr1->vAnnahme(move(f2), 3);
	Kr1->vAnnahme(move(f3), 20);



	 vSleep(3000);

	 while(true)
	 {

		vSetzeZeit(dGlobaleZeit);

		Kr1->vSimulieren();
		Kr2->vSimulieren();
		Kr3->vSimulieren();
		Kr4->vSimulieren();

	 	 vSleep(100);

	     dGlobaleZeit+=zeittakt;
	 }

}




int main(){
//vAufgabe();
//vAufgabe_1a();
//vAufgabe_2();
//vAufgabe_3();
//vAufgabe_AB1();
//vAufgabe4();
//vAufgabe5();
//vAufgabe6();
//vAufgabe_6a();
vAufgabe_7();











    return 0;
	}







