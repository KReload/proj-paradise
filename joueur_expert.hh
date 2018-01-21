#pragma once
#include "joueur.hh"
#include "transaction_expert.hh"
#include "joueur_medium.hh"
#include "transaction_fake.hh"
#include "message.hh"

class Joueur_expert :public Joueur_medium{
public:
    Joueur_expert(Joueur_medium & j);
    void jouer();
    void eval(int res,int montant);
    void fake();
    int capital();
    void maj(Joueur_medium &j);
    int suspicion();
    int score();
private:
    float _taux_suspicion;
    int _score;

};