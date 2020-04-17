#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "solution.hpp"

int main() {
	std::vector<std::string> vs;
	std::string s;
	std::string line;
	std::ifstream in("D:\\tests.txt"); 
	if (in.is_open())
	{
		while (getline(in, line))
		{
			vs.push_back(line);
		}
	}
	in.close();

	OverlapGraph g(vs);
	//std::cout << g << std::endl;
	std::cout << super_string(vs).size() << std::endl;
	std::cout << super_string(vs) << std::endl;
return 0;
}

