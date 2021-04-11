#ifndef DEF_POSTE_SEC
#define DEF_POSTE_SEC

#include "centrale.hpp"
#include "travaileurs.hpp"

class postesecurite:
{
  public:
    postesecurite();
    ~postesecurite()= default;

    void set_centrale( const centrale centrale_demandee);
    void set_travailleurs( const travailleurs travailleurs_demandes);

    void affichage_cadres();

  private:
    centrale centrale;
    travailleurs travailleurs;
}

#ENDIF
