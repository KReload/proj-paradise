#pragma once
#include "transaction.hh"

class TransactionExpert : public Transaction
{
public:
    TransactionExpert();
    std::string toString();
    int evaluate();
    int montant();
};