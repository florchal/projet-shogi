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
	std::cout<<"début main\n";
	Moteur mot = Moteur();
	int x_init, y_init,x_fin,y_fin;
	std::cout<<"init moteur ok\n";
	
	while(1)
	{
		for(int y=0;y<9;y++)
		{
			for(int x=0;x<9;x++)
			{
				if(mot.plat_mot.plateau[x][y]!=NULL)
				{
					if(mot.plat_mot.plateau[x][y]->getNom()==Soldat)
						std::cout<<"P ";
					else if((mot.plat_mot.plateau[x][y]->getNom()==General)||(mot.plat_mot.plateau[x][y]->getNom()==General_Jade))
						std::cout<<"G ";
					else if(mot.plat_mot.plateau[x][y]->getNom()==Gen_arg)
						std::cout<<"A ";
					else if(mot.plat_mot.plateau[x][y]->getNom()==Gen_or)
						std::cout<<"O ";
					else if(mot.plat_mot.plateau[x][y]->getNom()==Chariot)
						std::cout<<"L ";
					else if(mot.plat_mot.plateau[x][y]->getNom()==Cavalier)
						std::cout<<"C ";
					else if(mot.plat_mot.plateau[x][y]->getNom()==Fou)
						std::cout<<"F ";
					else if(mot.plat_mot.plateau[x][y]->getNom()==Tour)
						std::cout<<"T ";
				}
				else std::cout<<"_ ";
			}
			std::cout<<"\n";
		}	
		std::cin>>x_init;
		std::cin.clear();
		std::cin>>y_init;
		std::cin.clear();
		std::cin>>x_fin;
		std::cin.clear();
		std::cin>>y_fin;
		std::cin.clear();		
		mot.coup(x_init,y_init,x_fin,y_fin);
	//mot.coup(8,8,8,7);
	}
}
