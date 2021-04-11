#include "SDL2/sdl2.hpp"
#include "salleDeControle.hpp"
#include "centrale.hpp"
#include "reacteur.hpp"
#include "circuitprimaire.hpp"
#include "circuitsecondaire.hpp"
#include "condensateur.hpp"
#include "circuit.hpp"
#include "pompe.hpp"
#include <iostream>
#include <string>

#define WINDOW_WIDTH 1300
#define WINDOW_HEIGHT  650

salleDeControle::salleDeControle() : centrale()
{}

void display_and_run(sdl2::window fenêtre)
{
	double prod = central.get_production_centrale(); // production electrique
	std::string prod_electrique = std::to_string(prod); //double en string
 	
 	//le taux de bore dans la piscine
	reacteur react = centrale.get_reacteur();
	double taux_b = react.get_taux_bore_actuel();
	std::string taux_bore = std::to_string(taux_b);

	//la pression de confinement
	double pression = central.get_pression_enceinte();
	std::string pression_enceinte = std::to_string(pression);

	//la pression subit par l’enceinte de confinement
	double etat_b = react.get_etat_barre();
	std::string etat_barre = std::to_string(etat_b);

	//Pour le circuit primaire
	circuit_prim cuicuitprimaire = central.get_circuit_prim();
	pompe pompe1 = circuitprimaire.get_pompe();
	double r_1 = pompe1.get_regime();
	std::string rendement_1 = std::to_string(r_1);
	double t_1 = circuitprimaire.get_tempeaucircuit();
	std::string temperature_1 = std::to_string(t_1);
	circuit circuit_1 = circuitprimaire.get_circuit();
	double d_1 = circuit_1.get_debit();
	std::string debit_1 = std::to_string(d_1);
	double p_1 = circuit_1.get_pression();
	std::string pression_1 = std::to_string(p_1);
	double rd_1 = circuit_1.get_radioactivie();
	std::string radioactivite_1 = std::to_string(rd_1);

	//Pour le circuit secondaire
	circuit_sec cuicuitsecondaire = central.get_circuit_sec();
	pompe pompe2 = circuitsecondaire.get_pompe();
	double r_2 = pompe2.get_regime();
	std::string rendement_2 = std::to_string(r_2);
	double t_2 = circuitsecondaire.get_tempeaucircuit();
	std::string temperature_2 = std::to_string(t_2);
	circuit circuit_2 = circuitsecondaire.get_circuit();
	double d_2 = circuit_2.get_debit_eau();
	std::string debit_2 = std::to_string(d_2);
	double p_2 = circuit_2.get_pression();
	std::string pression_2 = std::to_string(p_2);
	double rd_2 = circuit_2.get_radioactivite();
	std::string radioactivite_2 = std::to_string(rd_2);

	//Pour le systeme de refroidissement
	condensateur condensateur = circuitsecondaire.get_condensateur();
	pompe pompe_c = condensateur.get_pompe();
	double r_c = pompe_c.get_regime();
	std::string rendement_c = std::to_string(r_c);
	double d_c = condensateur.get_debit_nv_condensateur();
	std::string debit_c = std::to_string(d_c);
	double t_vap = circuitsecondaire.get_temp_vap();
	double t_eau = circuitprimaire.get_tempeaucircuit();
	std::string t_diff = std::to_string(t_vap - t_eau);



	sdl2::font fonte_titre("./data/Lato-Bold.ttf", 28);
    // Pour choisir une fonte courante pour afficher du texte (pas encore mis en oeuvre pour l'affichage du texte)
    sdl2::font fonte_texte("./data/Lato-Thin.ttf", 18);

    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Console principale", {WINDOW_WIDTH, WINDOW_HEIGHT});

    
    
    // Affichage d'un titre
    //sdl2::texte titre1 ("Commandes de la salle de contrôle", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    //titre1.at(10,10);

    

    //Cadre ordres provenant du dispatching national

    fenêtre << sdl2::rectangle({50,50}, {1100,50}, {0xFF,0xFF,0xFF,0xFF}, true);

    sdl2::texte phrase1("Les ordres: ", fonte_texte, fenêtre, {0,0,0,0});//A completer
    phrase1.at(60,60);

    //Cadre affichant la production électrique (en MW)

    fenêtre << sdl2::rectangle({40,110}, {300,50}, {0xFF,0xFF,0xFF,0xFF}, true);

    sdl2::texte phrase2("Prod. Electrique(MW): " + prod_electrique, fonte_texte, fenêtre, {0,0,0,0});//A completer
    phrase2.at(50,120);

    //Cadre affichant le taux de bore dans la piscine
    fenêtre << sdl2::rectangle({350,110}, {250,50}, {0xFF,0xFF,0xFF,0xFF}, true);

    sdl2::texte phrase3("Taux de Bore: " + taux_bore, fonte_texte, fenêtre, {0,0,0,0});//A completer
    phrase3.at(360,120);

    //Un cadre affichant la pression subit par l’enceinte de confinement
    fenêtre << sdl2::rectangle({610,110}, {300,50}, {0xFF,0xFF,0xFF,0xFF}, true);

    sdl2::texte phrase8("Pression.confinement: " + pression_enceinte, fonte_texte, fenêtre, {0,0,0,0});//A completer
    phrase8.at(620,120);

    //un cadre affichant l’état des barres de graphite
    fenêtre << sdl2::rectangle({920,110}, {350,50}, {0xFF,0xFF,0xFF,0xFF}, true);

    sdl2::texte phrase9("Etat barres de graphes: " + etat_barre, fonte_texte, fenêtre, {0,0,0,0});//A completer
    phrase9.at(930,120);

    //Un cadre pour le circuit primaire affichant:
    fenêtre << sdl2::rectangle({40,170}, {406,200}, {0xFF,0xFF,0xFF,0xFF}, true);

    sdl2::texte phrase4("CIRCUIT PRIMAIRE ", fonte_titre, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase4.at(50,180);

    sdl2::texte phrase10("rendement pompe(%): " + rendement_1, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase10.at(50,210);

    sdl2::texte phrase11("température(°C): " + temperature_1, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase11.at(50,230);

    sdl2::texte phrase12("débit d’eau (en m3s-1): " + debit_1, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase12.at(50,250);

    sdl2::texte phrase13("pression(en bar): " + pression_1, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase13.at(50,270);

    sdl2::texte phrase14("radioactivité(en becquerel): " + radioactivite_1, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase14.at(50,290);
    //Un cadre pour le circuit secondaire affichant:
    fenêtre << sdl2::rectangle({456,170}, {406,200}, {0xFF,0xFF,0xFF,0xFF}, true);

    sdl2::texte phrase5("CIRCUIT SECONDAIRE ", fonte_titre, fenêtre, {0,0,0,0});//A completer
    phrase5.at(466,180);

    sdl2::texte phrase15("rendement pompe(%): " + rendement_2, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase15.at(466,210);

    sdl2::texte phrase16("température vapeur(°C): " + temperature_2, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase16.at(466,230);

    sdl2::texte phrase17("débit d’eau (en m3s-1): " + debit_2, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase17.at(466,250);

    sdl2::texte phrase18("pression(en bar): " + pression_2, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase18.at(466,270);

    sdl2::texte phrase19("radioactivité(en becquerel): " + radioactivite_2, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase19.at(466,290);

    //Un cadre réservé au système de refroidissement
    fenêtre << sdl2::rectangle({872,170}, {406,200}, {0xFF,0xFF,0xFF,0xFF}, true);

    sdl2::texte phrase7("SYSTEME REFROIDISSEMENT ", fonte_titre, fenêtre, {0,0,0,0});//A completer
    phrase7.at(882,180);

    sdl2::texte phrase20("rendement pompe(%): " + rendement_c, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase20.at(882,210);

    sdl2::texte phrase21("La différence de température(°C): " + t_diff, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase21.at(882,230);

    sdl2::texte phrase22("débit d’eau (en m3s-1): " + debit_c, fonte_texte, fenêtre, {0x00,0x00,0x00,0x00});//A completer
    phrase22.at(882,250);

    //Un cadre réservé au système de sécurité
    fenêtre << sdl2::rectangle({40,380}, {500,200}, {0xFF,0xFF,0xFF,0xFF}, true);

    sdl2::texte phrase6("Signalements: ", fonte_texte, fenêtre, {0,0,0,0});//A completer
    phrase6.at(50,390);

    //Touches 
    fenêtre << sdl2::rectangle({560,380}, {50,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche1("1", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche1.at(570,390);

    fenêtre << sdl2::rectangle({620,380}, {50,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche2("2", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche2.at(630,390);

    fenêtre << sdl2::rectangle({680,380}, {50,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche3("B", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche3.at(690,390);

    fenêtre << sdl2::rectangle({740,380}, {50,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche4("T", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche4.at(750,390);

    fenêtre << sdl2::rectangle({800,380}, {50,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche5("P", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche5.at(810,390);

    fenêtre << sdl2::rectangle({860,380}, {50,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche6("R", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche6.at(870,390);

    fenêtre << sdl2::rectangle({920,380}, {50,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche7("U", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche7.at(930,390);

    fenêtre << sdl2::rectangle({980,380}, {50,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche8("S", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche8.at(990,390);

    fenêtre << sdl2::rectangle({570,450}, {100,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche9("Tab", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche9.at(580,460);

    fenêtre << sdl2::rectangle({690,450}, {150,50}, {0xFF,0xFF,0xFF,0xFF}, true);
    sdl2::texte touche10("Espace", fonte_titre, fenêtre, {0x00,0xFF,0xFF,0xFF});
    touche10.at(700,460);


    fenêtre << titre1 << phrase1<< phrase2 << phrase3 << phrase4 
            << phrase5<< phrase6 << phrase7 << phrase8 << phrase9<< phrase10<< phrase11
            << phrase12<< phrase13<< phrase14<< phrase15<< phrase16<< phrase17<< phrase18<< phrase19
            << phrase20<< phrase21<< phrase22 << touche1<< touche2<< touche3<< touche4<< touche5<<touche6<<touche7<<touche8
            <<touche9 <<touche10
            << sdl2::flush;
    
    
}

//Rendement de la pompe du circuit primaire
void action_touche_1(sdl2::window fenêtre){

	circuit_prim circuitprimaire = centrale.get_circuit_prim();
	pompe pome_1 = circuitprimaire.get_pompe();
	double r_p = pompe_1.get_regime();
	std::string regime_p = std::to_string(r_p)

	sdl2::font fonte_titre("./data/Lato-Bold.ttf", 28);
    // Pour choisir une fonte courante pour afficher du texte (pas encore mis en oeuvre pour l'affichage du texte)
    sdl2::font fonte_texte("./data/Lato-Thin.ttf", 18);

	bool quitting = false;
    sdl2::event_queue queue;
    auto events = queue.pull_events();

    while (not quitting)
    {
    	fenêtre << sdl2::rectangle({570,510}, {500,150}, {0xFF,0xFF,0xFF,0xFF}, true);
    	sdl2::texte phrase("Rendement pompe du circuit primaire :", fonte_texte, fenêtre, {0x00,0xFF,0xFF,0xFF});
    	phrase.at(580,520);

    	sdl2::texte rendement(regime_p, fonte_texte, fenêtre, {0x00,0xFF,0xFF,0xFF});
    	rendement.at(590,550);

    // Charge une image fleche
    	sdl2::image fleche("data/fleche_haut_bas.png", fenêtre);
    	fleche.at(610,550);

    	sdl2::texte phrase("Q pour fermer", fonte_texte, fenêtre, {0x00,0xFF,0xFF,0xFF});
    	phrase.at(580,640);

    	fenêtre << phrase << rendement << fleche
            << sdl2::flush;
    	for ( const auto& e : events)
    	{
    		if (e->kind_of_event() == sdl2::event::key)
    		{
    			auto& key_ev = dynamic_cast<sdl2::event_keyboard&>(*e);
    			if (key_ev.type_of_event() == sdl2::event::key_down)
    			{
                	switch(key_ev.code())
                	{
                		case sdl2::event_keyboard::pagedown:
                		circuitprimaire.equ_regimepompe(-0.01);
                		break;
                		case sdl2::event_keyboard::pageup:
                		circuitprimaire.equ_regimepompe(0.01);
                		break;
                		default:
                        if (key_ev.ascci_code() == 'q')
                        {
                            quitting = true;
                        }
                	}

    			}
    		}
    	}
	}



}
// Rendement de la pompe du circuit secondaire
void action_touche_2(sdl2::window fenêtre){

	circuit_sec circuitsecondaire = centrale.get_circuit_prim();
	pompe pome_2 = circuitsecondaire.get_pompe();
	double r_p = pompe_2.get_regime();
	std::string regime_p = std::to_string(r_p)

	sdl2::font fonte_titre("./data/Lato-Bold.ttf", 28);
    // Pour choisir une fonte courante pour afficher du texte (pas encore mis en oeuvre pour l'affichage du texte)
    sdl2::font fonte_texte("./data/Lato-Thin.ttf", 18);

	bool quitting = false;
    sdl2::event_queue queue;
    auto events = queue.pull_events();

    while (not quitting)
    {
    	fenêtre << sdl2::rectangle({570,510}, {500,150}, {0xFF,0xFF,0xFF,0xFF}, true);
    	sdl2::texte phrase("Rendement pompe du circuit secondaire :", fonte_texte, fenêtre, {0x00,0xFF,0xFF,0xFF});
    	phrase.at(580,520);

    	sdl2::texte rendement(regime_p, fonte_texte, fenêtre, {0x00,0xFF,0xFF,0xFF});
    	rendement.at(590,550);

    // Charge une image fleche
    	sdl2::image fleche("data/fleche_haut_bas.png", fenêtre);
    	fleche.at(610,550);

    	sdl2::texte phrase("Q pour fermer", fonte_texte, fenêtre, {0x00,0xFF,0xFF,0xFF});
    	phrase.at(580,640);

    	fenêtre << phrase << rendement << fleche
            << sdl2::flush;
    	for ( const auto& e : events)
    	{
    		if (e->kind_of_event() == sdl2::event::key)
    		{
    			auto& key_ev = dynamic_cast<sdl2::event_keyboard&>(*e);
    			if (key_ev.type_of_event() == sdl2::event::key_down)
    			{
                	switch(key_ev.code())
                	{
                		case sdl2::event_keyboard::pagedown:
                		circuitsecondaire.equ_regimepompe(-0.01);
                		break;
                		case sdl2::event_keyboard::pageup:
                		circuitsecondaire.equ_regimepompe(0.01);
                		break;
                		default:
                        if (key_ev.ascci_code() == 'q')
                        {
                            quitting = true;
                        }
                	}

    			}
    		}
    	}
	}



}

// Action sur rendement pompe condensateur
void action_touche_R(sdl2::window fenêtre){

	circuit_sec circuitsecondaire = centrale.get_circuit_prim();
	condensateur condens = circuitsecondaire.get_condensateur();
	pompe pompe_c = condens.get_pompe();
	double r_p = pompe_c.get_regime();
	std::string regime_p = std::to_string(r_p)

	sdl2::font fonte_titre("./data/Lato-Bold.ttf", 28);
    // Pour choisir une fonte courante pour afficher du texte (pas encore mis en oeuvre pour l'affichage du texte)
    sdl2::font fonte_texte("./data/Lato-Thin.ttf", 18);

	bool quitting = false;
    sdl2::event_queue queue;
    auto events = queue.pull_events();

    while (not quitting)
    {
    	fenêtre << sdl2::rectangle({570,510}, {500,150}, {0xFF,0xFF,0xFF,0xFF}, true);
    	sdl2::texte phrase("Rendement pompe du condensateur :", fonte_texte, fenêtre, {0x00,0xFF,0xFF,0xFF});
    	phrase.at(580,520);

    	sdl2::texte rendement(regime_p, fonte_texte, fenêtre, {0x00,0xFF,0xFF,0xFF});
    	rendement.at(590,550);

    // Charge une image fleche
    	sdl2::image fleche("data/fleche_haut_bas.png", fenêtre);
    	fleche.at(610,550);

    	sdl2::texte phrase("Q pour fermer", fonte_texte, fenêtre, {0x00,0xFF,0xFF,0xFF});
    	phrase.at(580,640);

    	fenêtre << phrase << rendement << fleche
            << sdl2::flush;
    	for ( const auto& e : events)
    	{
    		if (e->kind_of_event() == sdl2::event::key)
    		{
    			auto& key_ev = dynamic_cast<sdl2::event_keyboard&>(*e);
    			if (key_ev.type_of_event() == sdl2::event::key_down)
    			{
                	switch(key_ev.code())
                	{
                		case sdl2::event_keyboard::pagedown:
                			condens.set_regime_pompe(-0.01);
                		break;
                		case sdl2::event_keyboard::pageup:
                			condens.set_regime_pompe(0.01);
                		break;
                		default:
                        if (key_ev.ascci_code() == 'q')
                        {
                            quitting = true;
                        }
                	}

    			}
    		}
    	}
	}



{


}

void action_touche_Tab(sdl2::window fenêtre){

	sdl2::image cent("data/reacteur_eau_pressurisee_zoom.jpg", fenêtre);
    	cent.at(50,30);

    	
    	fenêtre  << cent
            << sdl2::flush;
}

