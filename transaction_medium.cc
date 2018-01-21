#include "transaction_medium.hh"
#include <cstdlib>
#include <string>


/**
 * \fn TransactionMedium()
 * \brief Création d'une transaction medium
 *
 * \return Retourne rien
 */
TransactionMedium::TransactionMedium() : Transaction()
{
    _montant = (rand()%10 + 1)*10000;
    _lieux= Lieu::villeM();
    _nom = Nom::nomM();
    _preussite = 100-(_montant/10000*4)-(rand()%30);
}


/**
 * \fn toString()
 * \brief Retourne les paramètres d'une transaction
 *
 * \return Chaine de caractère
 */
std::string TransactionMedium::toString()
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
 * \fn evaluate()
 * \brief Evalue si la transaction est réussie ou non
 *
 * \return Retourne le montant gagné ou perdu
 */
int TransactionMedium::evaluate()
{
	if((rand()%100)>_preussite){
		return -_montant;
	}
    return _montant+rand()%5*_montant/10;
}


/**
 * \fn montant()
 * \brief
 *
 * \return Retourne le montant de la transaction
 */
int TransactionMedium::montant()
{
    return _montant;
}

