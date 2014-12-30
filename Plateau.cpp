#include "Plateau.hpp"
#include <stdio.h>

Plateau::Plateau(){
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			plateau[i][j] = NULL;
		}
	}
}

void Plateau::parachutage(Pion& pion, int x_fin, int y_fin,int joueur)
{
	int i = 0; //supprime le pion de la main du joueur concerné
	if(joueur==1)
	{
		while(joueur1[i]!=&pion)
		{
			i++;
		}
		joueur1[i]=NULL;
	}
	if(joueur==2)
	{
		while(joueur2[i]!=&pion)
		{
			i++;
		}
		joueur2[i]=&pion;
	}
	
	plateau[x_fin][y_fin]=&pion;//met le pion sur le plateau
}

void Plateau::setPosition(Pion& pion, int x_fin, int y_fin){
	plateau[x_fin][y_fin]=&pion;
}

void Plateau::capture(Pion pion, int x_cap, int y_cap, int preneur){
	int i = 0; //met le pion capturé dans la main du joueur concerné
	if(preneur==1)
	{
		while(joueur1[i]!=NULL)
		{
			i++;
		}
		joueur1[i]=&pion;
	}
	if(preneur==2)
	{
		while(joueur2[i]!=NULL)
		{
			i++;
		}
		joueur2[i]=&pion;
	}
	plateau[x_cap][y_cap]=NULL; //supprime le pion du plateau

}

Pion Plateau::getPion(int x, int y){
	return *plateau[x][y];
}
