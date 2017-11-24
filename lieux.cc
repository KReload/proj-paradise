#include "lieux.hh"
#include <fstream>
#include <iostream>
#include <string>

Lieu::Lieu(){
	std::string ville;
	std::ifstream fichier("villeP.txt", std::ios::in);  // on ouvre en lecture
	if(fichier)  // si l'ouverture a fonctionné
	{
 
       	while(getline(fichier, ville)){
           	_villeP.push_back(ville);
        }
        fichier.close();
    }

    std::ifstream fichier2("villeM.txt", std::ios::in);  
	if(fichier2)  
	{

       	while(getline(fichier2, ville)){
           	_villeM.push_back(ville);
        }
        fichier2.close();
    }

    std::ifstream fichier3("villeG.txt", std::ios::in);  
	if(fichier3)  
	{ 
       	while(getline(fichier3, ville)){
           	_villeG.push_back(ville);
        }
        fichier3.close();
    }


}


std::string Lieu:: villeP(){
	int index;
	index = rand()%(_villeP.size());
	return _villeP[index];
}
	

std::string Lieu:: villeM(){
	int index;
	index = rand()%(_villeM.size());
	return _villeM[index];
}

std::string Lieu:: villeG(){
	int index;
	index = rand()%(_villeG.size());
	return _villeG[index];
}
