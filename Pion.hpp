#ifndef PION_HEADER
#define PION_HEADER


#include <cstdlib>
#include <iostream>
#include <string>


enum piece {Case_vide, Soldat, Chariot, Cavalier, Gen_arg, Gen_or, General, Fou, Tour, Soldat_p, Chariot_p, Cavalier_p, Gen_arg_p, Fou_p, Tour_p,General_Jade};

class Pion {
	
private:
	int nom;
	bool promu;
	int positionx;
	int positiony;
	int proprietaire;//1 pour joueur 1, 2 pour joueur 2
	bool vivant; //true si sur plateau, false sinon
	
public:
	void setPion(int,int,int,int,bool);
	void setNom(int);
	void setPromotion(bool);
	void setPosition(int,int);
	void setVivant(bool);
	void setProprietaire(int);
	int getNom();
	bool getPromotion();
	int getPositionx();
	int getPositiony();
	int getId();
	bool getVivant();
	int getProprietaire();
	void retirerPion();
	Pion(int, int, int, int,bool);
	//Pion(Pion& pion);
};
#endif
