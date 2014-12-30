#ifndef DEPLACEMENTS_HEADER
#define DEPLACEMENTS_HEADER


#include <cstdlib>
#include <iostream>
#include <string>
#include "Pion.hpp"
#include "Plateau.hpp"
//La classe Deplacements s'occupe de tester si le mouvement que l'on souhaite réaliser est autorisé pour notre piece
//fonction principale pour cela : testMouvements(pion se déplaçant, abscisse d'arrivée, ordonnée d'arrivée); 
//la fonction renvoie 0 si le mouvement est légal 1 dans le cas contraire.

//Si la case d'arrivée est occupée par une autre piece (amie ou ennemie) c'est à la classe Moteur de réagir
//on ne teste ici que la portée du déplacement

int testMouvement(Pion&,int,int,Plateau);
int testGeneralOr_J1(int,int,int,int);
int testGeneralOr_J2(int,int,int,int);
int testGeneral(int,int,int,int);
int testSoldat_J1(int,int,int,int);
int testSoldat_J2(int,int,int,int);
int testCavalier_J1(int, int, int,int);
int testCavalier_J2(int, int, int,int);
int testGeneralArgent_J1(int,int,int,int);
int testGeneralArgent_J2(int,int,int,int);
int testParachutage(Pion&,int,int,int,Plateau);
int testTour(int,int,int,int,Plateau);
int testTourPromue(int,int,int,int,Plateau);
int testFou(int,int,int,int,Plateau);
int testFouPromu(int,int,int,int,Plateau);
int testChariot_J1(int,int,int,int,Plateau);
int testChariot_J2(int,int,int,int,Plateau);

#endif
