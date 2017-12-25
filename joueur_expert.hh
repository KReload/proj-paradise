#pragma once
#include "joueur.hh"
#include "transaction_medium.hh"
#include "joueur_medium.hh"
#include "transaction_fake.hh"
#include "message.hh"

class Joueur_expert :public Joueur_medium{
public:
    Joueur_expert(Joueur_medium & j);
    void jouer();
    int capital();
    void maj(Joueur_medium &j);
    int suspicion();
private:
    int _taux_suspicion;
    int _score;

};