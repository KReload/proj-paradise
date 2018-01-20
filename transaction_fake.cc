#include "transaction_fake.hh"
#include <iostream>
#include <cstdlib>
#include <string>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"



TransactionFake::TransactionFake(int transac) : Transaction()
{
    
    std::cout << "Tu as choisi de faire une fausse transaction, c'est à tes risques et périls." << std::endl;
    std::cout << "Il va falloir trouver un bon nom de transaction pour ne pas se faire repérer :" << std::endl;
    std::cin >> _nom;

    std::cout << "Maintenant que le nom a été soigneusement choisi, il va falloir trouver un bon montant" << std::endl;
    std::cout << "Souviens toi, plus le montant est élevé, plus tu prends des risques" << std::endl;
    std::string tmp;
    _montant=-1;
    while(0>=_montant){
        try{
            std::cin>>tmp;
            _montant =std::stoi(tmp);
            if(0>_montant){
                throw std::exception();
            }
        }
        catch(std::exception e){
            std::cout<<KRED<<"\nErreur de format. Veuillez tapper un montant.\n"<<KNRM<<std::endl;
        }
    }

    std::cout << "On a presque fini, il faut juste que tu me dises à quel endroit tu veux que l'argent parte"<<std::endl;
    std::cin >> _lieux;

    if(transac==0){
        //cas d'une transaction fausse de niveau medium
        _suspicionRate = ((float)_montant/100000.0)*(rand()%40);

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
        _suspicionRate = ((float)_montant/1000000.0)*(rand()%40);

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
        std::cout<<KRED<<"\nQuel dommage ta transaction c'est faite intercepter par la police\n"<<KNRM<<std::endl;
		return -_montant;
	}
    std::cout<<KGRN<<"\nBien joué ta fausse transaction a reussie\n"<<KNRM<<std::endl;
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


