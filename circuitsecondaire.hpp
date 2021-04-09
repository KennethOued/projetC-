#ifndef DEF_CIRCUIT_SECONDAIRE
#define DEF_CIRCUIT_SECONDAIRE


  #include <iostream>
  #include "circuit.hpp"
  #include "condensateur.hpp"
  #include"pompe.hpp"


  class circuit_sec : public circuit
  {
      public:
        circuit_sec();

        //les fonctions qui recuperent et modifient les variables simples(non objet) de notre classe circuit secondaire

        double get_etat_generateur_vapeur() const;
        condensateur get_condensateur() const;
        double get_temperature_vapeur () const;
        double get_debit() const;

        void set_etat_generateur_vapeur( const double valeur_demandee );
        void set_condensateur( const condensateur condens_demandee );
        void set_temperature_vapeur( const double valeur_demandee );
        void set_debit( const double valeur_demandee );

         //equations sur le circuit secondaire
        void equ_etat_generateur_vapeur( const circuit_pri_base& c);
        void equ_temperaturevapeur( const circuit_pri_base& c);
        void equ_debit()

        //equations condensateur du circuit secondaire
        void equ_etat_condensateur();
        void equ_regimepompecondens(const double valeur_demandee);
        void equ_debitniveaucondensateur();
        void equ_difentresortichaleur();



      private:
        double etat_generateur_vapeur;
        condensateur condensateur;
        double temperature_vapeur;
        double debit;

};

#endif
