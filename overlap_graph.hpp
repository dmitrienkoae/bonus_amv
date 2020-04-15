#pragma once
#include <vector>
#include <string>
#include <ostream>
#include <list>
#include <iostream>

typedef std::vector<int> Vint;
typedef std::vector<Vint> VVint;

typedef std::vector<std::string> Vstr;

typedef std::list<int> Lint;
typedef std::list<Lint> LLint; 


class OverlapGraph {
public:
	OverlapGraph();
	OverlapGraph(size_t n);
	OverlapGraph( Vstr&);
	~OverlapGraph();

	void overlaps(Vstr&);

	size_t size() const;

	friend std::ostream& operator<<(std::ostream&, const OverlapGraph&);

	int& at(size_t i, size_t j);
	int at(size_t i, size_t j) const;

private:
	int overlap(const std::string&, const std::string&);

	VVint m;
	size_t n;
};
