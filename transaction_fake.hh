#pragma once
#include "transaction.hh"

class TransactionFake : public Transaction
{
public:
    TransactionFake(int i);
    std::string toString();
    int evaluate();
    int montant();
    int suspicion();
protected:
    float _suspicionRate;
};