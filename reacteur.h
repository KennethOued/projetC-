#ifndef DEF_REACTEUR
#define DEF_REACTEUR

class reacteur
{
    public:
      reacteur();
      virtual ~reacteur();
      double get_Proportion_bar_graphi_hors_demandé() const;
      double get_Proportion_actuelle_bar_hors_demandé() const;
      double get_taux_bore_demande() const;
      double get_taux_bore_actuel() const;
      double get_etat_cuve() const;
      double get_radiation_piscine() const;
      double get_etat_piscine() const;
      double get_etat_barres_graphites() const;
      double get_etat_canaux() const;
      double get_etat_injecteur_bore() const;

      void set_Proportion_barres(const double e_barre);
      void set_taux_bore(const double taux_bore);
      void set_etat_cuve(const circuit_prim &c);
      void set_radiation_piscine(const circuit_prim &c);
      void set_etat_piscine(const circuit_prim &c);
      void set_etat_barres_graphites(const circuit_prim &c);
      void set_etat_cannaux(const circuit_prim &c);
      void set_etat_injecteur_bore(const circuit_prim &c);

    private:
    double Proportion_bar_graphi_hors_demandé;
    double Proportion_actuelle_bar_hors_demandé;
    double  taux_bore_demande;
    double  taux_bore_actuel ;
    double  etat_cuve;
    double  radiation_piscine;
    double  etat_piscine;
    double  etat_barres_graphites;
    double  etat_canaux ;
    double etat_injecteur_bore;

};

#endif
