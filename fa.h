#include <cstring>
#include <stdlib.h>
#include <string>
#include <istream>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


struct state{
	bool start;
	bool accept;
	int num;
};

struct edge{
	state *origin;
	state *end;
	char trans;		
};

class finiteAutomata{
	private:
		vector<edge> edges;
		state *curPos;
		vector<state> states;
	public:
		finiteAutomata();
		~finiteAutomata();
		finiteAutomata(char *file);
		int transition(char cur);
		int getCurrent();
		state *stateSearch(int num);
		bool isAccept();
};
