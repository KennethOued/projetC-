#include "SDL2/sdl2.hpp"
#include "postesecurite.hpp"


void postesecurite::set_centrale( const centrale centrale_demandee)
{
  centrale=centrale_demandee;
}

void postesecurite::set_travailleurs( const travailleurs travailleurs_demandes)
{
  travailleurs=travaileurs_demandes;
}


void postesecurite::affichage_cadre( centrale centrale, travailleurs travailleurs)
{

  sdl2::font fonte_titre("./data/Lato-Bold.ttf", 28);
  // Pour choisir une fonte courante pour afficher du texte (pas encore mis en oeuvre pour l'affichage du texte)
  sdl2::font fonte_texte("./data/Lato-Thin.ttf", 18);

    //variables du reacteur
    reacteur react= centrale.get_reacteur();
    double etat_react_canaux=react.get_Ecanaux();
    double etat_react_barre=react.get_Ebarre();
    double etat_react_pisc=react.get_Episc();
    double etat_react_cuve=react.get_Ecuve();


    //variables du circuit primaire
    circuit_prim circuitprim= centrale.get_circuitprim();
    double etat_circuit_prim=circuitprim.get_etat_circuit();
    double etat_circuit_pompe=circuitprim.get_pompe().get_etat();
    double etat_circuit_press=circuitprim.get_pressuriseur().get_etat_press();
    double etat_circuit_resispress=circuitprim.get_pressuriseur().get_etat_resistance_press();
    double etat_circuit_injecteur_acide=reacteur.get_Ebore();


    //variables du circuit secondaire
    circuit_sec circuitsec= centrale.get_circuitsec();
    double etat_circuit_sec=circuitsec.get_etat_circuit();
    double circuit_etat_pompe=circuitsec.get_pompe().get_etat();
    double circuit_etat_generateur=circuitsec.get_etat_generateur_vapeur();
    double circuit_etat_echangeur=circuitprim.get_etat_echangeur();

    //variable de l'enceinte
    double etat_enceinte=centrale.get_etat_enceinte();

    //variable du condensateur
    double etat_condensateur=circuitsec.get_condensateur().get_etat();


    sdl2::window fenêtre("Poste de securité radio protection: Console principale", {1900, 600});

    //cadre pour le reacteur

    sdl2::texte doc1("Reacteur :\n"
                    "Etat des canaux guidant les barres de graphite :"+ etat_react_canaux+"\n"
                    "Etat des barres de graphite :"+ etat_react_barre+"\n"
                    "Etat de la piscine :"+ etat_react_pisc+"\n"
                    "Etat de la cuve :"+ etat_react_cuve, fonte_texte, fenêtre,200,400 {0xFF,0xFF,0x00,0xFF}, {0x00,0x00,0xFF,0xFF});
    doc1.at(0,0);


    //cadre pour le circuit primaire

    sdl2::texte doc2("Circuit primaire :\n"
                    "Etat du circuit primaire :"+ etat_circuit_prim+"\n"
                    "Etat de la pompe :"+ etat_circuit_pompe+"\n"
                    "Etat du pressuriseur :"+ etat_circuit_press+"\n"
                    "Etat des resistances électriques de chauffage du pressuriseur :"+ etat_circuit_resispress+"\n"
                    "Etat de l'injecteur d'acide borique :"+ etat_circuit_injecteur_acide, fonte_texte, fenêtre,200,400 {0xFF,0xFF,0x00,0xFF}, {0x00,0x00,0xFF,0xFF});
    doc2.at(0,205);

    //cadre pour le circuit secondaire

    sdl2::texte doc3("Circuit secondaire :\n"
                    "Etat du circuit secondaire :"+ etat_circuit_sec+"\n"
                    "Etat de la pompe :"+ circuit_etat_pompe+"\n"
                    "Etat du generateur de vapeur :"+ circuit_etat_generateur+"\n"
                    "Etat de l'echangeur de vapeur :"+ circuit_etat_echangeur, fonte_texte, fenêtre,200,400 {0xFF,0xFF,0x00,0xFF}, {0x00,0x00,0xFF,0xFF});
    doc3.at(0,410);

    //cadre pour l'etat de l'enceinte

    sdl2::texte doc4("Etat de l'enceinte :"+ etat_enceinte, fonte_texte, fenêtre,200,100 {0xFF,0xFF,0x00,0xFF}, {0x00,0x00,0xFF,0xFF});
    doc4.at(0,615);


    //cadre pour l'etat du condensateur

    sdl2::texte doc5("Etat du condensteur :"+ etat_condensateur, fonte_texte, fenêtre,200,100 {0xFF,0xFF,0x00,0xFF}, {0x00,0x00,0xFF,0xFF});
    doc5.at(0,820);

    //Il reste a faire les cadres pour travailleur, activité et ordinateur

    //cadre pour les commandes
    sdl2::texte doc6("Commandes: \n"
                      "T : Affiche le schema de la centrale\n"
                      "Espace: Retour à la salle de controle\n"
                      "P: demande l'évacuation de la population\n"
                      "B: Bilan de l'activité ouvrière\n"
                      "O: Intervention ouviers\n"
                      "  1: Pompe du circuit primaire\n"
                      "  2: Pompe du circuit secondaire\n"
                      "  C: Condensateur\n"
                      "  G: Générateur de vapeur\n"
                      "  B: Injecteur d'acide borique\n"
                      "  I: Circuit primaire\n"
                      "  R: Circuit secondaire\n"
                      "  P: Pressuriseur", fonte_texte, fenêtre,400,400 {0xFF,0xFF,0x00,0xFF}, {0x00,0x00,0xFF,0xFF});
    doc6.at(0,1500);

    fenêtre << doc1 << doc2 << doc3 << doc4 << doc5 << doc6
            << sdl2::flush;

    bool quitting = false;
    sdl2::event_queue queue;
    while (not quitting)
    {
        auto events = queue.pull_events();
        if (events.size() > 0)
            fenêtre << sdl2::flush;
        for ( const auto& e : events)
            if (e->kind_of_event() == sdl2::event::key)
            {
              auto& key_ev = dynamic_cast<sdl2::event_keyboard&>(*e)
              if(key_ev.ascci_code() == "t")
              {
                afficher_centrale();
              }

              if(key_ev.ascci_code() == " ")
              {
                quitting=true;
              }

              if(key_ev.ascci_code() == "p")
              {
                demande_evacuation();
              }

              if(key_ev.ascci_code() == "b")
              {
                bilan_ouvrier();
              }

              if(key_ev.ascci_code() == "o")
              {
                if(key_ev.ascci_code() == "1")
                  intervention_pompe_circuitprim();

                if(key_ev.ascci_code() == "2")
                  intervention_pompe_circuitsec();

                if(key_ev.ascci_code() == "c")
                    intervention_condensateur();

                if(key_ev.ascci_code() == "g")
                    intervention_genevap();

                if(key_ev.ascci_code() == "b")
                    intervention_acideborique();

                if(key_ev.ascci_code() == "i")
                    intervention_circuitprim();

                if(key_ev.ascci_code() == "r")
                    intervention_circuitsec();

                if(key_ev.ascci_code() == "p")
                    intervention_pressuriseur();
              }

            }

    }
}
