#include "Moteur.hpp"
#include <stdio.h>



int Moteur::attaque(Pion& pion, int x_fin, int y_fin)
{
	if(pion.getProprietaire() == joueur_actif) //essaie de capturer son propre pion
		return -1; //pas de friendly fire
		
	else 
	{
		plat_mot.getPion(x_fin,y_fin).setPromotion(false); //dépromouvoir le pion capturé
		plat_mot.getPion(x_fin,y_fin).retirerPion(); //supprimer ses coordonnées dans la classe pion
		plat_mot.capture(pion, x_fin, y_fin, joueur_actif); //appel a la fonction capture propre au plateau, ce qui ajoute le pion a la liste des pions capturés et le retire du plateau
		plat_mot.setPosition(pion,x_fin,y_fin); //place le pion en mouvement à la position voulue sur le plateau
		pion.setPosition(x_fin, y_fin);//met à jour les coordonnées finales dans la classe pion
		return 0; //attaque ok
	}
	
}

int Moteur::mouvement(Pion& pion, int x_fin, int y_fin)
{	
	if((testMouvement(pion,x_fin,y_fin)) == 0) //si mouvement légal
	{
		if(plat_mot.plateau[x_fin,y_fin]!=NULL) //mais si case déjà occupée
			attaque(pion,x_fin,y_fin); //mener attaque
		else //sinon déplacement normal
		{
			pion.setPosition(x_fin,y_fin);
			plat_mot.setPosition(pion,x_fin,y_fin);
			return 0;
		}
	}
	else
	return -1;
}



int Moteur::parachutage(Pion& pion, int x_fin, int y_fin)
{
	if(testParachutage(pion, x_fin, y_fin, joueur_actif,plat_mot)==0)//si parachutage autorisé
	{ 
		if(plat_mot.plateau[x_fin][y_fin]==NULL) //si case libre 
			{
				pion.setPosition(x_fin,y_fin); //met a jour les nouvelles coordonnées dans la classe pion
				plat_mot.parachutage(pion,x_fin,y_fin); //appel a la fonction parachutage du plateau qui doit supprimer le pion de la liste des capturés et le remettre en jeu
				return 0;
			}
	}
	else return -1;
	
}

void Moteur::changer_joueur(){
	if(joueur_actif==1)
		joueur_actif=2;
	if(joueur_actif==2)
		joueur_actif=1;
}


int Moteur::coup(int x_init, int y_init, int x_fin, int y_fin) //gère tous les coups joués
{
	Pion pion = plat_mot.getPion(x_init,y_init);
	if((plat_mot.plateau[x_init][y_init]!=NULL)&&(pion.getProprietaire()==joueur_actif))
	{
		if(!pion.getVivant()) //si on cherche à bouger un pion mort on veut parachuter
		{
			parachutage(pion,x_fin,y_fin); 
			changer_joueur();
		}
		if(pion.getVivant()) //si on cherche à bouger un pion vivant c'est un déplacement normal
		{
			mouvement(pion,x_fin,y_fin);//Déplacer le pion (return -1 si coup invalide)
			plat_mot.plateau[x_init][y_init]=NULL;
			changer_joueur();
		}
		return -1; //si aucun des deux :erreur
	}	
}


Moteur::Moteur(){
	
	bool partie_active = true;
	Plateau plateau_jeu = Plateau();
	printf("plauteau initialisé\n");
	int joueur_actif=1;

	//----------------------------------------------------------
	for(int i = 0; i < 9; i++) //création des soldats du joueur 1
	{
		plat_mot.plateau[i][6]= new Pion(i,6,1,Soldat,true);
	}
	for(int i = 0; i < 9; i++) //création des soldats du joueur 2
	{
		plat_mot.plateau[i][2]= new Pion(i,2,2,Soldat,true);
	}
	//----------------------------------------------------------
	//création des tours
	plat_mot.plateau[7][7]= new Pion(7,7,1,Tour,true);
	plat_mot.plateau[1][1]= new Pion(1,1,2,Tour,true);

	//création des fous
	plat_mot.plateau[1][7]=new Pion(1,7,1,Fou,true);
	plat_mot.plateau[7][1]=new Pion(7,1,2,Fou,true); 

	//création des Generaux
	plat_mot.plateau[4][8]=new Pion(4,8,1,General,true);
	plat_mot.plateau[4][0]=new Pion(4,0,2,General_Jade,true);

	//création des Generaux d'or
	plat_mot.plateau[3][8]=new Pion(3,8,1,Gen_or,true);//J1
	plat_mot.plateau[5][8]=new Pion(5,8,1,Gen_or,true);
	plat_mot.plateau[3][0]=new Pion(3,0,2,Gen_or,true);//J2
	plat_mot.plateau[5][0]=new Pion(5,0,2,Gen_or,true);
	
	//création des Generaux d'argent
	plat_mot.plateau[2][8]=new Pion(2,8,1,Gen_arg,true);//J1
	plat_mot.plateau[6][8]=new Pion(6,8,1,Gen_arg,true);
	plat_mot.plateau[2][0]=new Pion(2,0,2,Gen_arg,true);//J2
	plat_mot.plateau[6][0]=new Pion(6,0,2,Gen_arg,true);
	
	//création des Cavaliers
	plat_mot.plateau[1][8]=new Pion(1,8,1,Cavalier,true);//J1
	plat_mot.plateau[7][8]=new Pion(7,8,1,Cavalier,true);
	plat_mot.plateau[1][0]=new Pion(1,0,2,Cavalier,true);//J2
	plat_mot.plateau[7][0]=new Pion(7,0,2,Cavalier,true);
	
	//création des Chariot
	plat_mot.plateau[0][8]=new Pion(0,8,1,Chariot,true);//J1
	plat_mot.plateau[8][8]=new Pion(8,8,1,Chariot,true);
	plat_mot.plateau[0][0]=new Pion(0,0,2,Chariot,true);//J2
	plat_mot.plateau[8][0]=new Pion(8,0,2,Chariot,true);
	//-------------------------------------------------------
	printf("fin creation moteur\n");
}
