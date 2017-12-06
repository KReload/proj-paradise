#include "transaction_debutant.hh"
#include <iostream>
#include <ctime>
#include <unistd.h>
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
    Message a;
    Nom n;


    Joueur_debutant d;
    Joueur * j;
    j=&d;
    Joueur_medium m(d);
    int i=1;
    std::cout<<"\n Vous venez d'être engagé chez Poly Bankers Agency, vous êtes un stagiaire qui cherche à faire ses preuves" << std::endl;
    std::cout <<" dans le monde hostile du trading. Vous commencez avec un capital de "<<d.capital()<<" € et vous espérez en sortir riche et beau." << std::endl;
    std::cout <<" Bienvenue dans la famille et souvenez vous, aucune transaction est gagnée d'avance ...\n"<<std::endl;
    sleep(5);
    while(j->capital()>0){
    	j->jouer();
    	if(j->capital()>50000 and i==1){
    		i=0;
    		m.maj(d);
    		j= &m;
    		std::cout<<"Bien joué!! Le patron t'as promu."<<std::endl;
    	}
    	if(i==0 and j->suspicion()>100){
	    	std::cout <<"suspicion a + de 100%"<<std::endl;	
    		break;
    	}
    }

    return 1;
}