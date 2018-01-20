#include "transaction_expert.hh"
#include <cstdlib>
#include <string>

TransactionExpert::TransactionExpert() : Transaction()
{
    _montant = (rand()%10 + 1)*100000;
    _lieux= Lieu::villeM();
    _nom = Nom::nomM();
    _preussite = 100-(_montant/100000*4)-(rand()%50);
}


std::string TransactionExpert::toString()
{
    std::string description = _nom;
    int i;
    //alignement des noms
    for(i=_lieux.length();i<7;i++){
        description +=" ";
    }
    description += "\t|\t";
    description += _lieux;
    int j;
    for(j=_lieux.length();j<17;j++){
        description +=" ";
    }
    description += "\t|\t";
    description += std::to_string(_montant);
    description += "\t\t|\t";
    description += std::to_string((int)_preussite); 
    description += "%";
    description += "\n-----------------------------------------------------------------------------------------------------";

    return description;
}

int TransactionExpert::evaluate()
{
	if((rand()%100)>_preussite){
		return -_montant;
	}
    return _montant+rand()%5*_montant/10;
}

int TransactionExpert::montant()
{
    return _montant;
}

