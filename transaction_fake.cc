#include "transaction_fake.hh"
#include <iostream>
#include <cstdlib>
#include <string>




TransactionFake::TransactionFake(int transac) : Transaction()
{
    
    std::cout << "Tu as choisi de faire une fausse transaction, c'est à tes risques et périls." << std::endl;
    std::cout << "Il va falloir trouver un bon nom de transaction pour ne pas se faire repérer :" << std::endl;
    std::cin >> _nom;

    std::cout << "Maintenant que le nom a été soigneusement choisi, il va falloir trouver un bon montant" << std::endl;
    std::cout << "Souviens toi, plus le montant est élevé, plus tu prends des risques" << std::endl;
    std::cin >> _montant;

    std::cout << "On a presque fini, il faut juste que tu me dises à quel endroit tu veux que l'argent parte"<<std::endl;
    std::cin >> _lieux;

    if(transac==0){
        //cas d'une transaction fausse de niveau medium
        _suspicionRate = (_montant/100000)*(rand()%40);

        if (_montant < 10001){ //cas ou le montant correspond a une petite transaction
            if(Nom::isP(_nom)){//le nom est bien un nom de petite transaction
                _suspicionRate = _suspicionRate/2;
            }
            if(Lieu::isP(_lieux)){//le lieu est bien un nom de petite ville
                _suspicionRate = _suspicionRate/2;
            }

        }
        else if(_montant < 100001){
            if(Nom::isM(_nom)){//le nom est bien un nom de moyenne transaction
                _suspicionRate = _suspicionRate/2;
            }
            if(Lieu::isM(_lieux)){//le lieu est bien un nom de moyenne ville
                _suspicionRate = _suspicionRate/2;
            }


        }
        else{
            if(Nom::isG(_nom)){//le nom est bien un nom de grande transaction
                _suspicionRate = _suspicionRate/2;
            }
            if(Lieu::isG(_lieux)){//le lieu est bien un nom de grande ville
                _suspicionRate = _suspicionRate/2;
            }


        }
    

        _preussite = 100-(_montant/10000*4)-(rand()%30);
    }
    else{
        //cas d'une transaction fausse de niveau expert
        _suspicionRate = (_montant/1000000)*(rand()%40);

        if (_montant < 10001){ //cas ou le montant correspond a une petite transaction
            if(Nom::isP(_nom)){//le nom est bien un nom de petite transaction
                _suspicionRate = _suspicionRate/2;
            }
            if(Lieu::isP(_lieux)){//le lieu est bien un nom de petite ville
                _suspicionRate = _suspicionRate/2;
            }

        }
        else if(_montant < 100001){
            if(Nom::isM(_nom)){//le nom est bien un nom de moyenne transaction
                _suspicionRate = _suspicionRate/2;
            }
            if(Lieu::isM(_lieux)){//le lieu est bien un nom de moyenne ville
                _suspicionRate = _suspicionRate/2;
            }


        }
        else{
            if(Nom::isG(_nom)){//le nom est bien un nom de grande transaction
                _suspicionRate = _suspicionRate/2;
            }
            if(Lieu::isG(_lieux)){//le lieu est bien un nom de grande ville
                _suspicionRate = _suspicionRate/2;
            }


        }
    

        _preussite = 100-(_montant/100000*4)-(rand()%30);
    }
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
    description += "Détournement";  

    return description;
}

int TransactionFake::evaluate()
{
    //Retourne un score et pas un montant
	if((rand()%100)>_preussite){
		return -_montant;
        std::cout<<"\nQuel dommage ta transaction c'est faite intercepter par la police\n"<<std::endl;
	}
    std::cout<<"\nBien jouer ta fausse transaction à reussi\n"<<std::endl;
    return _montant;
}

int TransactionFake::montant()
{
    return _montant;
}

int TransactionFake::suspicion()
{
    return _suspicionRate;
}


