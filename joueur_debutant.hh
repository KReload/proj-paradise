#pragma once
#include "joueur.hh"
#include "transaction_debutant.hh"

class Joueur_debutant :public Joueur{
	public:
		Joueur_debutant();
		Joueur_debutant(Joueur_debutant &);
		void jouer();
		int capital();
		std::string nom();
	

};