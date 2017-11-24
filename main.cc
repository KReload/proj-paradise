#include "transaction_debutant.hh"
#include <iostream>
#include <ctime>
#include "lieux.hh"

int main()
{
    srand(time(NULL));
    TransactionDebutant a;
    std::cout << a.toString() << a.evaluate();
    return 1;
}