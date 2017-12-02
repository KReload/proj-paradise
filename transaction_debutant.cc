#include "transaction_debutant.hh"
#include <cstdlib>
#include <string>

TransactionDebutant::TransactionDebutant() : Transaction()
{
    _montant = (rand()%10 + 1)*1000;
    _lieux= Lieu::villeP();
    _nom = Nom::nomP();
    _preussite = 100-(_montant/1000*5)-(rand()%30);
}

std::string TransactionDebutant::toString()
{
    std::string description = "\n~Petite Transaction~";
    description += "\n";
    description += _nom;
    description += "\nLocaux situés à ";
    description += _lieux;
    description += "\n";
    description += std::to_string(_montant); 

    return description;
}

int TransactionDebutant::evaluate()
{
	if((rand()%100)>_preussite){
		return -_montant;
	}
    return _montant/2+rand()%5*_montant/10;
}

int TransactionDebutant::montant()
{
    return _montant;
}
