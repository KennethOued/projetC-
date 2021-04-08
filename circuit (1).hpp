#ifndef _NUCLEARALERTE_CIRCUIT_PRIMAIRE_HPP_
#define _NUCLEARALERTE_CIRCUIT_PRIMAIRE_HPP_
#include "pompe.hpp"
#include "centrale_base.hpp"
#include "reacteur_base.hpp"

class circuit
{
public:
    circuit(): etat_circuit(1), pompe(), pression(1), radioactivite(0), inertie(0)
    {}

    double get_etat_circuit() const;
    pompe get_pompe() const;
    double get_pression() const;
    double get_inertie() const;
    double get_radioactivite() const;

    void set_etat_circuit( const double valeur_demandee );
    void set_pompe( const pompe pompe_demandee );
    void set_pression( const double valeur_demandee );
    void set_inertie( const double valeur_demandee );
    void set_radioactivite( const double valeur_demandee );

    virtual void equ_etatcircuit();
    virtual void equ_radioactivite( const auto& a, const auto & b );
    virtual void equ_inertie_tempeaucircuit();
    virtual void equ_pression();
    virtual void equ_etatpompe();
    virtual void equ_regimepompe( const double valeur_demandee) ;


protected:
    double etat_circuit;
    pompe pompe;
    double pression;
    double radioactivite;
    double inertie;
};

#endif
