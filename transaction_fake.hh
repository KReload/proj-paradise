#pragma once
#include "transaction.hh"

class TransactionFake : public Transaction
{
public:
    TransactionFake();
    std::string toString();
    int evaluate();
    int montant();
    int suspicion()
protected:
    int _suspicionRate;
};