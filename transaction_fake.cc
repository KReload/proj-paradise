#include "transaction_fake.hh"
#include <cstdlib>
#include <string>

TransactionFake::TransactionFake() : TransactionDebutant()
{
    _suspicionRate = _montant(rand()%10);
}




