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
    Joueur_debutant j;
    while(j.capital()>0){
    	j.jouer();
    }
    return 1;
}