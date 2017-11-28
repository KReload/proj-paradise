#include "transaction_debutant.hh"
#include <cstdlib>
#include <string>

TransactionDebutant::TransactionDebutant() : Transaction()
{
    _montant = (rand()%10 + 1)*1000;
    _nom = std::string("PetiteTransacName");
    _lieux = Lieu:: villeP();

}

std::string TransactionDebutant::toString()
{
    std::string description = "\n~Petite Transaction~";
    description += "\n";
    description += _nom;
    description += "\nLocaux situes a ";
    description += _lieux;
    description += "\n";
    description += std::to_string(_montant); 

    return description;
}

int TransactionDebutant::evaluate()
{
    return _montant;
}