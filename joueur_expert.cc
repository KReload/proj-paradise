#include "joueur_expert.hh"
#include <string>
#include <vector>


Joueur_expert::Joueur_expert(Joueur_medium & j):Joueur_medium(j){
	_taux_suspicion=j.suspicion();
	_score=j.score();
}

 int Joueur_expert::capital(){
	return _capital;
}

void Joueur_expert::jouer(){
	std::vector<TransactionMedium> transactions;
	int i=0;
	for(i=0;i<10;i++){
		transactions.push_back(TransactionMedium());
	}
	std::cout<<"n°\t|\tnom\t|\tlieu\t\t\t|\tmontant\t\t|\tchance de succès\t|\tsuspicion\t\n"<<std::endl;
	for(i=0;i<10;i++){
		std::cout<<i+1<<"\t|\t";
		std::cout<<transactions[i].toString()<<std::endl;
	}
	int n=-1;
	std::string tmp;
	std::cout<<Message::MessageG()<<std::endl;
	std::cout<<"\nVeuillez tapper le n° de la transaction que vous souhaitez effectuer ou 0 pour effectuer une fausse transaction :\n"<<std::endl;
	
	while(0>n or n>10){
		try{
			std::cin>>tmp;
			n =std::stoi(tmp);
			if(0>n or n>10){
				throw std::exception();
			}
		}
		catch(std::exception e){
			std::cout<<"\nErreur de format. Veuillez tapper un n° de transaction.\n"<<std::endl;
		}
	}

	int res;
	if(n==0){
		TransactionFake f;
		int c=f.evaluate();
		if(c<0){
			_capital+=c;
		}
		else{
			_capital-=c;
			_score+=c;
		}
		_taux_suspicion+=f.suspicion();
		std::cout<<"Le trader "<<_nom<<" a un capital de "<<_capital<<" € et un score de "<<_score<<" € de détournés\n"<<std::endl;
		return;
	}

	res=transactions[n-1].evaluate();
	if(_capital<transactions[n-1].montant()){
		std::cout<< "\nAh il semblerait que vous ne possédiez pas assez d'argent pour faire cette transaction.\nOn va vous faire un pret mais on récupèrera 50% des gains." <<std::endl;
		res=res-(abs(res)/2);
	}

	_capital+=res;
	if(res<0){
		std::cout<<"\nAhh quelle erreur vous perdez "<<-res<<" €"<<std::endl;
	}
	else{
		std::cout<<"\nBien joué vous avez gagnez "<<res<<" €"<<std::endl;
	}
	std::cout<<"Le trader "<<_nom<<" a un capital de "<<_capital<<" € et un score de "<<_score<<" € de détournés\n"<<std::endl;
	return;
}

void Joueur_expert::maj(Joueur_medium & j){
    _capital=j.capital();
    _taux_suspicion=j.suspicion();
}

int Joueur_expert::suspicion(){
	return _taux_suspicion;
}