#ifndef DEF_PRESSURISEUR
#define DEF_PRESSURISEUR

#include <iostream>
#include "circuit_prim.hpp"

class pressuriseur:
{

	public :

	pressuriseur();
//	pressuriseur(double T_press_demande,double etat_press,double etat_resistance_press,double T_press_actuel);
	virtual ~pressuriseur();

	//predicats
	double get_etat_press() const;
	double get_etat_resistance_press() const;
	double get_T_press_demande() const;
	double get_T_press_actuel() const;

	//actions
	void set_etat_press(double valeur_demandee);
	void set_etat_resistance_press(double valeur_demandee);
	void set_T_press_demande(double valeur_demandee);
	void set_T_press_actuel(double valeur_demandee);

	private:

	double T_press_demande;
	double etat_press;
	double etat_resistance_press;
	double T_press_actuel;

};


#endif
