#pragma once
#include "transaction.hh"

class TransactionFake : public Transaction
{
public:
    TransactionFake();
    std::string toString();
    int evaluate();
    int montant();
protected:
    int _suspicionRate;
};