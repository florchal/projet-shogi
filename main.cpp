#include <cstdlib>
#include <iostream>
#include <string>
#include "Deplacements.hpp"
#include "Plateau.hpp"
#include "Pion.hpp"
#include "Moteur.hpp"
#include <stdio.h>

//void afficher();
	
int main()
{
	printf("début main\n");
	Moteur mot = Moteur();
	int x_init, y_init,x_fin,y_fin;
	printf("init moteur ok\n");
	
	while(1)
	{
		for(int y=0;y<9;y++)
		{
			for(int x=0;x<9;x++)
			{
				if(mot.plat_mot.plateau[x][y]!=NULL)
				{
					if(mot.plat_mot.plateau[x][y]->getNom()==Soldat)
						printf("P ");
					else if((mot.plat_mot.plateau[x][y]->getNom()==General)||(mot.plat_mot.plateau[x][y]->getNom()==General_Jade))
						printf("G ");
					else if(mot.plat_mot.plateau[x][y]->getNom()==Gen_arg)
						printf("A ");
					else if(mot.plat_mot.plateau[x][y]->getNom()==Gen_or)
						printf("O ");
					else if(mot.plat_mot.plateau[x][y]->getNom()==Chariot)
						printf("L ");
					else if(mot.plat_mot.plateau[x][y]->getNom()==Cavalier)
						printf("C ");
					else if(mot.plat_mot.plateau[x][y]->getNom()==Fou)
						printf("F ");
					else if(mot.plat_mot.plateau[x][y]->getNom()==Tour)
						printf("T ");
				}
				else printf("_ ");
			}
			printf("\n");
		}	
		if((mot.coup(scanf("%d",&x_init),scanf("%d",&y_init), scanf("%d",&x_fin),scanf("%d",&y_fin)))==-1)
					printf("coup non autorisé\n");
	}
}
