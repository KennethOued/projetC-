#include "reacteur.hpp"
#include "circuitprimaire.hpp"
#include <algorithm>
#include <ctime>
#include <cstdlib>





reacteur::reacteur(): TXgr(0.),TGreff(0.),TXb(0.47),TBeff (0.47),Ecuve(1.),Rpisc(),Episc(1.),
                      Ebarre(1.),Ecanaux (1.),Ebore(1)
{}

reacteur::reacteur(double TXgr, double TGreff, double  TXb, double  TBeff , double  Ecuve, double Rpisc,
                  double  Episc, double Ebarre, double Ecanaux, double Ebore)
                  : TXgr(TXgr), TGreff(TGreff), TXb(TXb), TBeff(TBeff), Ecuve(Ecuve), Rpisc(Rpisc), Episc(Episc),
                    Ebarre(Ebarre), Ecanaux (Ecanaux), Ebore(Ebore)
{}

  double  reacteur::get_Ebarre()const
  {
    return Ebarres_graphite;

  }

  double  reacteur::get_Ebore()const
  {
    return Ebore;

  }

  double  reacteur::get_Ecuve()const
  {
    return Ecuve;

  }

  double reacteur::get_Episc()const
  {
    return Episc;

  }

  double  reacteur::get_Ecanaux()const
  {
    return Ecanaux;

  }


  double reacteur::get_TXgr()const
  {
    return TXgr;

  }

  double reacteur::get_TGreff()const
  {
    return TGreff;

  }

  double  reacteur::get_TXb()const
  {
    return TXb;

  }

  double  reacteur::get_TBeff()const
  {
    return TBeff;

  }

  double  reacteur::get_Rpisc()const
  {
    return Rpisc;
  }

  void  reacteur::set_Ebarre( const double valeur_demandee)
  {
    Ebarres_graphite= valeur_demandee;

  }

  void reacteur::set_Ebore( const double valeur_demandee)
  {
    Ebore= valeur_demandee;

  }

  void reacteur::set_Ecuve(const double valeur_demandee)
  {
    Ecuve= valeur_demandee;

  }

  void reacteur::set_Episc(const double valeur_demandee)
  {
    Episc= valeur_demandee;

  }

  void  reacteur::set_Ecanaux(const double valeur_demandee)
  {
    Ecanaux = valeur_demandee;

  }


  void reacteur::set_TXgr(const double valeur_demandee)
  {
    TXgr= valeur_demandee;

  }

  void reacteur::set_TGreff(const double valeur_demandee)
  {
    TGreff= valeur_demandee;

  }

  void reacteur::set_TXb(const double valeur_demandee)
  {
    TXb= valeur_demandee;

  }

  void reacteur::set_TBeff(const double valeur_demandee)
  {
    TBeff= valeur_demandee;

  }

  void reacteur::set_Rpisc(const double valeur_demandee)
  {
    Rpisc= valeur_demandee);
  }


  void  reacteur::equ_Ebarre(const circuitprimaire &circuitprim )
  {
    std::srand(std::time(nullptr));
    T1 = circuitprim.get_T1();
    if (T1 >= 420 && TXgr > 0.2)
    {

      Ebarre -= (double) (std::rand())%3. / 100.;

    }
    if (T1 >= 50 && Ecanaux < 0.6 && TGreff > 0.4)
    {
      if((double) (std::rand()/RAND_MAX) < 0.3)
      {
        Ebarre -= (double) (std::rand())%2. / 100.;
      }
    }
    if (T1 >= 50 && Ecuve < 0.7 && TGreff > 0.4)
    {
      if( (double) (std::rand()/RAND_MAX) < 0.4)
      {
        Ebarre -= double (std::rand())%3. / 100.;
      }
    }
  }


  void  reacteur::equ_Ebore(const circuit_prim &circuitprim)
  {
    std::srand(std::time(nullptr));
    T1 = circuitprim.get_tempeaucircuit();
    EC1 = circuitprim.get_etat_circuit();
    if (T1 >= 50 && Ecuve < 0.5 && EC1<0.5)
    {
      if((double) std::rand()< 0.5)
      {
        Ebore -= (double) (std::rand())%2. / 100.;
      }

    }
  }

  void  reacteur::equ_Ecuve(const circuit_prim &circuitprim)
  {
    std::srand(std::time(nullptr));
    T1 = circuitprim.get_tempeaucircuit();
    EC1 = circuitprim.get_etat_circuit();
    if (T1 >= 50 && EC1 < 0.2)
    {
      if((double) std::rand() < 0.8)
      {
        Ecuve -= (double) (std::rand())%6. / 100.;
      }
    }
    else if (T1 >= 50 && EC1 < 0.3)
    {
      if((double) std::rand() < 0.3)
      {
        Ecuve -=(double) (std::rand())%3. / 100.;
      }
    }
    else if (T1 >= 50 && EC1 < 0.6)
    {
      if( (double) std::rand() < 0.4)
      {
        Ecuve -= double (std::rand())%2. / 100.;
      }
    }
  }

  void reacteur::equ_Episc(const circuit_prim &circuitprim)
  {
    std::srand(std::time(nullptr));
    T1 = circuitprim.get_tempeaucircuit();
    EC1 = circuitprim.get_etat_circuit();
    if (T1 >= 50 && EC1 < 0.2)
    {
      if((double) std::rand() < 0.8)
      {
        Episc -= (double) (std::rand())%6. / 100.;
      }
    }
  }

  void  reacteur::equ_Ecanaux(const circuit_prim &circuitprim)
  {
    std::srand(std::time(nullptr));
    T1 = circuitprim.get_tempeaucircuit();

    if (T1 >= 50 && Ecuve < 0.5)
    {
      if((double) std::rand() < 0.5)
      {
        Ecanaux -= (double) (std::rand())%5. / 100.;
      }
    }
  }

void reacteur::equ_Rpisc(const circuit_prim &circuitprim)
{
  std::srand(std::time(nullptr));
  R1 = circuitprim.get_radioactivite();
  Rpisc = (1. - Ecuve)*R1 + 100. + (double) (std::rand())%45.;

}

void reacteur::equat_barres(const double valeur_demandee)
{
  while (1 >valeur_demandee || valeur_demandee<(1.-Ebarre))
	{
		std::cout<< "Entrez une nouvelle valeur de la proportion des barres de graphite" << std::endl;
		cin >> valeur_demandee;
	}

  TGreff = TXgr;
  TXgr = valeur_demandee;

}

void reacteur::increment_ou_decrement_barres()
{
  if (TGreff <  TXgr)
  {
    TGreff += 0.01;

  }
  if (TGreff > TXgr)
  {
    TGreff -= 0.01;

  }
}

void equ_bore_demande(const double valeur_demandee)
{
  while (0.5 >valeur_demandee || valeur_demandee<0)
	{
		std::cout<< "Entrez une nouvelle valeur du taux de bore" << std::endl;
		cin >> valeur_demandee;
	}

  TBeff = TXb;
  TXb = valeur_demandee;

}

void increment_ou_decrement_bore()
{
  if (TXb > TBeff)
  {
    TBeff += 0.01;

  }
  if (TXbe < TBeff)
  {
    TBeff -= 0.01;

  }
}
