#include "transaction_debutant.hh"
#include <iostream>
#include <ctime>
#include "lieux.hh"
#include "message.hh"
#include "nom.hh"
#include "joueur_debutant.hh"
#include "joueur_medium.hh"

int main()
{
    std::cout <<"    ____        _       _______            _         _____ _                 _       _              "<< std::endl;
    std::cout <<"   |  _ \\      | |     |__   __|          | |       / ____(_)               | |     | |             "<< std::endl;
    std::cout <<"   | |_) | ___ | |__      | |_ __ __ _  __| | ___  | (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __  "<< std::endl;
    std::cout <<"   |  _ < / _ \\| '_ \\     | | '__/ _` |/ _` |/ _ \\  \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__| "<< std::endl;
    std::cout <<"   | |_) | (_) | |_) |    | | | | (_| | (_| |  __/  ____) | | | | | | | |_| | | (_| | || (_) | |    "<< std::endl;
    std::cout <<"   |____/ \\___/|_.__/     |_|_|  \\__,_|\\__,_|\\___| |_____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|    "<< std::endl;
    std::cout << "                                                        Money is power \n" << std::endl;
    srand(time(NULL));
    Lieu l;
    Message m;
    Nom n;


    Joueur_debutant d;
    Joueur * j;
    j=&d;
    Joueur_medium m(d);

    while(j->capital()>0){
    	j->jouer();
    	if(j->capital()>50000){
    		m.maj(d);
    		j= &m;
    	}
    }

    return 1;
}