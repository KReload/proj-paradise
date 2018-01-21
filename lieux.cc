#include "lieux.hh"
#include <fstream>
#include <iostream>
#include <string>


//initialisation des vector des villes trié par taille
std::vector<std::string> Lieu::_villeP;
std::vector<std::string> Lieu::_villeM;
std::vector<std::string> Lieu::_villeG;

/**
 * \fn Lieu()
 * \brief lecture des fichier pour completer les vectors
 *
 * \return
 */
Lieu::Lieu(){
	std::string ville;
	std::ifstream fichier("villeP.txt", std::ios::in);  // on ouvre en lecture
	if(fichier)  // si l'ouverture a fonctionné
	{
 
       	while(getline(fichier, ville)){ //lit toutes les villes et on le ajoute au bon vector
           	Lieu::_villeP.push_back(ville);
        }
        fichier.close();
    }
    //et on repete le processus pour les 2 autres tailles de ville
    std::ifstream fichier2("villeM.txt", std::ios::in);  
	if(fichier2)  
	{

       	while(getline(fichier2, ville)){
			Lieu::_villeM.push_back(ville);
        }
        fichier2.close();
    }

    std::ifstream fichier3("villeG.txt", std::ios::in);  
	if(fichier3)  
	{ 
       	while(getline(fichier3, ville)){
			Lieu::_villeG.push_back(ville);
        }
        fichier3.close();
    }


}


/**
 * \fn villeP()
 * \brief tire au sort une ville
 *
 * \return retourne le nom de la ville tiré au hazard
 */
std::string Lieu:: villeP(){
	int index;
	if(!Lieu::_villeP.empty())
	{
		index = rand()%(Lieu::_villeP.size());
		return Lieu::_villeP[index];
	}
	return std::string("");
}
	
/**
 * \fn villeM()
 * \brief tire au sort une ville
 *
 * \return retourne le nom de la ville tiré au hazard
 */
std::string Lieu:: villeM(){
	int index;
	if(!Lieu::_villeM.empty())
	{
		index = rand()%(Lieu::_villeM.size());
		return Lieu::_villeM[index];
	}
	return std::string("");
}

/**
 * \fn villeG()
 * \brief tire au sort une ville
 *
 * \return retourne le nom de la ville tiré au hazard
 */
std::string Lieu:: villeG(){
	int index;
	if(!Lieu::_villeG.empty())
	{
		index = rand()%(Lieu::_villeG.size());
		return Lieu::_villeG[index];

	}
	return std::string("");
}


/**
 * \fn isM(std::string s)
 * \brief verifie si la ville est bien dans la liste
 *
 * \param s nom de la ville que l'on veut tester
 * \return retourne true si le nom a été trouvé false sinon
 */
bool Lieu::isM(std::string s){
  if(std::find(Lieu::_villeM.begin(),Lieu::_villeM.end(),s) != Lieu::_villeM.end()){
    return true;
  }
  return false;
}


/**
 * \fn isG(std::string s)
 * \brief verifie si la ville est bien dans la liste
 *
 * \param s nom de la ville que l'on veut tester
 * \return retourne true si le nom a été trouvé false sinon
 */
bool Lieu::isG(std::string s){
  if(std::find(Lieu::_villeG.begin(),Lieu::_villeG.end(),s) != Lieu::_villeG.end()){
    return true;
  }
  return false;
}

/**
 * \fn isP(std::string s)
 * \brief verifie si la ville est bien dans la liste
 *
 * \param s nom de la ville que l'on veut tester
 * \return retourne true si le nom a été trouvé false sinon
 */
bool Lieu::isP(std::string s){
  if(std::find(Lieu::_villeP.begin(),Lieu::_villeP.end(),s) != Lieu::_villeP.end()){
    return true;
  }
  return false;
}