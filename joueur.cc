#include "joueur.hh"
#include <string>

Joueur::Joueur():_nom(""),_capital(1){

}

int Joueur:: suspicion(){
	return 0;
}

int Joueur:: score(){
	return 0;
}

void Joueur::operator+=(int montant)
{
	_capital+=montant;
	return;
}