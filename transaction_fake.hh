#pragma once
#include "transaction_debutant.hh"

class TransactionFake : public TransactionDebutant
{
public:
    TransactionFake();
    std::string toString();
    int evaluate();
    int montant();
protected:
    int _suspicionRate;
};