#pragma once
#include <string>
#include <vector>

class FSM
{
	std::string word; //input word
	struct state {
		std::string sym;
		state *p[128];
		bool fin;
	};
	std::vector<struct state> states;
public:
	FSM(std::string word);
	int OverlapStr(std::string str);
	~FSM();
};

