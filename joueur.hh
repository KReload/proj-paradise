#pragma once
#include <string>
#include <iostream>
#include "lieux.hh"
#include "nom.hh"
#include "transaction_debutant.hh"

class Joueur
{
public:
    Joueur();
    
    virtual int capital() = 0;
    virtual void jouer() = 0;


protected:
    std::string _nom;
    int _capital;
};
