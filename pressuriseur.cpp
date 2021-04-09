#include "reacteur.hpp"
#include "circuitprimaire.hpp"
#include <algorithm>
#include <thread>
#include <chrono>
#include <random>
#include <functional>
#include <iostream>
#include <utility>
#include <cstdlib>


pressuriseur::pressuriseur():T_press_demande(25.),etat_press(1.),etat_resistance_press(1.),T_press_actuel(25.)
{}

/*pressuriseur::pressuriseur(double T_press_demande,double etat_press,double etat_resistance_press,
	double T_press_actuel):T_press_demande(T_press_demande),etat_press(etat_press),etat_resistance_press(etat_resistance_press),T_press_actuel(T_press_actuel)
{}*/


double pressuriseur::get_etat_press() const
{
	return etat_press;
}

double pressuriseur::get_etat_resistance_press() const
{
	return etat_resistance_press;
}

double pressuriseur::get_T_press_demande() const
{
	return T_press_demande;
}

double pressuriseur::get_T_press_actuel() const
{
	return T_press_actuel;
}

void set_etat_press(double valeur_demandee)
{
	etat_press=valeur_demandee;
}


void set_etat_resistance_press(double valeur_demandee)
{
	etat_resistance_press=valeur_demandee;
}


void set_T_press_demande(double valeur_demandee)
{
	T_press_demande=valeur_demandee;
}

void set_T_press_actuel(double valeur_demandee)
{
	T_press_actuel=valeur_demandee;
}
