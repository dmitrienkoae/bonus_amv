#include <iostream>
#include <vector>
#include <string>

#include "solution.hpp"

int main() {
	std::vector<std::string> vs;
	std::string s;
	std::string line;
	std::ifstream in("D:\\tests.txt"); \\input file
	if (in.is_open())
	{
		while (getline(in, line))
		{
			vs.push_back(line);
		}
	}
	in.close();

	std::cout << super_string(vs) << std::endl;
return 0;
}
