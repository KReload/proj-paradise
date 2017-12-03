#include "transaction_debutant.hh"
#include <cstdlib>
#include <string>

TransactionDebutant::TransactionDebutant() : Transaction()
{
    _montant = (rand()%10 + 1)*1000;
<<<<<<< HEAD
    _nom = std::string("PetiteTransacName");
    _lieux = Lieu:: villeP();

=======
    _lieux= Lieu::villeP();
    _nom = Nom::nomP();
    _preussite = 100-(_montant/1000*4)-(rand()%30);
>>>>>>> dd62fe29ed9d157d085277ee89ff245cc5c067e1
}

std::string TransactionDebutant::toString()
{
<<<<<<< HEAD
    std::string description = "\n~Petite Transaction~";
    description += "\n";
    description += _nom;
    description += "\nLocaux situes a ";
=======
    std::string description = _nom;
    description += "\t|\t";
>>>>>>> dd62fe29ed9d157d085277ee89ff245cc5c067e1
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
