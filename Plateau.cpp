#include "Plateau.hpp"


/*Plateau::Plateau(){
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			plateau[i][j] = Pion::Pion(i,j);
		}
	}
}*/

void Plateau::parachutage(Pion& pion, int x_fin, int y_fin)
{
	// TODO retirer le pion de la liste capturée
	plateau[x_fin][y_fin]=&pion;
}





void Plateau::setPosition(Pion& pion, int x_fin, int y_fin){
	plateau[x_fin][y_fin]=&pion;
}

void Plateau::capture(Pion& pion, int x_cap, int y_cap, int preneur){
	if(preneur==1)
	{
		joueur1.push_back(pion);
	}
	if(preneur==2)
	{
		joueur2.push_back(pion);
	}
}
	
bool Plateau::hasPion(int x,int y){
	if(plateau[x][y]==NULL)
		return false;
	else return true;
	
}	
	
	
Pion Plateau::getPion(int x, int y){
	return *plateau[x][y];
}
