#pragma once
#include "transaction.hh"

class TransactionDebutant : public Transaction
{
public:
    TransactionDebutant();
    std::string toString();
    int evaluate();
};

