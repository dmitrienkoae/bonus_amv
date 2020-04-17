#pragma once
#include "overlap_graph.hpp"

std::string super_string(Vstr&);
LLint get_cycles(const OverlapGraph&);
Vint get_assignment(const OverlapGraph&);
void shift(const OverlapGraph&, Lint&);
