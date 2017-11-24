#include "transaction_debutant.hh"
#include <iostream>
#include <ctime>
#include "lieux.hh"

int main()
{
    srand(time(NULL));
    Lieu l;
    std::cout<<l.villeP()<<std::endl;
    TransactionDebutant a;
    std::cout << a.toString() << a.evaluate()<<std::endl;
    return 1;
}