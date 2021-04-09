#ifndef DEF_REACTEUR
#define DEF_REACTEUR

/**
 * @brief      Cette classe décrit le reacteur *
 *
 * Le reacteur est caractérisée par la proportion des barres de graphite hors de l’eau demandé,
 * la proportion actuelle des barres hors de l’eau demandé, le taux de bore demandé dans l’eau
 * du circuit,le taux de bore actuel dans l’eau du circuit,l'état de la cuve,la radiation de la piscine(becquerel),
 * l'état de la piscine, l'état des barres de graphite,l'état des canaux guidant les barres et
 * l'état injecteurs d’acide borique
 */

class reacteur
{
    public:
      /**
      * @brief      Constructeur par défaut
      *
      * La proportion des barres de graphite hors de l’eau demandé vaut 0.la proportion actuelle des barres hors de l’eau
      * demandé est à zéro,le taux de bore demandé dans l’eau du circuit vaut 0.47, le taux de bore actuel dans l’eau du
      * circuit vaut 0.47, l'état de la cuve vaut 1,la radiation de la piscine(becquerel) n'a pas de valeur intiale,
      * l'état de la piscine vaut 1, l'état des barres de graphite vaut 1,l'état des canaux guidant les barres vaut 1 et
      * l'état injecteurs d’acide borique est égale à 1
      */

        reacteur();
        reacteur( double TXgr, double TGreff, double  TXb, double  TBeff , double  Ecuve, double Rpisc,
                  double  Episc, double Ebarre, double Ecanaux, double Ebore  )

      /**
     * @brief      Obtenir l'état des barres graphiques.
     *
     * @return     L'état des barres de graphite.
     */
        double  get_Ebarre()const;

      /**
     * @brief      Obtenir l'état injecteurs d’acide borique.
     *
     * @return     L'état injecteurs d’acide borique.
     */
        double  get_Ebore()const;

      /**
     * @brief      Obtenir l'état de la cuve.
     *
     * @return     L'état de la cuve.
     */
        double  get_Ecuve()const;

      /**
     * @brief      Obtenir l'état de la piscine.
     *
     * @return     L'état de la piscine.
     */
        double get_Episc()const;

      /**
     * @brief      Obtenir l'état des canaux.
     *
     * @return     L'état des canauxe.
     */
        double  get_Ecanaux()const;

      /**
     * @brief      Obtenir la proportion des barres de graphite hors de l’eau demandé.
     *
     * @return     La proportion des barres de graphite hors de l’eau demandé.
     */
        double get_TXgr()const;

      /**
     * @brief      Obtenir la proportion actuelle des barres hors de l’eau.
     *
     * @return     La proportion actuelle des barres hors de l’eau.
     */
        double get_TGreff()const;

      /**
     * @brief      Obtenir le taux de bore demandé dans l’eau du circuit.
     *
     * @return     Le taux de bore demandé dans l’eau du circuit.
     */
        double  get_TXb()const;

      /**
     * @brief      Obtenir le taux de bore actuel dans l’eau.
     *
     * @return     Le taux de bore actuel dans l’eau.
     */
        double  get_TBeff()const ;

      /**
     * @brief      Obtenir la radiation de la piscine.
     *
     * @return     La radiation de la piscine.
     */
        double  get_Rpisc()const;



        void set_Ebarre( const double valeur_demandee);

        void set_Ebore( const double valeur_demandee);

        void set_Ecuve(const double valeur_demandee);

        void set_Episc(const double valeur_demandee);

        void  set_Ecanaux(const double valeur_demandee);

        void set_TXgr(const double valeur_demandee);

        void set_TGreff(const double valeur_demandee);

        void set_TXb(const double valeur_demandee);

        void set_TBeff(const double valeur_demandee);

        void set_Rpisc(const double valeur_demandee);

        /**
         * @brief      Permet d'ajuster l'état des barres graphiques
         *
         *  Ma formule mathématique : - Si la température de l'eau dans le circuit >= 420 et
         *                              la proportion des barres de graphite hors de l’eau demandé > 0.2 alors
         *                                      etat_barres_graphite = RND(0.03)
         *                             -
         *
         * @param[in]  circuitprimaire &circuitprim  Le circuit primaire
         *
         * @return     La valeur effective obtenue
         */

        void  equ_Ebarre(const circuitprimaire &circuitprim );

        void  equ_Ebore(const circuitprimaire &circuitprim);


        void  equ_Ecuve(const circuitprimaire &circuitprim);


        void equ_Episc(const circuitprimaire &circuitprim);


        void  equ_Ecanaux(const circuitprimaire &circuitprim);

        void equ_Rpisc(const circuitprimaire &circuitprim);

        void equ_barres(const double valeur_demandee);

        void increment_ou_decrement_barres();

        void equ_bore(const double valeur_demandee);

        void increment_ou_decrement_bore();





    private:
        double TXgr;
        double TGreff;
        double  TXb ;
        double  TBeff ;
        double  Ecuve;
        double Rpisc;
        double  Episc;
        double Ebarre;
        double Ecanaux;
        double Ebore;


};

#endif
