
#include "Deplacements.hpp"


//----------------Test Généraux d'or et pions promus--------------------
int testGeneralOr_J1(int x_init, int y_init, int x, int y){	
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
	else return -1; //déplacement invalide
}

int testGeneralOr_J2(int x_init, int y_init, int x, int y){	
	if((x==x_init) && (y==y_init+1))
	{
		return 0;
	}
	else if((x==x_init+1) && (y==y_init-1))
	{
		return 0;
	}
	else if((x==x_init-1) && (y==y_init-1))
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
int testGeneralArgent_J1(int x_init, int y_init, int x, int y){	
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

int testGeneralArgent_J2(int x_init, int y_init, int x, int y){	

	if((x==x_init+1) && (y==y_init+1))
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



//----------------------Test Soldats----------------------------------
int testSoldat_J1(int x_init, int y_init, int x, int y){
	if((x==x_init) && (y==y_init+1))
	{
		return 0;
	}

	else return -1; //déplacement invalide
}

int testSoldat_J2(int x_init, int y_init, int x, int y){
	if((x==x_init) && (y==y_init-1))
	{
		return 0;
	}
	
	else return -1; //déplacement invalide
}
//----------------------------------------------------------------------


//----------------------Test Cavaliers----------------------------------
int testCavalier_J1(int x_init, int y_init, int x, int y){
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

int testCavalier_J2(int x_init, int y_init, int x, int y){
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


int testTour(int x_init, int y_init, int x, int y){
	
	
}


int testMouvement(Pion& pion, int x_fin, int y_fin){
	
	int x_init = pion.getPositionx();
	int y_init = pion.getPositiony();
	int proprietaire = pion.getProprietaire(); 
	
	switch(pion.getNom()){
		case Soldat:		//Soldat
		if(proprietaire==1)
			testSoldat_J1(x_init,y_init,x_fin,y_fin);
		else if(proprietaire==2)
			testSoldat_J2(x_init,y_init,x_fin,y_fin);
		break;
		case Chariot:		//Chariot
		break;
		case Cavalier:		//Cavalier
		if(proprietaire==1)
			testCavalier_J1(x_init,y_init,x_fin,y_fin);
		else if(proprietaire==2)
			testCavalier_J2(x_init,y_init,x_fin,y_fin);
		break;
		case Gen_arg:		//Gen_arg
		if(proprietaire==1)
			testGeneralArgent_J1(x_init, y_init, x_fin, y_fin);
		else if(proprietaire==2)
			testGeneralArgent_J2(x_init, y_init, x_fin, y_fin);
		break;
		case Gen_or:		//Gen_or
		if(proprietaire==1)
			testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
		else if(proprietaire==2)
			testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
		break;
		case General:		//General
		testGeneral(x_init, y_init, x_fin,y_fin);
		break;
		case Fou:		//Fou
		break;
		case Tour:		//Tour
		break;
		case Soldat_p:		//Soldat promu
		if(proprietaire==1)
			testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
		else if(proprietaire==2)
			testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
		break;
		case Chariot_p:	//Chariot promu
		if(proprietaire==1)
			testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
		else if(proprietaire==2)
			testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
		break;
		case Cavalier_p:	//Cavalier promu
		if(proprietaire==1)
			testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
		else if(proprietaire==2)
			testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
		break;
		case Gen_arg_p:	//General d'argent promu
		if(proprietaire==1)
			testGeneralOr_J1(x_init, y_init, x_fin, y_fin);
		else if(proprietaire==2)
			testGeneralOr_J2(x_init, y_init, x_fin, y_fin);
		break;
		case Fou_p:	//Fou promu
		break;
		case Tour_p:	//Tour promue
		break;
		case General_Jade:	//General de jade
		testGeneral(x_init, y_init, x_fin,y_fin);
		break;
		default:
		return -1;
		break;
	}
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
		for(int i = 0; i++; i<9)
		{
			if((plateau.getPion(x_fin,i).getNom()==Soldat)&&(plateau.getPion(x_fin,i).getProprietaire()==joueur_actif))
				return -1;
		}
	}
	else return 0;
	
}

