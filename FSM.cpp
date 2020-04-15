#include "FSM.h"

#include <algorithm>


inline FSM::FSM(std::string word)
{

	std::string word_rev = word;
	std::reverse_copy(word.begin(), word.end(), word_rev.begin());
	this->word = word_rev;
	int wlen = word_rev.size();
	for (int i = 0; i <= wlen; i++) {
		struct state s;
		s.fin = false;
		states.push_back(s);
	}
	/*
	for (int i = 0; i <= wlen; i++) { //Nulling arrows and finaling bool
		for (int j = 0; j < 128; j++) {
			states[i].p[j] = &states[0];
		}

		//states[i].fin = false;
	}
	*/

	for (int i = 0; i <= wlen; i++) { //Constructing states
		state cur_st;
		cur_st.fin = false;
		std::string pr_word;
		if (i != 0) {
			for (int j = 0; j < i; j++) {
				pr_word += word_rev[j];
			}
			cur_st.sym = pr_word;
			cur_st.fin = true;
		}
		states[i] = cur_st;

	}

	for (int i = 0; i <= wlen; i++) { //Nulling arrows and finaling bool
		for (int j = 0; j < 128; j++) {
			states[i].p[j] = &states[0];
		}
		//states[i].fin = false;
	}


	for (int i = 1; i < wlen; i++) { // Backward arrows 
		for (int j = 0; j < 128; j++) {
			std::string prefix = states[i].sym;
			prefix += j;
			std::string pr_rev;
			int n = prefix.size();
			for (int k = 0; k < n; k++) {
				pr_rev += prefix[n - 1 - k];
			}
			for (int k = 0; k < i; k++) {
				pr_rev.erase(pr_rev.end() - 1);
				std::string pr_revrev;
				for (int l = 0; l < pr_rev.size(); l++) {
					pr_revrev += pr_rev[pr_rev.size() - 1 - l];
				}
				int flag = 1;
				for (int l = 0; l < pr_revrev.size(); l++) {
					if (pr_revrev[l] != states[i - k].sym[l]) {
						flag = 0;
						break;
					}
				}
				if (flag == 1) {
					states[i].p[j] = &states[i - k];
					break;
				}
			}
		}
	}

	for (int i = 0; i < wlen; i++) { // Forward arrows
		char c;
		size_t length;
		length = states[i + 1].sym.size();
		c = states[i + 1].sym[length - 1];
		states[i].p[c] = &states[i + 1];
	}

}
inline int FSM::OverlapStr(std::string str)
{
	if (str.size() > word.size())
		str = str.substr(0, word.size());
	state *cur_st = &states[0];
	state *cur_prev = &states[0];
	int str_size = str.size();
	int overlap_beg = -1;
	int overlap_end = -1;
	bool first = true;
	std::string str_rev = str;
	std::reverse_copy(str.begin(), str.end(), str_rev.begin());

	for (int i = 0; i < str_size; i++) {
		if (str_rev[i] >= 0) { //escaping negative chars (many of them are in non-text files)
			cur_prev = cur_st;
			cur_st = cur_st->p[str_rev[i]];

		}
		else {
			cur_st = &states[0];
		}

		if (cur_st == cur_prev && cur_prev == &states[1])
			return 1;

		if (cur_st->fin == true) {
			if (first) {
				overlap_beg = i;
				first = false;
			}
			else {

				overlap_end = i;
			}
			//break;
		}
	}

	int overlap = overlap_end - overlap_beg + 1;

	if (overlap_end != str_rev.size() - 1) {
		overlap = 0;

	}
	if (overlap_beg == str_rev.size() - 1) {
		overlap = 1;
	}
	if (first)
		overlap = 0;
	return overlap;
}

inline FSM::~FSM()
{
}

