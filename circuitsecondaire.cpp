#include "circuit.hpp"
#include "circuitsecondaire.hpp"
#include "circuitpribase.hpp"
#include "condensateur.hpp"
#include "pompe.hpp"


#include <algorithm>

circuit_sec::circuit_sec() : circuit(),condensateur(), etat_generateur_vapeur(1.0), temperature_vapeur(25.0), debit(0.0)
{}

condensateur circuit_sec::get_condensateur() const;
{
  return condensateur;
}


double circuit_sec::get_debit() const
{
  return debit;
}

double circuit_sec::get_etatgenerateurvapeur() const
{
  return etat_generateur_vapeur;
}

double circuit_sec::get_temparaturevapeur() const
{
  return temperature_vapeur;
}

void circuit_sec::set_etatgenerateurvapeur( const double valeur_demandee )
{
  etat_generateur_vapeur=valeur_demandee;
}

void circuit_sec::set_condensateur( const condensateur condens_demande )
{
  condensateur=condens_demande;
}

void circuit_sec::set_temperaturevapeur( const double valeur_demandee )
{
  temperature_vapeur=valeur_demandee;
}

void circuit_sec::set_debit( const double valeur_demandee )
{
  debit=valeur_demandee;
}

void circuit_sec::equ_etat_circuit()
{
  std::srand(std::time(nullptr));
  double d;

  if ( temperature_vapeur>=310 )
  {
    d=std::rand();
    if (d<=0.25)
      etat_circuit-=std::rand(0.04);
  }

  if ( etat_circuit<0.5 && temperature_vapeurt> 130 )
  {
    d=std::rand();
    if (d<=0.3)
      etat_circuit-=std::rand(0.015);
  }
}

void circuit_sec::equ_etatgenerateurvapeur( const circuit_pri_base& c)
{
  if (c.get_etat_echangeur()<0.4)
  {
    d=std::rand();
    if (d<=0.25)
      etat_generateur_vapeur-=std::rand(0.03);
  }
}

void circuit_sec::equ_temperaturevapeur(const circuit_pri_base & c)
{
  temparature_vapeur=std::max(c.get_etat_echangeur()*(c.get_etat_circuit()/1.51)+26+ inertie*(inertie>3),99);
}

void circuit_sec::equ_debit()
{
  if(temperature_vapeur>3 && (etat_circuit*(condensateur.get_etat()+0.1)*etat_generateur_vapeur*pompe.get_regime()*0.85 <3))
  {
    debit=(etat_circuit*(condensateur.get_etat()+0.1))*etat_generateur_vapeur*1.3;
  }
  else
  {
    debit = (etat_circuit*(condensateur.get_etat()+0.1))*etat_generateur_vapeur*pompe.get_regime()*0.85;
  }
}


void circuit_sec::equ_pression()
{
  if(temperature_vapeur<120)
  {
    pression=1;
  }
  else
  {
    pression=std::max(1,(etat_circuit+0.1)*etat_generateur_vapeur*(pompe.get_regime()/50 +(temperature_vapeur-135)/10));
  }
}




void circuit_sec::equ_inertie(const circuit_pri_base & c, double& a)
{
  std::srand(std::time(nullptr));
  if(pompe.get_regime()<0.55+std::rand(0.15) && c.get_tempeaucircuit()>200)
  {
    inertie+=std::rand(c.get_tempeaucircuit()/100);
  }

  else if(inertie>0)
  {
    inertie=std::max(inertie-std::rand(3),0);
  }
}

void circuit_sec::equ_radioactivite(const circuit_pri_base & c, double & a )
{
  radioactivite= std::max(radioactivite,(1-c.get_etatechangeur())*c.get_radioactivite());
}


//fonctions qui modifient la pompe du circuit secondaire

void circuit_sec::equ_etatpompe()
{
  std::srand(std::time(nullptr));
  if(etat_circuit<0.6 )
  {
    d=std::rand();
    if(d<=0.3)
      pompe.set_etat( pompe.get_etat()-0.02*std::rand() );
  }
}

void circuit_sec::equ_regimepompe( const double valeur_demandee)
{
  while (0<valeur_demandee || valeur_demandee>pompe.get_etat())
	{
		std::cout<< "Entrez une nouvelle valeur du régime fonctionnement pompe" << std::endl;
		cin >> valeur_demandee;
	}
  pompe.set_regime(valeur_demandee)
}


//fonctions qui modifient le condensateur

void circuit_sec::equ_etatcondensateur()
{
  if ( condensateur.get_diff_chaleur_in_out_condensateur()>19)
  {
    d=std::rand();
    if(d<=0.4)
      condensateur.set_etat( condensateur.get_etat()-0.03*std::rand() );
  }

}

void circuit_sec::equ_regimepompecondens(const double valeur_demandee)
{
  while (0<valeur_demandee || valeur_demandee>condensateur.get_etat())
	{
		std::cout<< "Entrez une nouvelle valeur du régime pompe condensateur" << std::endl;
		cin >> valeur_demandee;
	}
  condensateur.set_regime_pompe(valeur_demandee)
}


void circuit_sec::equ_debitniveaucondensateur()
{
  condensateur.get_debit_nv_condensateur()=condensateur.get_etat()*condensateur.get_regime_pompe()*150;
}


void circuit_sec::equ_difentresortichaleur()
{
  condensateur.get_diff_chaleur_in_out_condensateur()=condensateur.get_debit_nv_condensateur()/7.5;
}
