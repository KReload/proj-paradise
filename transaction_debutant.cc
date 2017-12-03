#include "transaction_debutant.hh"
#include <cstdlib>
#include <string>

TransactionDebutant::TransactionDebutant() : Transaction()
{
    _montant = (rand()%10 + 1)*1000;
    _lieux= Lieu::villeP();
    _nom = Nom::nomP();
    _preussite = 100-(_montant/1000*4)-(rand()%30);
}

std::string TransactionDebutant::toString()
{
    std::string description = _nom;
    description += "\t|\t";
    description += _lieux;
    description += "\t|\t";
    description += std::to_string(_montant); 

    return description;
}

int TransactionDebutant::evaluate()
{
	if((rand()%100)>_preussite){
		return -_montant;
	}
    return _montant+rand()%5*_montant/10;
}

int TransactionDebutant::montant()
{
    return _montant;
}
