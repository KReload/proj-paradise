#include "nom.hh"
#include <fstream>
#include <iostream>
#include <string>

std::vector<std::string> Nom::_nomP;
std::vector<std::string> Nom::_nomM;
std::vector<std::string> Nom::_nomG;


Nom::Nom(){
	std::string nom;
	std::ifstream fichier("nomP.txt", std::ios::in);  // on ouvre en lecture
	if(fichier)  // si l'ouverture a fonctionné
	{
 
       	while(getline(fichier, nom)){
           	Nom::_nomP.push_back(nom);
        }
        fichier.close();
    }

    std::ifstream fichier2("nomM.txt", std::ios::in);  
	if(fichier2)  
	{

       	while(getline(fichier2, nom)){
			Nom::_nomM.push_back(nom);
        }
        fichier2.close();
    }

    std::ifstream fichier3("nomG.txt", std::ios::in);  
	if(fichier3)  
	{ 
       	while(getline(fichier3, nom)){
			Nom::_nomG.push_back(nom);
        }
        fichier3.close();
    }


}


std::string Nom:: nomP(){
  int index;
  if(!Nom::_nomP.empty())
  {
    index = rand()%(Nom::_nomP.size());
    return Nom::_nomP[index];
  }
  return std::string("");
}
  

std::string Nom:: nomM(){
  int index;
  if(!Nom::_nomP.empty())
  {
    index = rand()%(Nom::_nomM.size());
    return Nom::_nomM[index];
  }
  return std::string("");
}

std::string Nom:: nomG(){
  int index;
  if(!Nom::_nomG.empty())
  {
    index = rand()%(Nom::_nomG.size());
    return Nom::_nomG[index];

  }
  return std::string("");
}