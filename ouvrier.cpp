#include "ouvrier.hpp"

ouvrier::ouvrier():etat(1),dispo(True)
{}

double ouvrier::get_etat() const
{
	return etat;
}
void ouvrier::set_etat(const int etat)
{
	etat = etat;
}
bool ouvrier::get_dispo() const
{
	return dispo;
}
void ouvrier::set_dispo(bool dispo)
{
	dispo_intervenir = dispo;
}
