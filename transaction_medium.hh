#pragma once
#include "transaction.hh"

class TransactionMedium : public Transaction
{
public:
    TransactionMedium();
    std::string toString();
    int evaluate();
    int montant();
};