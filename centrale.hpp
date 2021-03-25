#ifndef DEF_CENTRALE
#define DEF_CENTRALE
#include <iostream>
#include "circuitprimaire.h"
#include "circuitsecondaire.h"
#include "circuit.h"


 class centrale:
{
	public:
	//constructeur par defaut car valeurs d'initialisation connues
	centrale(){ cout << " Nouvelle centrale créée"  <<endl;};



	//predicats
	double get_etat_enceinte_confinement() const ;
	double get_pression_enceinte() const ;
	double get_radioactivité_enceinte() const ;
	double get_etat_generale_centrale() const ;
	double get_MW() const ;

	//actions

	void set_etat_enceinte_confinement(circuit_sect& c)
	void set_pression_enceinte(circuit::circuit& c)
	void set_radioactivité_enceinte(circuit::circuit& c)
	void set_etat_generale_centrale(circuit::circuit& c) 
    void set_MW(circuit::circuit& c) 
private:

	double etat_enceinte_confinement;
	double pression_enceinte;
	double radioactivité_enceinte;
	double etat_generale_centrale;
	double MW;

};

#endif