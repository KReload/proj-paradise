
#include "joueur_debutant.hh"
#include "message.hh"
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
 * \fn Joueur_debutant()
 * \brief Fonction du contructeur du joueur debutant.
 *
 * \return rien.
 */
Joueur_debutant :: Joueur_debutant(){
	std::string nom;
	std::cout<<"Veuillez donné votre nom : "<<std::endl;
	//demande au joueur de rentrer son nom
	std::cin>>nom;
	_nom=nom;
	//fixe le capitale de depart à 10000
	_capital=10000;
}

/**
 * \fn Joueur_débutant(Joueur_debutant & j)
 * \brief Fonction du contructeur par copie.
 *
 * \param j est le joueur dont on veut faire une copie.
 * \return rien.
 */
Joueur_debutant :: Joueur_debutant(Joueur_debutant & j){
	_nom=j.nom();
	_capital=j.capital();
}


/**
 * \fn capital()
 * \brief Fonction de get pour recuperer le capital du joueur.
 *
 * \return le capital.
 */
 int Joueur_debutant:: capital(){
	return _capital;
}


/**
 * \fn jouer()
 * \brief Fonction qui effectue un tour de jeu du joueur débutant.
 *
 * \return rien.
 */
void Joueur_debutant::jouer(){
	std::vector<TransactionDebutant> transactions;
	int i=0;
	for(i=0;i<10;i++){//creation des transactions que l'on va proposer au joueur
		transactions.push_back(TransactionDebutant());
	}
	//affichage des transaction
	std::cout<<"n°\t|\tnom\t\t\t|\tlieu\t\t\t|\tmontant\n"<<std::endl;
	for(i=0;i<10;i++){
		std::cout<<i+1<<"\t|\t";
		std::cout<<transactions[i].toString()<<std::endl;
		
	}
	int n=-1;
	std::string tmp;
	//affiche un message aleatoire
	std::cout<<Message::MessageP()<<std::endl;
	std::cout<<"\nVeuillez tapper le n° de la transaction que vous souhaitez effectuer :\n"<<std::endl;
	//attente d'un choix de la part d'un joueur.
	while(1>n or n>10){
		try{
			std::cin>>tmp;
			n =std::stoi(tmp);
			if(1>n or n>10){
				throw std::exception();
			}
		}
		catch(std::exception e){//traite les cas ou le joueur rentre des valeur aberante ou des lettres
			std::cout<<KRED<<"\nErreur de format. Veuillez tapper un n° de transaction.\n"<<KNRM<<std::endl;
		}
	}
	//lance l'affichage des résultats.
	(*this).eval(transactions[n-1].evaluate(),transactions[n-1].montant());
}


/**
 * \fn eval()
 * \brief Fonction qui effectue l'affichage en fonction du résultat de la transaction choisit.
 *
 * \return rien.
 */
void Joueur_debutant::eval(int res,int montant){

	//si le joueur a choiit une transaction alors qu'il n'a pas assez d'argent on lui annonce qu'il y a un pret et que par consequent il pert 50% des gain qu'il fait.
	if(_capital<montant){
		std::cout<<KRED<< "\nAh il semblerait que vous ne possédiez pas assez d'argent pour faire cette transaction.\nOn va vous faire un pret mais on récupèrera 50% des gains." <<KNRM<<std::endl;
		res=res-(abs(res)/2);
	}

	//mise a jour du capital du joueur
	_capital+=res;
	if(res<0){//si le resultat est négatif ca signifie que la transaction a echouer.
		std::cout<<KRED<<"\nAhh quelle erreur vous perdez "<<-res<<" €"<<KNRM<<std::endl;
	}
	else{//sinon la transaction a réussit
		std::cout<<KGRN<<"\nBien joué vous avez gagnez "<<res<<" €"<<KNRM<<std::endl;
	}
	//affichage de l'etat du joueur.
	std::cout<<"Le stagiaire "<<_nom<<" a un capital de "<<KBLU<<_capital<<KNRM<<" €\n"<<std::endl;
	return;
}

/**
 * \fn nom()
 * \brief Fonction de get pour recuperer le nom du joueur.
 *
 * \return le nom du joueur.
 */
std::string Joueur_debutant:: nom(){
	return _nom;
}

