#include "transaction_debutant.hh"
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "lieux.hh"
#include "message.hh"
#include "nom.hh"
#include "joueur_debutant.hh"
#include "joueur_medium.hh"
#include "joueur_expert.hh"


int main()
{
    std::cout <<"    ____        _       _______            _         _____ _                 _       _              "<< std::endl;
    std::cout <<"   |  _ \\      | |     |__   __|          | |       / ____(_)               | |     | |             "<< std::endl;
    std::cout <<"   | |_) | ___ | |__      | |_ __ __ _  __| | ___  | (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __  "<< std::endl;
    std::cout <<"   |  _ < / _ \\| '_ \\     | | '__/ _` |/ _` |/ _ \\  \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__| "<< std::endl;
    std::cout <<"   | |_) | (_) | |_) |    | | | | (_| | (_| |  __/  ____) | | | | | | | |_| | | (_| | || (_) | |    "<< std::endl;
    std::cout <<"   |____/ \\___/|_.__/     |_|_|  \\__,_|\\__,_|\\___| |_____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|    "<< std::endl;
    std::cout << "                                                        Money is power \xa9 \n" << std::endl;
    srand(time(NULL));
    Lieu l;
    Message a;
    Nom n;
    Joueur_debutant d;
    Joueur * j;
    j=&d;
    Joueur_medium m(d);
    Joueur_expert e(m);
    std::string tmp;
    int i=1;
    int exp = 0;
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
            std::cout << "\x1B[2J\x1B[H"<<std::endl;

            std::cout<<"\n\nBRAVO !!!! \n\nLe patron t'as embauché en tant que trader tu n'es plus un stagiaire.\n"<<std::endl;
            std::cout<<"\nTu viens de débloquer de nouvelles compétences:\n-tu peux maintenant voir, grâce ton expérience, la probabilité de réussite des transactions\n-tu peux faire des fausses transactions\n"<<std::endl;
            sleep(5);
            std::cout << "\n\n\nPour effectuer une fausse transaction appuie sur 0 au moment du choix des transactions et suis les instructions\n\n"<<std::endl;
            sleep(5);
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t tape OK pour continuer\n"<<std::endl;
            std::cin>>tmp;
        }
        if(exp == 0 and i==0 and j->score()>200000){
            exp = 1;
    		e.maj(m);
    		j= &e;
            std::cout << "\x1B[2J\x1B[H"<<std::endl;

    		std::cout<<"\n\nBRAVO !!!! \n\nLe patron t'as nommé chef de l'équipe de trading.\n"<<std::endl;
            std::cout<<"\nTu viens de débloquer de nouvelles compétences:\n-tu peux maintenant voir, grâce ton expérience, le taux de suspicion que la brigade anti-fraude à sur toi\n-tu peux maintenant avoir l'opportunité de réduire ton taux de suspicion alors reste attentif.\n"<<std::endl;
            sleep(5);
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t tape OK pour continuer\n"<<std::endl;
            std::cin>>tmp;
    	}
    	if(i==0 and j->suspicion()>100){
	    	std::cout <<"suspicion a + de 100%"<<std::endl;	
    		break;
        }
        
    }


    return 1;
}