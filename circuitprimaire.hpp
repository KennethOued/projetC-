#ifndef DEF_CIRCUIT_PRIMAIRE
#define DEF_CIRCUIT_PRIMAIRE

  #include <iostream>
  #include "circuit.hpp"//pompe est include dans circuit donc pas besoin decrire encore #include<pompe.hpp>
  #include"pressuriseur.hpp"
  #include"reacteur.hpp"
  #include"centrale_base.hpp"


  class circuit_prim : public circuit
  {
      public:
        circuit_prim();
        ~circuit_prim()= default;
        //circuit_prim( double etat_circuit, pompe pomp, double pression, double debit, double inertie, double temperature_eau_circuit, double radioactivite, double etat_press, double etat_resist, double etat_echangeur, double temperature_pressuriseur_demande, double temperature_pressuriseur_actuel);

        //les fonctions qui recuperent et modifient les variables simples(non objet) de notre classe circuit primaire

        double get_etat_echangeur() const;
        pressuriseur get_pressuris() const;
        double get_tempeaucircuit() const;
        double get_debit() const;

        void set_etat_echangeur( const double valeur_demandee );
        void set_pressuris( const pressuriseur pressuris_demande );
        void set_tempeaucircuit( const double valeur_demandee );
        void set_debit( const double valeur_demandee );

       //equations sur le circuit primaire

       void equ_etat_echangeur();
       void equ_debit( const reacteur& reacteur);
       void equ_tempeaucircuit( const reacteur& reacteur );

       //equations sur la pompe du circuit primaire

       void equ_regimepompe(double valeur_demandee);

       //equation sur le pressuriseur du circuit primaire

       void equ_etat_press();
       void equ_etat_resistance_press();
       void equ_T_press_demande(double temp_demande);
       void decrement_increment_pression();

       circuit_prim& operator = (const circuit_prim&) = default;
       
      private:
        pressuriseur pressuriseur;
        double temperature_eau_circuit;
        double etat_echangeur;
        double debit;
  };

#endif
