#include "circuitprimaire.hpp"
#include "circuitsecondaire.hpp"
#include <algorithm>
#include <ctime>
#include <cstdlib>


circuit_prim::circuit_prim() : circuit(),barrecontr(),pressuriseur(), etat_echangeur(1), temperature_eau_circuit(25.0)
{}
//circuit_prim::circuit_prim( double etat_circuit, pompe pomp, double pression, double debit, double inertie, double radioactivite,pressuriseur pres, double etat_echangeur ) : circuit(etat_circuit,pomp, debit, inertie, radioactivite),pressuris(pres),etat_echangeur(etat_echangeur),pression(pression),temperature_eau_circuit(temperature_eau_circuit)
//{}


double circuit_prim::get_etat_echangeur() const
{
  return etat_echangeur;
}


pressuriseur circuit_prim::get_pressuris() const
{
  return pressuriseur;
}

double circuit_prim::get_tempeaucircuit() const
{
  return temperature_eau_circuit;
}

double circuit_prim::get_debit() const
{
  return debit;
}



void circuit_prim::set_etat_echangeur( const double valeur_demandee )
{
  etat_echangeur=valeur_demandee;
}

void circuit_prim::set_pressuris( const pressuriseur pressuris_demandee )
{
  pressuriseur=pressuris_demandee;
}
void circuit_prim::set_tempeaucircuit( const double valeur_demandee )
{
  temperature_eau_circuit=valeur_demandee;
}

void circuit_prim::set_debit( const double valeur_demandee )
{
  debit=valeur_demandee;
}





void circuit_prim::equ_etat_circuit()
{
  std::srand(std::time(nullptr));
  double d;

  if ( temperature_eau_circuit>=420 )
    etat_circuit-=std::rand(0.02);

  if ( temperature_eau_circuit>=40*pression )
    etat_circuit-=std::rand(0.03);

  if ( temperature_eau_circuit>=50 && pression>10 )
  {
    d=std::rand();
    if (d<=0.2)
      etat_circuit-=std::rand(0.02);
  }

  if(temperature_eau_circuit>=50 && etat_echangeur<0.6)
  {
    d=std::rand();
    if (d<=0.3)
      etat_circuit-=std::rand(0.015);
  }

}

void circuit_prim::equ_etat_echangeur()
{
  if (temperature_eau_circuit>=50 && etat_circuit<0.5)
  {
    d=std::rand();
    if (d<=0.4)
      etat_echangeur-=std::rand(0.04);
  }

}

void circuit_prim::equ_pression()
{
  pression= std::max(((pressuriseur.get_T_press_actuel()-25)/3.24) + ((temperature_eau_circuit-100)/83.3)*(etat_circuit+0.1)*(etat_echangeur+0.0),1);
}


void circuit_prim::equ_debit( const reacteur& reacteur)
{
  debit= etat_circuit*reacteur.get_Ecuve()*pompe.get_regime_pompe()*90;
}


void circuit_prim::equ_inertie(const circuitsecondaire_base & circuitsec, const reacteur& reacteur)
{
  std::srand(std::time(nullptr));
  if(etat_echangeur<50 && reacteur.get_TBeff()<25 && reacteur.get_TGreff()<50)
  {
    inertie+=std::rand(26);
  }

  else if(circuitsec.get_temperaturevapeur()<temperature_eau_circuit)
  {
    inertie+=(circuitsec.get_temperaturevapeur()-temperature_eau_circuit)/3;
  }

  else
    inertie=std::max(0,inertie-std::rand(16));
}


void circuit_prim::equ_tempeaucircuit( const reacteur& reacteur )
{
  temperature_eau_circuit= std::max(25,((0.5-reacteur.get_TBeff())/0.5)*(645*reacteur.get_TGreff() - 140*debit/(90 + 2*pression)) + 26+inertie;
}


void circuit_prim::equ_radioactivite( const centrale_base& centr, const reacteur& reacteur )
{
  std::srand(std::time(nullptr));
  radioactivite= 98*(debit+1)+90*std::rand+(0.5-reacteur.get_TBeff())*(centr.get_prodcentr()+0.1)*6.54;
}

//fonctions qui modifient la pompe du circuit primaire

void circuit_prim::equ_etatpompe()
{
  std::srand(std::time(nullptr));
  if(temperature_eau_circuit>=50 && etat_circuit<0.5)
  {
    d=std::rand();
    if(d<=0.5)
      pompe.set_etat( pompe.get_etat()-0.03*std::rand() );
  }

}

void circuit_prim::equ_regimepompe(double valeur_demandee)
{
  while (0<valeur_demandee || valeur_demandee>pompe.get_etat())
	{
		std::cout<< "Entrez une nouvelle valeur du régime fonctionnement pompe" << std::endl;
		cin >> valeur_demandee;
	}
  pompe.set_regime(valeur_demandee)
}


//fonction de pressuriseur

void circuit_prim::equ_etat_press()
{
	 std::srand(std::time(nullptr));
	 double T1 = temperature_eau_circuit;
	 double P1 = pression;
	 if (T1>=40*P1 || T1>=420)
	 {
	 	 if((double) std::rand() < 0.3)
	 	 {
	 	 	pressuriseur.set_etat_press(pressuriseur.get_etat_press()-double (std::rand())%2. / 100.);
	 	 }
	 }

}
void circuit_prim::equ_etat_resistance_press()
{
	 std::srand(std::time(nullptr));
	 double T1 = temperature_eau_circuit;
	 double P1 = pression;
	 if (T1>=40*P1 || T1>=420)
	 {
	 	 if((double) std::rand() < 0.3)
	 	 {
	 	 	pressuriseur.set_etat_resistance_press(pressuriseur.get_etat_resistance_press()- double (std::rand())%2. / 100.);
	 	 }
	 }
	 else if (T1>=50 && pressuriseur.get_etat_press()<0.5)
	 {
	 	if((double) std::rand() < 0.8)
	 	 {
	 	 	pressuriseur.set_etat_resistance_press(pressuriseur.get_etat_resistance_press()- double (std::rand())%3. / 100.)
	 	 }
	 }
}

void circuit_prim::equ_T_press_demande(double temp_demande)
{
	while (25 >temp_demande || temp_demande>100*(pressuriseur.get_etat_press() + pressuriseur.get_etat_resistance_press()))
	{
		std::cout<< "Entrez une nouvelle valeur de la température" << std::endl;
		cin >> temp_demande;
	}
	pressuriseur.set_T_press_actuel( pressuriseur.get_T_press_demande() );
	pressuriseur.set_T_press_demande( temp_demande );
}

void circuit_prim::decrement_increment_pression()
{
	if (pressuriseur.get_T_press_demande()<pressuriseur.get_T_press_actuel())
		pressuriseur.set_T_press_actuel(pressuriseur.get_T_press_actuel()-1);
	else if (pressuriseur.get_T_press_demande()>pressuriseur.get_T_press_actuel())
		pressuriseur.set_T_press_actuel(pressuriseur.get_T_press_actuel()+1);
}
