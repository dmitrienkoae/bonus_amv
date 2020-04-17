#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "solution.hpp"

int main() {
	std::vector<std::string> vs = {"eab", "fgh", "ghf", "hed", "abc", "cde"};
	std::cout << "Sum length : "<< super_string(vs).size() << std::endl;
	std::cout << "Superstring : " <<super_string(vs) << std::endl;
	vs = { "a", "aa", "sdf", "fa", "ahg", "hju", "ut" };
	std::cout << "Sum length : " << super_string(vs).size() << std::endl;
	std::cout << "Superstring : " << super_string(vs) << std::endl;
return 0;
}


