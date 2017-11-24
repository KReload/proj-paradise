#pragma once
#include <string>

class Transaction
{
public:
    Transaction();
    Transaction(std::string nom, int montant, std::string lieux, float preussite);
    virtual std::string toString() = 0;
    virtual int evaluate() = 0;

protected:
    std::string _nom;
    int _montant;
    std::string _lieux;
    float _preussite;
};