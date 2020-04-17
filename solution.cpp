#include "solution.hpp"

Vint get_assignment(const OverlapGraph& g){
	const size_t n = g.size();
	Vint ass(n);
	VVint used(n, Vint(n, 0));
	while(true) {
		int max = -1, maxi = -1, maxj = -1;

		for(size_t i = 0; i < n; ++i) {
			for(size_t j = 0; j < n; ++j) {
				if(used[i][j])
					continue;

				if(g.at(i, j) > max) {
					max = g.at(i, j);
					maxi = i;
					maxj = j;
				}
			}
		}

		if(max == -1)
			break;
		ass[maxi] = maxj;

		for(size_t i = 0; i < n; ++i) {
			used[maxi][i] = 1;
			used[i][maxj] = 1;
		}
	}

	return ass;
}

LLint get_cycles(const OverlapGraph& g){
	Vint ass = get_assignment(g);
	const size_t n = g.size();
	Vint used(n, 0);
	LLint cycles;
	Lint cycle;
	for(size_t i = 0; i < ass.size(); ++i) {
		if(used[i])
			continue;

		cycle.push_back(i);
		used[i] = 1;
		
		if(ass[i] == cycle.front()) {
			shift(g, cycle);
			cycles.push_back(cycle);
			cycle = Lint();
			i = 0;
		} else {
			i = ass[i] - 1;
		}
	}
	return cycles;
}

void shift(const OverlapGraph& g, Lint& cycle) {
	int min = g.at(cycle.back(), cycle.front());
	auto prev = cycle.begin();
	for(auto it = std::next(prev, 1); it != cycle.end(); ++it) {
		if(min >= g.at(*prev, *it))
			min = g.at(*prev, *it);
		prev = it;
	}
	while(g.at(cycle.back(), cycle.front()) != min) {
		cycle.push_back(cycle.front());
		cycle.pop_front();
	}
}

std::string super_string(Vstr& vs) {
	OverlapGraph g(vs);
	LLint cycles = get_cycles(g);
	std::string super_str;
	for(auto& cycle : cycles) {
		std::string cur_str = vs[cycle.front()];
		auto prev = cycle.begin();
		for(auto it = std::next(prev, 1); it != cycle.end(); ++it) {
			cur_str += vs[*it].substr(g.at(*prev, *it));
			prev = it;
		}
		super_str += cur_str;
	}
	return super_str;
}
