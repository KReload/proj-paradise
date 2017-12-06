#include "transaction_debutant.hh"
#include <iostream>
#include <ctime>
#include "lieux.hh"
#include "nom.hh"
#include "joueur_debutant.hh"

int main()
{
    srand(time(NULL));
    Lieu l;
    Nom n;
    Joueur_debutant d;
    Joueur * j;
    j=&d;
    while(j->capital()>0){
    	j->jouer();
    	if(j->capital()>50000){


    	}
    }
    return 1;
}