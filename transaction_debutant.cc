#include "transaction_debutant.hh"
#include <cstdlib>
#include <string>

/**
 * \fn TransactionDebutant()
 * \brief Création d'une transaction débutante aléatoire
 *
 * \return rien.
 */
TransactionDebutant::TransactionDebutant() : Transaction()
{
    _montant = (rand()%10 + 1)*1000;
    _lieux= Lieu::villeP();
    _nom = Nom::nomP();
    _preussite = 100-(_montant/1000*4)-(rand()%30);
}


/**
 * \fn toString()
 * \brief Affiche les paramètres de la transaction
 *
 * \return La chaine de caractères correspondante.
 */
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
    for(i=_lieux.length();i<17;i++){
        description +=" ";
    }
    description += "\t|\t";
    description += std::to_string(_montant); 
    description += "\n-----------------------------------------------------------------------------------------";
    return description;
}


/**
 * \fn evaluate()
 * \brief Regarde si la transaction a réussi
 * \return Retourne le montant gagné ou perdu
 */
int TransactionDebutant::evaluate()
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
int TransactionDebutant::montant()
{
    return _montant;
}
