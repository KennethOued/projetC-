#ifndef _NUCLEARALERT_TRAVAILLEURS_HPP_
#define _NUCLEARALERT_TRAVAILLEURS_HPP_

#include <array>
#include "ouvrier.hpp"
using namespace std 

const size_t taille(145);
class travailleurs
{
public:
	travailleurs();
	

	bool requiert_travailleurs(const int nombre_ouvriers);
	// chaque organe est representé par un chiffre
	// renvoie true s'il y'a assez d'ouvriers en état de travailler
	void set_dispo(const int nombre_ouvriers,const int x_depart,const int dispo);
	int get_nb_dispo() const;
	int get_nb_bonne_sante() const;
	void set_etat_travailleurs(const int nombre_ouvriers,const int x_depart,const int etat);

protected:

array<ouvrier,taille> Ouvriers;
	// vector<ouvrier> Ouvriers; // ouvriers free pour travailler
	//
};

#endif