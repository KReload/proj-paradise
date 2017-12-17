#pragma once
#include "transaction.hh"

class TransactionFake : public Transaction
{
public:
    TransactionFake();
    TransactionFake(int i);
    std::string toString();
    int evaluate();
    int montant();
    int suspicion();
protected:
    int _suspicionRate;
};