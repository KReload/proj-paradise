
#include "joueur_debutant.hh"
#include "message.hh"
#include <string>
#include <vector>

Joueur_debutant :: Joueur_debutant(){
	std::string nom;
	std::cout<<"Veuillez donné votre nom : "<<std::endl;
	std::cin>>nom;
	_nom=nom;
	_capital=200000;
}

Joueur_debutant :: Joueur_debutant(Joueur_debutant & j){
	_nom=j.nom();
	_capital=j.capital();
}

 int Joueur_debutant:: capital(){
	return _capital;
}

void Joueur_debutant::jouer(){
	std::vector<TransactionDebutant> transactions;
	int i=0;
	for(i=0;i<10;i++){
		transactions.push_back(TransactionDebutant());
	}
	std::cout<<"n°\t|\tnom\t|\tlieu\t\t\t|\tmontant\n"<<std::endl;
	for(i=0;i<10;i++){
		std::cout<<i+1<<"\t|\t";
		std::cout<<transactions[i].toString()<<std::endl;
		
	}
	int n=-1;
	std::string tmp;
	std::cout<<Message::MessageP()<<std::endl;
	std::cout<<"\nVeuillez tapper le n° de la transaction que vous souhaitez effectuer :\n"<<std::endl;
	
	while(1>n or n>10){
		try{
			std::cin>>tmp;
			n =std::stoi(tmp);
			if(1>n or n>10){
				throw std::exception();
			}
		}
		catch(std::exception e){
			std::cout<<"\nErreur de format. Veuillez tapper un n° de transaction.\n"<<std::endl;
		}
	}

	int res;

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
	std::cout<<"Le stagiaire "<<_nom<<" a un capital de "<<_capital<<" €\n"<<std::endl;
	return;
}

std::string Joueur_debutant:: nom(){
	return _nom;
}

