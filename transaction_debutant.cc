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
    int j;
    //alignement des nom
    for(j=_nom.length();j<17;j++){
        description +=" ";
    }
    description += "\t|\t";
    description += _lieux;
    int i;
    for(i=_lieux.length();i<18;i++){
        description +=" ";
    }
    description += "\t|\t";
    description += std::to_string(_montant); 
    description += "\n-----------------------------------------------------------------------------------------";
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
