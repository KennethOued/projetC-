#include "pompe.hpp"


pompe::pompe(): regime(0.),etat(1.)
{}

pompe::pompe(double regime , double etat): regime(regime), etat(etat)
{}

double pompe::set_regime(double valeur_demandee)
{
	regime = valeur_demandee;
}

double pompe::get_etat() const
{
	return etat;
}

double pompe::get_regime() const
{
	return regime;
}

double pompe::set_etat(double valeur_demandee)
{
	etat=valeur_demandee;
}
