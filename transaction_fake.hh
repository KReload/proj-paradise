#pragma once
#include "transaction.hh"
#include <iostream>

class TransactionFake : public Transaction
{
public:
    TransactionFake(int i);
    friend std::ostream& operator<<(std::ostream& os, TransactionFake& fake);
    std::string toString();
    int evaluate();
    int montant();
    int suspicion();
    void medium();
    void expert();
protected:
    float _suspicionRate;
};
