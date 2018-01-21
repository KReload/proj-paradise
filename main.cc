#include "transaction_debutant.hh"
#include "event_surprise.hh"
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "lieux.hh"
#include "message.hh"
#include "nom.hh"
#include "joueur_debutant.hh"
#include "joueur_medium.hh"
#include "joueur_expert.hh"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

/**
 * \fn main()
 * \brief lancement du programme
 *
 * \return
 */
int main()
{


    std::cout <<KBLU<<"    ____        _       _______            _         _____ _                 _       _              "<< std::endl;
    std::cout <<"   |  _ \\      | |     |__   __|          | |       / ____(_)               | |     | |             "<< std::endl;
    std::cout <<"   | |_) | ___ | |__      | |_ __ __ _  __| | ___  | (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __  "<< std::endl;
    std::cout <<"   |  _ < / _ \\| '_ \\     | | '__/ _` |/ _` |/ _ \\  \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__| "<< std::endl;
    std::cout <<"   | |_) | (_) | |_) |    | | | | (_| | (_| |  __/  ____) | | | | | | | |_| | | (_| | || (_) | |    "<< std::endl;
    std::cout <<"   |____/ \\___/|_.__/     |_|_|  \\__,_|\\__,_|\\___| |_____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|    "<< std::endl;
    std::cout << "                                                        Money is power \xa9 \n" <<KNRM<< std::endl;
    srand(time(NULL));
    // Initialisation des fichiers Lieux, Events, Messages et Noms
    Lieu l;
    EventSurprise event;
    Message a;
    Nom n;
    //initialisation des différents niveaux de joueur
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
    //boucle de jeu
    while(j->capital()>0){
        //fait tour de jeu
    	j->jouer();
    	if(j->capital()>50000 and i==1){ //test si on peut passer au niveau suivant
    		i=0;
    		m.maj(d); //met a jour les paramètre du joueur du niveau superieur avec ce du joueur actuel
    		j= &m;
            std::cout << "\x1B[2J\x1B[H"<<std::endl;//clear de l'ecran

            std::cout<<"\n\nBRAVO !!!! \n\nLe patron t'as embauché en tant que trader tu n'es plus un stagiaire.\n"<<std::endl;
            std::cout<<"\nTu viens de débloquer de nouvelles compétences:\n-Tu peux maintenant voir, grâce ton expérience, la probabilité de réussite des transactions\n-Tu peux faire des fausses transactions\n"<<std::endl;
            sleep(5);
            std::cout << "\n\n\nPour effectuer une fausse transaction appuie sur 0 au moment du choix des transactions et suis les instructions\n\n"<<std::endl;
            sleep(5);
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t tape OK pour continuer\n"<<std::endl;
            //attente de l'utilisateur avant de continuer
            std::cin>>tmp;
        }
        if(exp == 0 and i==0 and j->score()>200000){
            exp = 1;
            //met a jour les paramètre du joueur du niveau superieur avec ce du joueur actuel
    		e.maj(m);
    		j= &e;
            std::cout << "\x1B[2J\x1B[H"<<std::endl;//clear de l'ecran

    		std::cout<<"\n\nBRAVO !!!! \n\nLe patron t'as nommé chef de l'équipe de trading.\n"<<std::endl;
            std::cout<<"\nTu viens de débloquer de nouvelles compétences:\n-Tu peux maintenant voir, grâce ton expérience, le taux de suspicion que la brigade anti-fraude à sur toi\n-Tu peux maintenant avoir l'opportunité de réduire ton taux de suspicion alors reste attentif.\n"<<std::endl;
            sleep(5);
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Tape OK pour continuer\n"<<std::endl;
            //attente de l'utilisateur avant de continuer
            std::cin>>tmp;
    	}
    	if(i==0 and j->suspicion()>100){//test si le taux de suspicion dépace 100%
	    	std::cout <<KRED<<"La police viens vous arréter à cause de vos détournements de fond!"<<KNRM<<std::endl;	
    		break;
        }
        
    }


std::cout<<"Vous avez perdu, vous avez fait un score de " << j->score() << "\n\n";

std::cout<<KRED<<"    ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███      ▐██▌     ▐██▌     ▐██▌ "<<std::endl;
std::cout<<"   ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒    ▐██▌     ▐██▌     ▐██▌ "<<std::endl;
std::cout<<"  ▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒    ▐██▌     ▐██▌     ▐██▌ "<<std::endl;
std::cout<<"  ░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄      ▓██▒     ▓██▒     ▓██▒ "<<std::endl;
std::cout<<"  ░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒    ▒▄▄      ▒▄▄      ▒▄▄  "<<std::endl;
std::cout<<"   ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░    ░▀▀▒     ░▀▀▒     ░▀▀▒ "<<std::endl;
std::cout<<"    ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░    ░  ░     ░  ░     ░  ░ "<<std::endl;
std::cout<<"  ░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░        ░        ░        ░ "<<std::endl;
std::cout<<"        ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░         ░        ░        ░    "<<KNRM<<std::endl;
                                                                                                  




    return 1;
}