#include "transaction_expert.hh"
#include <cstdlib>
#include <string>

/**
 * \fn TransactionExpert()
 * \brief Création transaction expert aléatoire
 * \return Retourne rien
 */
TransactionExpert::TransactionExpert() : Transaction()
{
    _montant = (rand()%10 + 1)*100000;
    _lieux= Lieu::villeM();
    _nom = Nom::nomM();
    _preussite = 100-(_montant/100000*4)-(rand()%50);
}


/**
 * \fn toString()
 * \brief Retourne les paramètres d'une transaction
 * \return Chaine de caractère
 */
std::string TransactionExpert::toString()
{
    std::string description = _nom;
    int i;
    //alignement des noms
    for(i=_nom.length();i<17;i++){
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
    description += "\n------------------------------------------------------------------------------------------------------------------";

    return description;
}

/**
 * \fn TransactionExpert()
 * \brief Evalue si la transaction est réussie ou non
 * \return Retourne le montant gagné ou perdu
 */
int TransactionExpert::evaluate()
{
	if((rand()%100)>_preussite){
		return -_montant;
	}
    return _montant+rand()%5*_montant/10;
}

/**
 * \fn montant()
 * \brief 
 * \return Retourne le montant de la transaction
 */
int TransactionExpert::montant()
{
    return _montant;
}

