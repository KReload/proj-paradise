#pragma once
#include "joueur.hh"
#include "transaction_medium.hh"
#include "joueur_debutant.hh"
#include "transaction_fake.hh"

class Joueur_medium :public Joueur_debutant{
	public:
		Joueur_medium(Joueur_debutant & j);
		void jouer();
		int capital();
		void maj(Joueur_debutant &j);
	private:
		int taux_suspicion;
		int score;

};