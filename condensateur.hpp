#ifndef DEF_CONDENSATEUR
#define DEF_CONDENSATEUR

#include <iostream>


class condensateur:
{
	public:

	condensateur();
	~condensateur()= default;
	//condensateur(double etat_condensateur,double regime_pompe_condensateur,double debit_nv_condensateur, double diff_chaleur_in_out_condensateur);

	double get_etat() const;
	double get_regime_pompe() const;
	double get_debit_nv_condensateur() const;
	double get_diff_chaleur_in_out_condensateur() const;

	void set_etat( const double valeur_demandee);
	void set_regime_pompe( const double valeur_demandee);
	void set_debit_nv_condensateur( const double valeur_demandee);
	void set_diff_chaleur_in_out_condensateur( const double valeur_demandee);

	condensateur& operator = (const condensateur&) = default;

	private:

	double etat;
	double regime_pompe;
	double debit_nv_condensateur;
	double diff_chaleur_in_out_condensateur;


};



#endif
