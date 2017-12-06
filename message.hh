#pragma once
#include <string>
#include <vector>

//enum Categorie {Petite,Moyenne,Grosse,Piege};

class Message{
public:
    Message();
	static std::string MessageP();
	static std::string MessageM();
	static std::string MessageG();
protected:
    static std::vector<std::string> _messageP;
	static std::vector<std::string> _messageM;
	static std::vector<std::string> _messageG;
};
