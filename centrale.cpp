#include "centrale.hpp"
#include<algorithm>
#include <ctime>
#include <cstdlib>


//oui signifie parametrable par lutilisateur  non signifie non parametrable

centrale::centrale():etat_enceinte(1),pression_enceinte(1),radioactivite(0.00002),etat_centrale(1),
                     production_centrale(0)
{}
centrale::centrale(double etat_enceinte,double pression_enceinte,double radioactivite,double etat_centrale,
                  double production_centrale):
                                             etat_enceinte(etat_enceinte),pression_enceinte(pression_enceinte),
                                             radioactivite(radioactivite),etat_centrale(etat_centrale),
                                             production_centrale(production_centrale)
{}

  double centrale:: get_etat_enceinte()const
  {
    return etat_enceinte;
  }

  double centrale::get_pression_enceinte()const
  {
    return pression_enceinte;
  }
  double centrale::get_radioactivite()const
  {
    return radioactivite;
  }//Radioactivité de l’enceinte de confinement à l’intérieur(non)Notez que si l’enceinte est abîmée, la radioactivité baisse dans l’enceinte (mais pas à l’extérieur!)
  double centrale::get_etat_centrale()const
  {
    return etat_centrale;
  }
  double centrale::get_production_centrale()const
  {
    return production_centrale;
  }


  void centrale::set_etat_enceinte( const double valeur_demandee)
  {
    etat_enceinte= valeur_demandee;
  }

  void centrale::set_pression_enceinte( const double valeur_demandee)
  {
    pression_enceinte=valeur_demandee;
  }

  void centrale::set_radioactivite(const double valeur_demandee)
  {
    radioactivite=valeur_demandee;
  }

  void centrale::set_etat_centrale(const double valeur_demandee)
  {
    etat_centrale=valeur_demandee;
  }

  void centrale::set_production_centrale(const double valeur_demandee)
  {
    production_centrale=valeur_demandee;
  }



  void centrale::equ_etat_enceinte()
  {
    if (pression_enceinte > 2. && pression_enceinte < 3.4 && etat_enceinte > 0.5)
    {
      if((double) std::rand() < 0.3)
      {
        etat_enceinte -=(double) (std::rand())%2. / 100.;
      }
    }
    if (pression_enceinte > 3.4 && pression_enceinte < 4.5 && etat_enceinte > 0.25)
    {
      if((double) std::rand() < 0.6)
      {
        etat_enceinte -=(double) (std::rand())%0. / 100.;
      }
    }
  }


  void centrale::equ_pression_enceinte(const circuit_prim &circuitprim, const reacteur& reacteur, const circuit_sec &circuitsec)
  {
    if ( (circuitprim.get_pression()>8 && reacteur.get_Ecuve()<1 && reacteur.get_Episc()<1) ||
         (reacteur.get_Ecuve()<0.3 && reacteur.get_Episc() < 0.4) )
    {
      pression_enceinte += (2. - reacteur.get_Ecuve() - reacteur.get_Episc()) / 23.;

    }
    if  (circuitprim.get_etat_circuit()<0.6 && circuitprim.get_pression()>12) || (circuitprim.get_etat_circuit()<0.2)
    {
      pression_enceinte += (1-circuitprim.get_etat_circuit())/30;

    }
    if (circuitsec.get_etat_generateur_vapeur()<0.9 && circuitsec.get_pression()>2)
    {
      pression_enceinte += (1-circuitsec.get_pression())/20;
      pression_enceinte =std:: min(pression_enceinte,5);

    }
    if (etat_enceinte > 0.5 && etat_enceinte < 0.6)
      {
        pression_enceinte -= (1-etat_enceinte)/(2×pression_enceinte);

      }
//À chaque tour, 30% de chance que la Penceinte baisse de 0.13 bar
    if((double) std::rand() < 0.3)
      {
        pression_enceinte -= 0.13;
      }
   }


void centrale::equ_radioactivite_enceinte(const circuit_prim & circuitprim, const reacteur& reacteur)
{
  std::srand(std::time(nullptr));
  radioactivite = (double) (std::rand())%(100./55) / 100. + 0.00002 + (1-circuitprim.get_etat_circuit())*
                  (circuitprim.get_radioactivite() / 98.98)+(1-circuitprim.get_etat_press())×10;

 if (reacteur.get_Episc() < 0.55 && reacteur.get_Rpisc()() > 3000 )
  {
     radioactivite= 1.25×radioactivite;
  }
 if (etat_enceinte < 0.9 )
  {
    radioactivite /= 1.3;
  }

 if (etat_enceinte< 0.1)
 {
   radioactivite /= 1.5
 }
}


void centrale::equ_etat_centrale(const circuit_prim & circuitprim, const reacteur& reacteur, const circuit_sec & circuitsec)
{
  etat_centrale = (reacteur.get_Ecanaux() + 2*reacteur.get_Ebarre() + 8*reacteur.get_Ecuve() +
                3*reacteur.get_Episc() + circuitprim.get_etat_pompe() + circuitsec.get_etat_pompe() +
                5*circuitprim.get_etat_echangeur() + 4*circuitsec.get_etat_generateur_vapeur() +
                circuitprim.get_pressuris().get_etat_press() + circuitprim.get_pressuris().get_etat_resistance_press() + 4*etat_enceinte +
                8*circuitprim.get_etat_circuit() + 3*circuitsec.get_etat_circuit() + reacteur.get_Ebore() +
                circuitsec.get_condensateur().get_etat()) / 44;

}

void centrale::equ_production(const circuit_sec & circuitsec, const circuit_prim & circuitprim)
{
  if (circuitsec.get_temperature_vapeur()<120 || circuitsec.get_etat_circuit()<0.22 )
  {
   production_centrale = 0;
  }

  if (circuitsec.get_temperature_vapeur() < 3000 )
  {
    production_centrale =std:: max(5.787×(circuitsec.get_temperature_vapeur()-120) + 28.118×(circuitsec.get_pression()-1)+circuitprim.get_pression(),0);
  }
  else
  {
    production_centrale = 30000;
  }

  if  ( circuitsec.get_etat_circuit() < 0.6 )
  {
    production_centrale = production_centrale * circuitsec.get_etat_circuit();
  }

  if( production_centrale > 1400 && production_centrale < 1412 )
  {
     production_centrale = 1400;
  }
}
