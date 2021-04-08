#include "condensateur.hpp"
#include <algorithm>
#include <ctime>
#include <cstdlib>

condensateur::condensateur():etat(1.),regime_pompe(0.),debit_nv_condensateur(0.),diff_chaleur_in_out_condensateur(0.)

/*condensateur::condensateur(double etat_condensateur,double regime_pompe_condensateur,double debit_nv_condensateur, double diff_chaleur_in_out_condensateur):
						etat_condensateur(etat_condensateur),regime_pompe_condensateur(regime_pompe_condensateur),debit_nv_condensateur(debit_nv_condensateur),
						diff_chaleur_in_out_condensateur(diff_chaleur_in_out_condensateur)*/



	double condensateur::get_etat() const
	{
		return etat_condensateur;
	}
	double condensateur::get_regime_pompe() const
	{
		return regime_pompe;
	}
	double condensateur::get_debit_nv_condensateur() const
	{
		return debit_nv_condensateur;
	}
	double condensateur::get_diff_chaleur_in_out_condensateur() const
	{
		return diff_chaleur_in_out_condensateur;
	}


	void condensateur::set_etat( const double valeur_demandee)
	{
		etat=valeur_demandee;
	}


	void condensateur::set_regime_pompe(const double valeur_demandee)
	{
		regime_pompe=valeur_demandee;
	}


	void condensateur::set_debit_nv_condensateur( const double valeur_demandee)
	{
		debit_nv_condensateur = valeur_demandee;
	}


	void condensateur::set_diff_chaleur_in_out_condensateur(const double valeur_demandee)
	{
		diff_chaleur_in_out_condensateur = valeur_demandee;
	}
