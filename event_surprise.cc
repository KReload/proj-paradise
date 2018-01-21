#include "event_surprise.hh"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>


//definition pour afficher en couleur dans le terminal
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

//trois map pour stocker les évènements (leur texte, leur récompense, et leur bonne réponse)
std::map<int,std::string> EventSurprise::_eventText;
std::map<int,int> EventSurprise::_eventPoints;
std::map<int,int> EventSurprise::_question;

/**
 * \fn EventSurprise()
 * \brief Fonction qui lit le fichier events.txt et charge les evenement dans les map. (executé une seul fois)
 *
 * \return rien.
 */
EventSurprise::EventSurprise() {
    std::string line;
    std::string eventText;
    std::istringstream isline;
    int question;
    int eventPoints;
    std::ifstream fichier("events.txt", std::ios::in);  // on ouvre en lecture
    int i = 0;
    if(fichier){ // Si l'ouverture fonction
       	while(getline(fichier, line)){//parcours tout le fichier
            isline.clear();
            isline.str(line);
            isline >> question >> eventPoints; 
            getline(isline, eventText);
            //ajoute l'evenement et tous ses composants au maps
            _eventText[i] = eventText; 
            _eventPoints[i] =  eventPoints;
            _question[i] =  question;
            i+=1;
        }
        fichier.close();
    }
}


/**
 * \fn eventDeclenche()
 * \brief Fonction qui selectionne un evenement au hazard dans tous les events et l'execute.
 * \return un entier signifiant la variation à applique du taux de suspicion.
 */
int EventSurprise:: eventDeclenche(){
    int index;
    int answer = 2;
	if(!EventSurprise::_eventText.empty()) {//vérifie qu'il y a bien des évènements à proposer
        index = rand()%(EventSurprise::_eventText.size()); //tire au hazard un evenement
        std::cout << EventSurprise::_eventText[index];  //affiche le texte de l'evenement
        while(answer!= 0 && answer!=1) {//on attend d'avoir une réponse
            if(answer!= 0 && answer!=1)
            {
                std::cout << "\n\n\n\nVous acceptez (tapez 1), vous refusez (tapez 0)\n"<<std::endl;
            }
            std::cin >> answer;
        }
        if(answer == _question[index]) {//si  la reponse est celle attendu affiche des felicitation et on retourne la variation du taux de suspicion à appliquer
            std::cout <<KGRN<< "Vous avez fait le bon choix ! Votre suspicion est réduite de " << _eventPoints[index] << "%\n"<<KNRM<<std::endl;
            return -_eventPoints[index];
        } else {//sinon on retourne une augmentation du taux de suspicion aleatoire
            std::cout <<KRED<< "Oh non !! Vous avez fait une grave erreur, vous etes dans le colimateur!! \n"<<KNRM<<std::endl;
            return rand()%30;
        }
        
	}
	return 0;
}