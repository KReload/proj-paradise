#pragma once
#include <string>
#include <vector>

enum Categorie {Petite,Moyenne,Grosse,Piege};

class Lieu{
public:
    Lieu();
	static std::string villeP();
	static std::string villeM();
	static std::string villeG();
protected:
    static std::vector<std::string> _villeP;
	static std::vector<std::string> _villeM;
	static std::vector<std::string> _villeG;
	static std::vector<std::string> _villePG;
};




