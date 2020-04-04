#include "overlap_graph.hpp"

OverlapGraph::OverlapGraph(){
}

OverlapGraph::OverlapGraph(size_t n) {
	this->n = n;
	this->m = VVint(n, Vint(n));
}

OverlapGraph::OverlapGraph(const Vstr& vs) {
	overlaps(vs);
}

OverlapGraph::~OverlapGraph() {
}


void OverlapGraph::overlaps(const Vstr& vs) {
	this->n = vs.size();
	this->m = VVint(n, Vint(n));
	for(size_t i = 0; i < n; ++i)
		for(size_t j = 0; j < n; ++j)
			m[i][j] = overlap(vs[i], vs[j]);
}

size_t OverlapGraph::size() const {
	return n;
}

int OverlapGraph::overlap(const std::string& s1, const std::string& s2) {
	if(&s1 == &s2)
		return 0;
	int s1_last = s1.size() - 1;
	int s2_size = s2.size();
	int	res = 0; 
	for(int i = s1_last, j = 1; i >= 0  && j <= s2_size; i--, j++){
		bool is_overlap = true;
		for(int k = 0; k < j; ++k) {
			if(s1[i + k] != s2[k]) {
				is_overlap = false;
				break;
			}
		}
		if(is_overlap)
			res = j;
	}

	return res;
}


int& OverlapGraph::at(size_t i, size_t j) {
	return m[i][j];
}

int OverlapGraph::at(size_t i, size_t j) const{
	return m[i][j];
}

std::ostream& operator<<(std::ostream& out, const OverlapGraph& g) {
	for(size_t i = 0; i < g.size(); ++i) {
		for(size_t j = 0; j < g.size(); ++j)
			out << g.m[i][j] << ' ';
		out << std::endl;
	}  
	out << "\n--------------------------\n";
	return out;
}

