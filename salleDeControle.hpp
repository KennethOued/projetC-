#ifndef DEF_SALLE_DE_CONTROLE
#define DEF_SALLE_DE_CONTROLE

 #include "centrale.hpp"


 class salleDeControle : 
  {
      public:
        salleDeControle();
        
        void display_and_run(sdl2::window fenêtre);
        void action_touche_1(sdl2::window fenêtre);
        void action_touche_2(sdl2::window fenêtre);
        void action_touche_B(sdl2::window fenêtre);
        void action_touche_T(sdl2::window fenêtre);
        void action_touche_P(sdl2::window fenêtre);
        void action_touche_R(sdl2::window fenêtre);
        void action_touche_U(sdl2::window fenêtre);
        void action_touche_S(sdl2::window fenêtre);
        void action_touche_Tab(sdl2::window fenêtre);
        void action_touche_Espace(sdl2::window fenêtre);
        void ordre(sdl2::window fenêtre, string phrase);
        void signalement(sdl2::window fenêtre, string phrase);





      private:
        centrale central;
  };

#endif
