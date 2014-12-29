#include "Deplacements.hpp"


//----------------Test Généraux d'or et pions promus--------------------
int testGeneralOr_J2(int x_init, int y_init, int x, int y){	
	if((x==x_init) && (y==y_init+1)) //case avant J2
	{
		return 0;
	}
	else if((x==x_init+1) && (y==y_init+1)) //diagonale avant gauche J2
	{
		return 0;
	}
	else if((x==x_init-1) && (y==y_init+1)) //diagonale avant droite J2
	{
		return 0;
	}		
	else if((x==x_init-1) && (y==y_init)) //directement a droite J2
	{
		return 0;
	}		
	else if((x==x_init+1) && (y==y_init)) // Directement a gauche J2
	{
		return 0;
	}		
	else if((x==x_init) && (y==y_init-1)) //case arriere J2
	{
		return 0;
	}		
	else return -1; //déplacement invalide
}

int testGeneralOr_J1(int x_init, int y_init, int x, int y){	
	if((x==x_init) && (y==y_init+1)) //case arriere J1
	{
		return 0;
	}
	else if((x==x_init+1) && (y==y_init-1)) //diagonale avant droite J1
	{
		return 0;
	}
	else if((x==x_init-1) && (y==y_init-1)) //diagonale avant gauche J1
	{
		return 0;
	}		
	else if((x==x_init-1) && (y==y_init)) //case gauche J1
	{
		return 0;
	}		
	else if((x==x_init+1) && (y==y_init))//case droite J1
	{
		return 0;
	}		
	else if((x==x_init) && (y==y_init-1))//case avant J1
	{
		return 0;
	}		
	else return -1; //déplacement invalide
}
//----------------------------------------------------------------------

//-----------------Test Général et Général de jade----------------------
int testGeneral(int x_init, int y_init, int x, int y){	
	if((x==x_init) && (y==y_init+1))
	{
		return 0;
	}
	else if((x==x_init+1) && (y==y_init+1))
	{
		return 0;
	}
	else if((x==x_init-1) && (y==y_init+1))
	{
		return 0;
	}		
	else if((x==x_init-1) && (y==y_init))
	{
		return 0;
	}		
	else if((x==x_init+1) && (y==y_init))
	{
		return 0;
	}		
	else if((x==x_init) && (y==y_init-1))
	{
		return 0;
	}
	else if((x==x_init-1) && (y==y_init-1))
	{
		return 0;
	}
	else if((x==x_init+1) && (y==y_init-1))
	{
		return 0;
	}						
	else return -1; //déplacement invalide
}
//----------------------------------------------------------------------

//----------------------Test Généraux d'argent--------------------------
int testGeneralArgent_J2(int x_init, int y_init, int x, int y){	
	if((x==x_init) && (y==y_init+1)) //case avant J2
	{
		return 0;
	}
	else if((x==x_init+1) && (y==y_init+1)) //diagonale avant gauche J2
	{
		return 0;
	}
	else if((x==x_init-1) && (y==y_init+1))//diagonale avant droite J2
	{
		return 0;
	}				
	else if((x==x_init-1) && (y==y_init-1))//diagonale arriere droite J2
	{
		return 0;
	}
	else if((x==x_init+1) && (y==y_init-1))// Diagonale arriere gauche J2
	{
		return 0;
	}						
	else return -1; //déplacement invalide
}

int testGeneralArgent_J1(int x_init, int y_init, int x, int y){	
	
	if((x==x_init+1) && (y==y_init+1)) //diagonale arriere droite J1
	{
		return 0;
	}
	else if((x==x_init-1) && (y==y_init+1))//diagonale arriere gauche J1
	{
		return 0;
	}			
	else if((x==x_init-1) && (y==y_init-1))//diagonale avant droite J1
	{
		return 0;
	}
	else if((x==x_init+1) && (y==y_init-1))//diagonale avant gauche J1
	{
		return 0;
	}		
	else if((x==x_init) && (y==y_init-1))//case avant J1
	{
		return 0;
	}			
	else return -1; //déplacement invalide
}
//----------------------------------------------------------------------

