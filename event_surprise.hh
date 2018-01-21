#pragma once
#include <string>
#include <algorithm>
#include <map>


class EventSurprise{
public:
    EventSurprise();
	static int eventDeclenche();
protected:
    static std::map<int,std::string> _eventText;
	static std::map<int,int> _eventPoints;
	static std::map<int,int> _question;
};