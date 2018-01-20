#include "joueur_medium.hh"
#include <string>
#include <vector>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


Joueur_medium :: Joueur_medium(Joueur_debutant & j):Joueur_debutant(j){
	_taux_suspicion=0;
	_score=0;
}

 int Joueur_medium:: capital(){
	return _capital;
}
int Joueur_medium:: score(){
	return _score;
}

void Joueur_medium::jouer(){
	std::vector<TransactionMedium> transactions;
	int i=0;
	for(i=0;i<10;i++){
		transactions.push_back(TransactionMedium());
	}
	std::cout<<"n°\t|\tnom\t\t\t|\tlieu\t\t\t|\tmontant\t\t|   chance de succès\n"<<std::endl;
	for(i=0;i<10;i++){
		std::cout<<i+1<<"\t|\t";
		std::cout<<transactions[i].toString()<<std::endl;
	}
	int n=-1;
	std::string tmp;
	std::cout<<Message::MessageM()<<std::endl;
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
			std::cout<<KRED<<"\nErreur de format. Veuillez tapper un n° de transaction.\n"<<KNRM<<std::endl;
		}
	}

	int res;
	if(n==0){
		TransactionFake f(0);
		int c=f.evaluate();
		if(c<0){
			_capital+=c;
		}
		else{
			_capital-=c;
			_score+=c;
		}
		_taux_suspicion+=f.suspicion();
		std::cout<<"Le trader "<<_nom<<" a un capital de "<<KBLU<<_capital<<KNRM<<" € et un score de "<<KBLU<<_score<<KNRM<<" € de détournés\n"<<std::endl;
		return;
	}

	res=transactions[n-1].evaluate();
	if(_capital<transactions[n-1].montant()){
		std::cout<<KRED<< "\nAh il semblerait que vous ne possédiez pas assez d'argent pour faire cette transaction.\nOn va vous faire un pret mais on récupèrera 50% des gains." <<KNRM<<std::endl;
		res=res-(abs(res)/2);
	}

	_capital+=res;
	if(res<0){
		std::cout<<KRED<<"\nAhh quelle erreur vous perdez "<<-res<<" €"<<KNRM<<std::endl;
	}
	else{
		std::cout<<KGRN<<"\nBien joué vous avez gagnez "<<res<<" €"<<KNRM<<std::endl;
	}
	std::cout<<"Le trader "<<KBLU<<_nom<<KNRM<<" a un capital de "<<KBLU<<_capital<<KNRM<<" € et un score de "<<KBLU<<_score<<KNRM<<" € de détournés\n"<<std::endl;
	return;
}

void Joueur_medium::maj(Joueur_debutant & j){
	_capital=j.capital();
}

int Joueur_medium::suspicion(){
	return _taux_suspicion;
}