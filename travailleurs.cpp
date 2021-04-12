#include "travailleurs.hpp"
#include <iostream>

travailleurs::travailleurs():Ouvriers.fill(ouvrier){}


vector travaileurs::requiert_travailleurs(const int nombre_ouvriers)
{
	// le tableau dynanimique retourné aura toujours comme 
	// dernier élément la valeur (1 ou 0) qui indique si 
	//des travailleurs peuvent être envoyés pour réparation
	// le reste des éléments correspond aux positions des travailleurs en bonne
	// santé et dispo.
	int val = 0;
	vector<int> tab();

	for (int i = 0; i<Ouvriers.size(); i++)
	{
		if (Ouvriers[i].get_etat() == 1 && Ouvriers[i].get_dispo()==1)
			tab.push_back(i) ;

	}
   if (tab.size() >= nombre_ouvriers)
   		val = 1;
   	tab.push_back(val) ;
   	return tab;

}

// int travaileurs::get_nb_bonne_sante() const
// {
// 	int cp = 0;
// 	for (auto ouvrier:Ouvriers)
// 	{
// 		if (ouvrier.get_etat() == 1)
// 			cp+= 1;
// 	}
// 	return cp;
// }

// int travailleurs::get_nb_dispo() const
// {
// 	int cp = 0;
// 	for (auto ouvrier:Ouvriers)
// 	{
// 		if (ouvrier.get_dispo() == 1)
// 			cp+= 1;
// 	}
// 	return cp;
// }


void travailleurs::set_dispo(const vector liste_pos,const int dispo)
{
	for (int i=0; i<liste_pos.size()-1; i++)
	{
		Ouvriers[liste_pos[i]].set_dispo() = dispo;
	}
}

void travailleurs::set_etat_travailleurs(const vector liste_pos,const int etat)
{
	for (int i=0; i<liste_pos.size()-1; i++)
	{
		Ouvriers[liste_pos[i]].set_etat() = etat;
	}
}