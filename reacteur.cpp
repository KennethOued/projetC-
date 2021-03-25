#include "reacteur.h"
#include "circuitprimaire.h"
#include <algorithm>
#include "time.h"
#include <stdio>
#include <cstdlib>

using namespace std;

reacteur::reacteur()
{
   Proportion_bar_graphi_hors_demandé=0.;
  Proportion_actuelle_bar_hors_demandé=0.;
  taux_bore_demande=0.47;
  taux_bore_actuel =0.47;
   etat_cuve=1.;
   radiation_piscine=0.;
   etat_piscine=1.;
   etat_barres_graphites=1.;
   etat_canaux =1.;
   etat_injecteur_bore = 1.;
}

double reacteur::get_Proportion_bar_graphi_hors_demandé() const
{
  return Proportion_bar_graphi_hors_demandé;
}
double reacteur::get_Proportion_actuelle_bar_hors_demandé() const
{
  return Proportion_actuelle_bar_hors_demandé;
}
double reacteur::get_taux_bore_demande() const
{
  return taux_bore_demande;
}
double reacteur::get_taux_bore_actuel() const
{
  return taux_bore_actuel;
}
double reacteur::get_etat_cuve() const
{
  return etat_cuve;
}
double reacteur::get_radiation_piscine() const
{
  return radiation_piscine;
}
double reacteur::get_etat_piscine() const
{
  return etat_piscine;
}
double reacteur::get_etat_barres_graphites() const
{
  return etat_barres_graphites;
}
double reacteur::get_etat_canaux() const
{
  return etat_canaux;
}
double reacteur::get_etat_injecteur_bore() const
{
  return etat_injecteur_bore;
}

void reacteur::set_Proportion_barres()
{
  Proportion_actuelle_bar_hors_demandé= get_Proportion_bar_graphi_hors_demandé();
  Proportion_bar_graphi_hors_demandé = (1-get_etat_barres_graphites())*100;

}

void reacteur::set_taux_bore(double taux_bore)
{
  taux_bore_actuel = get_taux_bore_demande();
  if (0<= taux_bore and taux_bore<=0.5)
    taux_bore_demande = taux_bore;
}
void reacteur::set_etat_cuve(circuit_prim &c)
{
  srand(time(nullptr));
  if (c.get_tempeaucircuit()>=50)
  {
    if (0.3<c.get_etat_circuit() and c.get_etat_circuit()<0.6)
    {
       if (rand()/RAND_MAX < 0.4) 
            etat_cuve = get_etat_cuve()-rand(0.02);
    }
   else if (0.2<c.get_etat_circuit() and c.get_etat_circuit()<0.3)
   {
     if (rand()/RAND_MAX < 0.4) 
            etat_cuve = get_etat_cuve()-rand(0.03);
   }
  else if (c.get_etat_circuit()<0.2)
  {
    if (rand()/RAND_MAX < 0.4) 
            etat_cuve = get_etat_cuve()-rand(0.06);
  }

  }
  else etat_cuve = get_etat_cuve();

}
void reacteur::set_radiation_piscine(circuit_prim &c)
{
  radiation_piscine = (1-get_etat_cuve())*c.get_radioactivité() + 100 + rand(45);
}
void reacteur::set_etat_piscine(double e_piscine)
{
  if (c.get_tempeaucircuit()>=50 and c.get_etat_circuit()<0.2)
  {

    if (rand()/RAND_MAX < 0.8)
      etat_piscine = get_etat_piscine()-rand(0.06);
  }
  else etat_piscine = get_etat_piscine();
}
void reacteur::set_etat_barres_graphites(circuit_prim &c)
{
  if (c.get_tempeaucircuit() >= 50 and get_Proportion_actuelle_bar_hors_demandé() >0.4))
  {
    if (0.6<get_etat_cuve() and  get_etat_cuve()<0.7) 
    {
       if (rand()/RAND_MAX < 0.4)
            etat_barres_graphites = get_etat_barres_graphites()-rand(0.03);
    }
    else if (get_etat_cuve()<0.6)
    {
       if (rand()/RAND_MAX < 0.3)
            etat_barres_graphites = get_etat_barres_graphites()-rand(0.02);
    }
  }
  else etat_barres_graphites = get_etat_barres_graphites();
}
void reacteur::set_etat_cannaux(circuit_prim &c)
{
  if (c.get_tempeaucircuit()>=50 and c.geteatechaneur()<0.5)
  {

    if (rand()/RAND_MAX < 0.5)
      etat_canaux = get_etat_canaux()-rand(0.05);
  }
  else etat_canaux = get_etat_canaux();
}
void reacteur::set_etat_injecteur_bore(circuit_prim &c)
{
  if (c.get_tempeaucircuit()>=50 and (get_etat_cuve()<0.5 and c.get_etat_circuit()<0.5))
    {

      if (rand()/RAND_MAX < 0.5)
        etat_injecteur_bore = get_etat_injecteur_bore()-rand(0.02);
    }
  else etat_injecteur_bore = get_etat_injecteur_bore();
}