#include "Moteur.hpp"
#include <stdio.h>



int Moteur::attaque(Pion& pion, int x_fin, int y_fin)
{
	if(plat_mot.getPion(x_fin,y_fin).getProprietaire() == joueur_actif) //lol je testais le pion en mouvement et pas le pion capturé
		return -1; //pas de friendly fire
	
	else
	{
		//dégager le pion capturé
		plat_mot.getPion(x_fin,y_fin).setPromotion(false); //dépromouvoir le pion capturé
		plat_mot.getPion(x_fin,y_fin).retirerPion(); //supprimer ses coordonnées dans la classe pion
		plat_mot.capture(plat_mot.getPion(x_fin,y_fin), x_fin, y_fin, joueur_actif); //appel a la fonction capture propre au plateau, ce qui ajoute le pion a la liste des pions capturés et le retire du plateau
		//mouvement normal 
		plat_mot.plateau[x_fin][y_fin]=new Pion(pion.getPositionx(),pion.getPositiony(),pion.getProprietaire(),pion.getNom(),pion.getVivant());
		plat_mot.plateau[x_fin][y_fin]->setPromotion(pion.getPromotion());
		plat_mot.plateau[x_fin][y_fin]->setPosition(x_fin,y_fin);
		return 0; //attaque ok
	}
	
}

int Moteur::mouvement(Pion& pion, int x_fin, int y_fin)
{
    
	if((testMouvement(pion,x_fin,y_fin,plat_mot)) == 0) //si mouvement légal
	{
		std::cout<<"coucou cest nous"<<std::endl;
		if(plat_mot.plateau[x_fin][y_fin]!= NULL) //mais si case déjà occupée
		{	
			attaque(pion,x_fin,y_fin); //mener attaque //et la on fait pas de return ???? GRRRRRRR x)
			
			if((joueur_actif==1)&&(x_fin<=2)) //gestion des promotions cf changements classe Pion 
			{
				plat_mot.plateau[x_fin][y_fin]->setPromotion(true);
			}
			if((joueur_actif==2)&&(x_fin>=6))
			{
				plat_mot.plateau[x_fin][y_fin]->setPromotion(true);
			}
			std::cout<<"mais tu es pas censé passer la"<<std::endl;
			return 0;
            
		}
		else //sinon déplacement normal
		{
			std::cout <<pion.getPositionx()<<pion.getPositiony()<<pion.getProprietaire()<<pion.getNom()<<std::endl;
			plat_mot.plateau[x_fin][y_fin]=new Pion(pion.getPositionx(),pion.getPositiony(),pion.getProprietaire(),pion.getNom(),pion.getVivant());
			plat_mot.plateau[x_fin][y_fin]->setPromotion(pion.getPromotion());
			plat_mot.plateau[x_fin][y_fin]->setPosition(x_fin,y_fin);
			
			if((joueur_actif==1)&&(x_fin<=2)) //gestion des promotions cf changements classe Pion 
			{
				plat_mot.plateau[x_fin][y_fin]->setPromotion(true);
			}
			if((joueur_actif==2)&&(x_fin>=6))
			{
				plat_mot.plateau[x_fin][y_fin]->setPromotion(true);
			}
			
            
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
			plat_mot.parachutage(pion,x_fin,y_fin,joueur_actif); //appel a la fonction parachutage du plateau qui doit supprimer le pion de la liste des capturés et le remettre en jeu
			return 0;
		}
	}
	else return -1;
	
}
// je l'utilise pas me demande pas pourquoi x) ah si Je sais !!! C'est UN putin de ELSE IF :'( sinon le joueur change jamais je crois x)
void Moteur::changer_joueur(){
	if(joueur_actif==1)
		joueur_actif=2;
	else
		joueur_actif=1;
}


/*int Moteur::coup(int x_init, int y_init, int x_fin, int y_fin) //gère tous les coups joués
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
 return -1; //si aucun des deux :erreur// Ca c'est faux mon loulou ... Quoi qu'il arrive il retourne -1 la ...
 }	// Manque les return, tu dois renvoyer quelque chose et tu retournes toujours -1 regarde ce que je te propose
 // Ca explique qu'a chaque fois que tu fais un mouvement le mouvement est invalide mais tu bouges quand meme les pièces.
 // Le return de la fonction mouvmement est inexploitée. Mais je t'aime bien quand même x)
 }*/
