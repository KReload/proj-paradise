#include "event_surprise.hh"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

std::map<int,std::string> EventSurprise::_eventText;
std::map<int,int> EventSurprise::_eventPoints;
std::map<int,int> EventSurprise::_question;

EventSurprise::EventSurprise() {
    std::string line;
    std::string eventText;
    std::istringstream isline;
    int question;
    int eventPoints;
    std::ifstream fichier("events.txt", std::ios::in);  // on ouvre en lecture
    int i = 0;
    if(fichier){ // Si l'ouverture fonction
       	while(getline(fichier, line)){
            isline.clear();
            isline.str(line);
            isline >> question >> eventPoints; 
            getline(isline, eventText);
            _eventText[i] = eventText; 
            _eventPoints[i] =  eventPoints;
            _question[i] =  question;
            i+=1;
        }
        fichier.close();
    }
}

int EventSurprise:: eventDeclenche(){
    int index;
    int answer = 2;
	if(!EventSurprise::_eventText.empty()) {
        index = rand()%(EventSurprise::_eventText.size());
        std::cout << EventSurprise::_eventText[index];
        while(answer!= 0 && answer!=1) {
            if(answer!= 0 && answer!=1)
            {
                std::cout << "\n\n\n\nVous acceptez (tapez 1), vous refusez (tapez 0)\n";
            }
            std::cin >> answer;
        }
        if(answer == _question[index]) {
            std::cout << "Vous avez fait le bon choix ! Vous gagnez " << _eventPoints[index] << "points\n";
            return -_eventPoints[index];
        } else {
            std::cout << "Oh non !! Vous avez fait une grave erreur, MALUS!! \n";
            return rand()%30;
        }
        
	}
	return 0;
}