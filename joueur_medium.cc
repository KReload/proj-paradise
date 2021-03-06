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

/**
 * \fn Joueur_medium(Joueur_debutant & j)
 * \brief Fonction du contructeur du joueur medium.
 *
 * \param j joueur debutant à partir duquel on créé le joueur medium
 * \return rien.
 */
Joueur_medium :: Joueur_medium(Joueur_debutant & j):Joueur_debutant(j){
	_taux_suspicion=0;
	_score=0;
}

/**
 * \fn capital()
 * \brief Fonction de get pour recuperer le capital du joueur.
 *
 * \return le capital.
 */
 int Joueur_medium:: capital(){
	return _capital;
}

/**
 * \fn score()
 * \brief Fonction de get pour recuperer le score du joueur.
 *
 * \return le score.
 */
int Joueur_medium:: score(){
	return _score;
}

/**
 * \fn jouer()
 * \brief Fonction qui effectue un tour de jeu du joueur medium.
 *
 * \return rien.
 */

void Joueur_medium::jouer(){
	std::vector<TransactionMedium> transactions;
	int i=0;
	for(i=0;i<10;i++){//genere les transactions
		transactions.push_back(TransactionMedium());
	}
	//affiche les transactions
	std::cout<<"n°\t|\tnom\t\t\t|\tlieu\t\t\t|\tmontant\t\t|   chance de succès\n"<<std::endl;
	for(i=0;i<10;i++){
		std::cout<<i+1<<"\t|\t";
		std::cout<<transactions[i].toString()<<std::endl;
	}
	int n=-1;
	std::string tmp;
	//affiche un message aleatoire
	std::cout<<Message::MessageM()<<std::endl;
	std::cout<<"\nVeuillez taper le n° de la transaction que vous souhaitez effectuer ou 0 pour effectuer une fausse transaction :\n"<<std::endl;
	//attente d'un choix de la part d'un joueur.
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

	if(n==0){
		//lance la fonction qui gere les fausses transactions
		(*this).fake();
	}
	else{
		//lance l'affichage des résultats.
		(*this).eval(transactions[n-1].evaluate(),transactions[n-1].montant());
	}
	return;
}

/**
 * \fn fake()
 * \brief Fonction qui effectue un fausse transaction.
 *
 * \return rien.
 */

void Joueur_medium::fake(){
	//créé un fausse transaction avec comme paramètre 0 donc une fausse transaction de pour medium.
	TransactionFake f(0);
	int c=f.evaluate();
	if(c<0){//si se que renvoie l'evaluate de la fausse transaction est negatif la transaction a echoué donc on retire la mise du capital mais le score ne bouge pas
		(*this)+=c;
	}
	else{//sinon la transaction reussi donc on decremente le capital et in incremente le score.
		(*this)+=(-c);
		_score+=c;
	}
	//mise a jour du taux de suspicion.
	_taux_suspicion+=f.suspicion();
	std::cout<<"Le trader "<<_nom<<" a un capital de "<<KBLU<<_capital<<KNRM<<" € et un score de "<<KBLU<<_score<<KNRM<<" € de détournés\n"<<std::endl;
	return;
}


/**
 * \fn eval()
 * \brief Fonction qui effectue l'affichage en fonction du résultat de la transaction choisit.
 *
 * \return rien.
 */
void Joueur_medium::eval(int res,int montant){

	//si le joueur a choiit une transaction alors qu'il n'a pas assez d'argent on lui annonce qu'il y a un pret et que par consequent il pert 50% des gain qu'il fait.
	if(_capital<montant){
		std::cout<<KRED<< "\nAh il semblerait que vous ne possédiez pas assez d'argent pour faire cette transaction.\nOn va vous faire un pret mais on récupèrera 50% des gains." <<KNRM<<std::endl;
		res=res-(abs(res)/2);
	}


	//mise a jour du capital du joueur
	(*this)+=res;
	if(res<0){//si le resultat est négatif ca signifie que la transaction a echouer.
		std::cout<<KRED<<"\nAhh quelle erreur vous perdez "<<-res<<" €"<<KNRM<<std::endl;
	}
	else{//sinon la transaction a réussit
		std::cout<<KGRN<<"\nBien joué vous avez gagnez "<<res<<" €"<<KNRM<<std::endl;
	}
	//affichage de l'etat du joueur.
	std::cout<<"Le trader "<<_nom<<" a un capital de "<<KBLU<<_capital<<KNRM<<" € et un score de "<<KBLU<<_score<<KNRM<<" € de détournés\n"<<std::endl;
	return;
}


/**
 * \fn maj(Joueur_medium & j)
 * \brief Fonction qui met a jour le joueur exper.
 *
 * \param j joueur à partir duquel on met a jour.
 * \return rien.
 */
void Joueur_medium::maj(Joueur_debutant & j){
	_capital=j.capital();
}

/**
 * \fn suspicion()
 * \brief Fonction de get du taux de suspicion.
 *
 * \return le taux de suspicion.
 */
int Joueur_medium::suspicion(){
	return _taux_suspicion;
}