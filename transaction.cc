#include "transaction.hh"

Transaction::Transaction():_nom(""),_montant(0),_lieux(""),_preussite(0){};
Transaction::Transaction(std::string nom, int montant, std::string lieux, float preussite)
:_nom(nom), _montant(montant),_lieux(lieux),_preussite(preussite) 
{}