#pragma once
#include <string>
#include <vector>

//enum Categorie {Petite,Moyenne,Grosse,Piege};

class Nom{
public:
    Nom();
	static std::string nomP();
	static std::string nomM();
	static std::string nomG();
	static bool isP(std::string);
	static bool isM(std::string);
	static bool isG(std::string);
protected:
    static std::vector<std::string> _nomP;
	static std::vector<std::string> _nomM;
	static std::vector<std::string> _nomG;
};

