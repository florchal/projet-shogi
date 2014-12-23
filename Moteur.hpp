#ifndef MOTEUR_HEADER
#define MOTEUR_HEADER


#include <cstdlib>
#include <iostream>
#include <string>
#include "Deplacements.hpp"
#include "Plateau.hpp"
#include "Pion.hpp"


class Moteur{
	
	private:
		bool partie_active;
		int joueur_actif;
		Plateau plat_mot;

	public:
		int mouvement(Pion&,int,int);
		int coup(int,int,int,int); 
		int attaque(Pion&, int, int);
		int parachutage(Pion&, int, int);
		Moteur();
		void changer_joueur();
	
};
#endif
