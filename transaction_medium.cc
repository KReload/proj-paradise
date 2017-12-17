#include "transaction_medium.hh"
#include <cstdlib>
#include <string>

TransactionMedium::TransactionMedium() : Transaction()
{
    _montant = (rand()%10 + 1)*10000;
    _lieux= Lieu::villeM();
    _nom = Nom::nomM();
    _preussite = 100-(_montant/10000*4)-(rand()%30);
}


std::string TransactionMedium::toString()
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

int TransactionMedium::evaluate()
{
	if((rand()%100)>_preussite){
		return -_montant;
	}
    return _montant+rand()%5*_montant/10;
}

int TransactionMedium::montant()
{
    return _montant;
}