//----------------------Test Soldats----------------------------------
int testSoldat_J2(int x_init, int y_init, int x, int y){
	if((x==x_init) && (y==y_init+1))
	{
		return 0;
	}
	
	else return -1; //déplacement invalide
}

int testSoldat_J1(int x_init, int y_init, int x, int y){
	if((x==x_init) && (y==y_init-1))
	{
		return 0;
	}
	
	else return -1; //déplacement invalide
}
//----------------------------------------------------------------------

//----------------------Test Cavaliers----------------------------------
int testCavalier_J2(int x_init, int y_init, int x, int y){
	if((x==x_init+1)&&(y==y_init+2))
	{
		return 0;
	}
	else if((x==x_init-1)&&(y==y_init+2))
	{
		return 0;
	}
	else return -1;
}

int testCavalier_J1(int x_init, int y_init, int x, int y){
	if((x==x_init+1)&&(y==y_init-2))
	{
		return 0;
	}
	else if((x==x_init-1)&&(y==y_init-2))
	{
		return 0;
	}
	else return -1;
}
//----------------------------------------------------------------------


int testTour(int x_init, int y_init, int x_fin, int y_fin){
	/*if((y_init==y_fin)&&(x_init<x_fin)) //horizontal vers la droite
	 {
	 for(int x=x_init+1;x<=x_fin-1;x++)
	 {
	 if(plateau[x][y_fin]!=NULL)
	 return -1;
	 }
	 }
	 else if((y_init==y_fin)&&(x_init>x_fin)) //horizontal vers la gauche
	 {
	 for(int x=x_init-1;x>=x_fin+1;x--)
	 {
	 if(plateau[x][y_fin]!=NULL)
	 return -1;
	 }
	 }
	 else if((x_init==x_fin)&&(y_init>y_fin)) //vertical vers le haut
	 {
	 for(int y=y_init-1;y>=y_fin+1;y--)
	 {
	 if(plateau[x_init][y]!=NULL)
	 return -1;
	 }
	 }
	 else if((x_init==x_fin)&&(y_init<y_fin)) //vertical vers le bas
	 {
	 for(int y=y_init+1;y<=y_fin-1;y++)
	 {
	 if(plateau[x_init][y]!=NULL)
	 return -1;
	 }
	 }	
	 else
	 return 0;*/
}

int testFou(int x_init, int y_init, int x_fin, int y_fin){
	/*if((y_init<y_fin)&&(x_init<x_fin))//diagonale bas droite
	 {
	 for(int k=x_init+1;k<=x_fin-1;k++)
	 {
	 if(plateau[x_init+k][y_init+k]!=NULL)
	 return -1;
	 }
	 }
	 else if((y_init<y_fin)&&(x_init>x_fin)) //diagonale bas gauche
	 {
	 for(int k=y_init+1;k<=y_fin-1;k++)
	 {
	 if(plateau[x_init-k][y_init+k]!=NULL)
	 return -1;
	 }
	 }
	 else if((x_init>x_fin)&&(y_init>y_fin))//diagonale haut gauche
	 {
	 for(int k=y_init-1;k>=y_fin+1;k--)
	 {
	 if(plateau[x_init-k][y_init-k]!=NULL)
	 return -1;
	 }
	 }
	 else if((x_init<x_fin)&&(y_init>y_fin))//diagonale haut droite
	 {
	 for(int k=x_init+1;k<=x_fin-1;k++)
	 {
	 if(plateau[x_init+k][y_init-k]!=NULL)
	 return -1;
	 }
	 }	
	 else
	 return 0;*/
	
}

int testFouPromu(int x_init, int y_init, int x_fin, int y_fin){
	if((x_fin==x_init+1)&&(y_fin==y_init))
		return 0;
	else if((x_fin==x_init-1)&&(y_fin==y_init))
		return 0;
	else if((x_fin==x_init)&&(y_fin==y_init+1))
		return 0;
	else if((x_fin==x_init)&&(y_fin==y_init-1))
		return 0;
	else testFou( x_init, y_init, x_fin, y_fin);
}

