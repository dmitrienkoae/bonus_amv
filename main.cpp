#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "solution.hpp"

int main() {
	std::vector<std::string> vs = {"eab", "fgh", "ghf", "hed", "abc", "cde"};
	std::string superstr = super_streing(vs);
	std::cout << superstr << std::endl;
	std::vector<std::string> vs2 = { "a", "aa", "sdf", "fa", "ahg", "hju", "ut" };
	std::string superstr2 = super_streing(vs2);
	std::cout << superstr2 << std::endl;
return 0;
}


