#ifndef PLATEAU_HEADER
#define PLATEAU_HEADER

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector> 
#include "Pion.hpp"

class Plateau
{
	
	public:
		Pion* plateau[9][9];
	private:
		std::vector<Pion> joueur1;
		std::vector<Pion> joueur2;
	
	public:
	
		void setPosition(Pion&,int,int);
		void capture(Pion&,int,int,int);
		void parachutage(Pion&,int,int);
		Pion getPion(int,int);
		//Plateau();
		
};
#endif
