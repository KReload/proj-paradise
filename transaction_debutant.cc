#include "transaction_debutant.hh"
#include <cstdlib>
#include <string>

TransactionDebutant::TransactionDebutant() : Transaction()
{
    _montant = (rand()%10 + 1)*1000;
    _nom = std::string("ok");
    
}

std::string TransactionDebutant::toString()
{
    return _nom;
}

int TransactionDebutant::evaluate()
{
    return _montant;
}