int Moteur::coup(int x_init, int y_init, int x_fin, int y_fin) //gère tous les coups joués
{
	Pion pion = plat_mot.getPion(x_init,y_init);
	if((plat_mot.plateau[x_init][y_init]!=NULL)&&(pion.getProprietaire()==joueur_actif))
	{
		if(!pion.getVivant()) //si on cherche à bouger un pion mort on veut parachuter
		{
			parachutage(pion,x_fin,y_fin);
			changer_joueur();
			return 0;
		}
		else if(pion.getVivant()) //si on cherche à bouger un pion vivant c'est un déplacement normal
		{
			if(mouvement(pion,x_fin,y_fin)!=-1) //Déplacer le pion (return -1 si coup invalide)
			{
				plat_mot.plateau[x_init][y_init]=NULL;
				if(joueur_actif==1)
					joueur_actif=2;
				else
					joueur_actif=1;
				return 0;
			}
			else
				return -1;
			
		}
		else
		{
			return -1;
		}
	}
	
}

Moteur::Moteur(){
	
	bool partie_active = true;
	Plateau plat_jeu = Plateau();
	printf("plateau initialisé\n");
	this->joueur_actif=1 ; // je pense que ca ca devrait marcher.
	partie_active=true;
	//----------------------------------------------------------
	for(int i = 0; i < 9; i++) //création des soldats du joueur 1
	{
		plat_jeu.plateau[i][6]= new Pion(i,6,1,Soldat,true);
	}
	for(int i = 0; i < 9; i++) //création des soldats du joueur 2
	{
		plat_jeu.plateau[i][2]= new Pion(i,2,2,Soldat,true);
	}
	//----------------------------------------------------------
	//création des tours
	plat_jeu.plateau[7][7]= new Pion(7,7,1,Tour,true);
	plat_jeu.plateau[1][1]= new Pion(1,1,2,Tour,true);
	
	//création des fous
	plat_jeu.plateau[1][7]=new Pion(1,7,1,Fou,true);
	plat_jeu.plateau[7][1]=new Pion(7,1,2,Fou,true);
	
	//création des Generaux
	plat_jeu.plateau[4][8]=new Pion(4,8,1,General,true);
	plat_jeu.plateau[4][0]=new Pion(4,0,2,General_Jade,true);
	
	//création des Generaux d'or
	plat_jeu.plateau[3][8]=new Pion(3,8,1,Gen_or,true);//J1
	plat_jeu.plateau[5][8]=new Pion(5,8,1,Gen_or,true);
	plat_jeu.plateau[3][0]=new Pion(3,0,2,Gen_or,true);//J2
	plat_jeu.plateau[5][0]=new Pion(5,0,2,Gen_or,true);
	
	//création des Generaux d'argent
	plat_jeu.plateau[2][8]=new Pion(2,8,1,Gen_arg,true);//J1
	plat_jeu.plateau[6][8]=new Pion(6,8,1,Gen_arg,true);
	plat_jeu.plateau[2][0]=new Pion(2,0,2,Gen_arg,true);//J2
	plat_jeu.plateau[6][0]=new Pion(6,0,2,Gen_arg,true);
	
	//création des Cavaliers
	plat_jeu.plateau[1][8]=new Pion(1,8,1,Cavalier,true);//J1
	plat_jeu.plateau[7][8]=new Pion(7,8,1,Cavalier,true);
	plat_jeu.plateau[1][0]=new Pion(1,0,2,Cavalier,true);//J2
	plat_jeu.plateau[7][0]=new Pion(7,0,2,Cavalier,true);
	
	//création des Chariot
	plat_jeu.plateau[0][8]=new Pion(0,8,1,Chariot,true);//J1
	plat_jeu.plateau[8][8]=new Pion(8,8,1,Chariot,true);
	plat_jeu.plateau[0][0]=new Pion(0,0,2,Chariot,true);//J2
	plat_jeu.plateau[8][0]=new Pion(8,0,2,Chariot,true);
	//-------------------------------------------------------
	plat_mot=plat_jeu ;
	printf("fin creation moteur\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(plat_mot.plateau[i][j]!= NULL)
				std::cout<<i<<","<<j<<"    "<<plat_mot.plateau[i][j]->getNom()<<"    "<<plat_mot.plateau[i][j]->getProprietaire()<<std::endl;
		}
	}
}
int Moteur::getJoueur()
{
    return joueur_actif;

}
