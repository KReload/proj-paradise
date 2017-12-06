#include "transaction_fake.hh"
#include <iostream>
#include <cstdlib>
#include <string>

TransactionFake::TransactionFake() : Transaction()
{
    
    std::cout << "Tu as choisi de faire une fausse transaction, c'est à tes risques et périls" << std::endl;
    std::cout << "Il va falloir trouver un bon nom de transaction pour attirer des pigeons" << std::endl;
    std::cin >> _nom;

    std::cout << "Maintenant que le nom a été soigneusement choisi, il va falloir trouver un bon montant" << std::endl;
    std::cout << "Souviens toi, plus le montant est élevé, plus tu prends des risques" << std::endl;
    std::cin >> _montant;

    _suspicionRate = _montant/100000*(rand()%40);

    
    std::cout << "On a presque fini, il faut juste que tu me dises à quel endroit tu veux que l'argent parte"
    std::cin >> _lieux;
    _preussite = 100-(_montant/10000*4)-(rand()%30);
}


std::string TransactionFake::toString()
{
    std::string description = _nom;
    description += "\t|\t";
    description += _lieux;
    description += "\t|\t";
    description += std::to_string(_montant);
    description += "\t|\t";
    description += std::to_string(_preussite);
    description += "\t|\t";
    description += std::to_string("Détournement");  

    return description;
}

int TransactionMedium::evaluate()
{
    //Retourne un score et pas un montant
	if((rand()%100)>_preussite){
		return -_montant;
	}
    return _montant;
}

int TransactionMedium::montant()
{
    return _montant;
}




