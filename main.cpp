#include <iostream>
#include <vector>
#include <string>

#include "solution.hpp"

int main() {


	std::vector<std::string> vs;
	std::string s;
	while(std::cin >> s) {
		vs.push_back(s);
	}

	std::cout << super_string(vs) << std::endl;
return 0;
}
