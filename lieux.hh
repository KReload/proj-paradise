#pragma once
#include <string>
#include <algorithm>
#include <vector>

enum Categorie {Petite,Moyenne,Grosse,Piege};

class Lieu{
public:
    Lieu();
	static std::string villeP();
	static std::string villeM();
	static std::string villeG();
	static bool isP(std::string);
	static bool isM(std::string);
	static bool isG(std::string);
protected:
    static std::vector<std::string> _villeP;
	static std::vector<std::string> _villeM;
	static std::vector<std::string> _villeG;
};