int testTourPromue(int x_init, int y_init, int x_fin, int y_fin){
	if((x_fin==x_init+1)&&(y_fin==y_init+1))
		return 0;
	else if((x_fin==x_init-1)&&(y_fin==y_init-1))
		return 0;
	else if((x_fin==x_init-1)&&(y_fin==y_init+1))
		return 0;
	else if((x_fin==x_init+1)&&(y_fin==y_init-1))
		return 0;
	else testTour(x_init, y_init, x_fin, y_fin);
}

int testMouvement(Pion& pion, int x_fin, int y_fin){
	// Je rajoute une sécurité la si ca te dérange pas.

	int x_init = pion.getPositionx();
	int y_init = pion.getPositiony();
	int proprietaire = pion.getProprietaire(); 
	
	if((x_init<9)&&(x_init>-1)&&(y_init<9)&&(y_init>-1)) 
	{
		switch(pion.getNom())
		{
			case Soldat:		//Soldat
				if(proprietaire==1)
					return testSoldat_J1(x_init,y_init,x_fin,y_fin);
				else if(proprietaire==2)
					return testSoldat_J2(x_init,y_init,x_fin,y_fin);
				break;
				
			case Chariot:		//Chariot
				break;
				
			case Cavalier:		//Cavalier
				if(proprietaire==1)
					return testCavalier_J1(x_init,y_init,x_fin,y_fin);
				else if(proprietaire==2)
					return testCavalier_J2(x_init,y_init,x_fin,y_fin);
				break;
				
			case Gen_arg:		//Gen_arg
				if(proprietaire==1)
					return testGeneralArgent_J1(x_init, y_init, x_fin, y_fin);
				else if(proprietaire==2)
					return testGeneralArgent_J2(x_init, y_init, x_fin, y_fin);
				break;
				
			case Gen_or:		//Gen_or
				if(proprietaire==1)
					return testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
				else if(proprietaire==2)
					return testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
				break;
				
			case General:		//General
					return testGeneral(x_init, y_init, x_fin,y_fin);
				break;
				
			case Fou:		//Fou
					return testFou(x_init, y_init, x_fin,y_fin);
				break;
				
			case Tour:		//Tour
					return testTour(x_init, y_init, x_fin,y_fin);
				break;
				
			case Soldat_p:		//Soldat promu
				if(proprietaire==1)
					return testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
				else if(proprietaire==2)
					return testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
				break;
				
			case Chariot_p:	//Chariot promu
				if(proprietaire==1)
					return testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
				else if(proprietaire==2)
					return testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
				break;
				
			case Cavalier_p:	//Cavalier promu
				if(proprietaire==1)
					return testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
				else if(proprietaire==2)
					return testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
				break;
				
			case Gen_arg_p:	//General d'argent promu
				if(proprietaire==1)
					return testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
				else if(proprietaire==2)
					return testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
				break;
				
			case Fou_p:	//Fou promu
					return testFouPromu(x_init,y_init, x_fin, y_fin);
				break;
				
			case Tour_p:	//Tour promue
					return testTourPromue(x_init,y_init, x_fin, y_fin);
				break;
				
			case General_Jade:	//General de jade
					return testGeneral(x_init, y_init, x_fin,y_fin);
				break;
				
			default:
				return -1;
				break;
		}
	}
	else 
		return -1;
}


int testParachutage(Pion& pion, int x_fin, int y_fin, int joueur_actif, Plateau plateau)
{
	if(joueur_actif==1)
	{
		if(y_fin==0)//pas de parachutage en derniere ligne
			return -1;
		if((pion.getNom()==Cavalier)&&(y_fin<=1))//pas de cavalier sur les deux dernières lignes
			return -1;
	}	
	if(joueur_actif==2) //idem pour joueur 2
	{
		if(y_fin==8)
			return -1;
		if((pion.getNom()==Cavalier)&&(y_fin>=7))
			return -1;
	}
	
	if(pion.getNom()==Soldat) //vérification qu'il n'y a pas deux soldats non promus dans la même colonne
	{
		for(int i = 0; i<9;i++)
		{
			if((plateau.getPion(x_fin,i).getNom()==Soldat)&&(plateau.getPion(x_fin,i).getProprietaire()==joueur_actif))
				return -1;
		}
	}
	else return 0;
	
}

