#include "Pion.hpp"

Pion::Pion(int x, int y, int prop, int name, bool viv){ //Constructeur
	positionx = x;
	positiony = y;
	proprietaire = prop;
	nom = name;
	vivant = viv;
}
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
}

void Pion::setPosition(int x, int y){
	positionx = x;
	positiony = y;
}

void Pion::setVivant(bool vivant){
	vivant = vivant;
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
