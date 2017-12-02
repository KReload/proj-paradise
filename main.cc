#include "transaction_debutant.hh"
#include <iostream>
#include <ctime>
#include "lieux.hh"
#include "nom.hh"

int main()
{
    srand(time(NULL));
    Lieu l;
    Nom n;
    TransactionDebutant a;
    std::cout << a.toString() <<std::endl;
    std::cout << a.evaluate() <<std::endl;
    std::cout << a.montant() <<std::endl;
    return 1;
}