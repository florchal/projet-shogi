#include "Pion.hpp"

Pion::Pion(int x, int y, int prop, int name, bool viv){ //Constructeur
	positionx = x;
	positiony = y;
	proprietaire = prop;
	nom = name;
	vivant = viv;
}

/*Pion::Pion(Pion& pion){ //Constructeur
	positionx = pion.getPositionx();
	positiony = pion.getPositiony();
	proprietaire = pion.getProprietaire();
	nom = pion.getNom();
	vivant = pion.getVivant();
	promu =pion.getPromotion();
}*/
//setters
void Pion::setPion(int x, int y, int prop, int name,bool viv){ //Constructeur
	positionx = x;
	positiony = y;
	proprietaire = prop;
	nom = name;
	vivant = viv;
}

void Pion::setNom(int nouveau_nom){
	nom = nouveau_nom;
}

void Pion::setPromotion(bool promotion){
	promu = promotion;
	if(promotion)
	{
		switch(this->getNom())
		{
			case Soldat:
				this->setNom(Soldat_p);
				break;
			
			case Cavalier:
				this->setNom(Cavalier_p);
				break;
				
			case Gen_arg:
				this->setNom(Gen_arg_p);
				break;
			
			case Chariot:
				this->setNom(Chariot_p);
				break;
				
			case Tour:
				this->setNom(Tour_p);
				break;
			
			case Fou:
				this->setNom(Fou_p);
				break;
				
			default:
				break;
		}
	}
	else
	{
		switch(this->getNom())
		{
			case Soldat_p:
				this->setNom(Soldat);
				break;
			
			case Cavalier_p:
				this->setNom(Cavalier);
				break;
				
			case Gen_arg_p:
				this->setNom(Gen_arg);
				break;
			
			case Chariot_p:
				this->setNom(Chariot);
				break;
				
			case Tour_p:
				this->setNom(Tour);
				break;
			
			case Fou_p:
				this->setNom(Fou);
				break;
				
			default:
				break;
		}
	}
}

void Pion::setPosition(int x, int y){
	positionx = x;
	positiony = y;
}

void Pion::setVivant(bool vivant){
	this->vivant = vivant;
}

void Pion::setProprietaire(int prop){
	proprietaire = prop;
}
//getters

int Pion::getNom(){
	return nom;
}

bool Pion::getPromotion(){
	return promu;
}

int Pion::getPositionx(){
	return positionx;
}

int Pion::getPositiony(){
	return positiony;
}

bool Pion::getVivant(){
	return vivant;
}

int Pion::getProprietaire(){
	return proprietaire;
}

void Pion::retirerPion(){
	positionx = 100;
	positiony = 100;
}	
