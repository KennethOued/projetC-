#ifndef _PROJET_POMPE_HPP_
#define _PROJET_POMPE_HPP_


/**
 * @brief      Cette classe décrit une pompe du circuit primaire ou secondaire *
 *
 * La pompe est caractérisée par son rendement et son état. Le rendement peut être
 * limité par l'état de la pompe
 */
class pompe
{
  public:
    /**
     * @brief      Constructeur par défaut
     *
     * L'état initial de la pompe vaut 1. et son rendement est à zéro.
     */
    pompe();

    /**
     * @brief      Permet d'ajuster le rendement de la pompe
     *
     *  Ma formule mathématique : \f$x_{i} = \frac{i+1}{2}\f$
     *
     *  Et voici un lien sur un attribut :
     *
     *  voir #rendement
     *
     * @param[in]  valeur_demandee  La valeur demandée
     *
     * @return     La valeur effective obtenue (qui dépend de l'état de la pompe)
     */
    double set_regime(double valeur_demandee);

    double set_etat(double valeur_demandee);

    /**
     * @brief      Gets the state.
     *
     * @return     The state.
     */
    double get_etat() const;
    double get_regime() const;

  private:
    /** Rendement de la pompe */
    double regime;

    /** Etat de la pompe */
    double etat;
};

#endif
