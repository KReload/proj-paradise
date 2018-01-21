#include "message.hh"
#include <fstream>
#include <iostream>
#include <string>

//initialisation des vector des message trié par taille
std::vector<std::string> Message::_messageP;
std::vector<std::string> Message::_messageM;
std::vector<std::string> Message::_messageG;



/**
 * \fn Message()
 * \brief lecture des fichier pour completer les vectors
 *
 * \return
 */
Message::Message(){
	std::string message;
	std::ifstream fichier("messageP.txt", std::ios::in);  // on ouvre en lecture
	if(fichier)  // si l'ouverture a fonctionné
	{
 
       	while(getline(fichier, message)){//lit toutes les messages et on le ajoute au bon vector
           	Message::_messageP.push_back(message);
        }
        fichier.close();
    }
    //et on repete le processus pour les 2 autres tailles de message
    std::ifstream fichier2("messageM.txt", std::ios::in);  
	if(fichier2)  
	{

       	while(getline(fichier2, message)){
			Message::_messageM.push_back(message);
        }
        fichier2.close();
    }

    std::ifstream fichier3("messageG.txt", std::ios::in);  
	if(fichier3)  
	{ 
       	while(getline(fichier3, message)){
			Message::_messageG.push_back(message);
        }
        fichier3.close();
    }


}

/**
 * \fn MessageP()
 * \brief tire au sort un message
 *
 * \return retourne le nom du message tiré au hazard
 */
std::string Message:: MessageP(){
  int index;
  if(!Message::_messageP.empty())
  {
    index = rand()%(Message::_messageP.size());
    return Message::_messageP[index];
  }
  return std::string("");
}
  
/**
 * \fn MessageM()
 * \brief tire au sort un message
 *
 * \return retourne le nom du message tiré au hazard
 */
std::string Message:: MessageM(){
  int index;
  if(!Message::_messageM.empty())
  {
    index = rand()%(Message::_messageM.size());
    return Message::_messageM[index];
  }
  return std::string("");
}

/**
 * \fn MessageG()
 * \brief tire au sort un message
 *
 * \return retourne le nom du message tiré au hazard
 */
std::string Message:: MessageG(){
  int index;
  if(!Message::_messageG.empty())
  {
    index = rand()%(Message::_messageG.size());
    return Message::_messageG[index];

  }
  return std::string("");
}