#include "transaction_debutant.hh"
#include <iostream>
#include <ctime>
#include "lieux.hh"
#include "nom.hh"
#include "joueur_debutant.hh"
#include "joueur_medium.hh"

int main()
{
    srand(time(NULL));
    Lieu l;
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