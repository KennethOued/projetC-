#include "ouvrier.hpp"

ouvrier::ouvrier():etat(1),dispo(1)
{}

int ouvrier::get_etat() const
{
	return etat;
}
void ouvrier::set_etat(const int etat)
{
	etat = etat;
}
int ouvrier::get_dispo() const
{
	return dispo;
}
void ouvrier::set_dispo(const int dispo)
{
	dispo = dispo;
}
