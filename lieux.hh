#pragma once
#include <string>
#include <vector>

enum Categorie {Petite,Moyenne,Grosse,Piege};

class Lieu{
	std::vector<std::string> _villeP;
	std::vector<std::string> _villeM;
	std::vector<std::string> _villeG;
	std::vector<std::string> _villePG;
public:
	Lieu();
	std::string villeP();
	std::string villeM();
	std::string villeG();

};




