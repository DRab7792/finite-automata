#include "fa.h"
using namespace std;
//Constructor
finiteAutomata::finiteAutomata(){
}
//Args: file name
//Constructor
finiteAutomata::finiteAutomata(char *file){
	ifstream inStream;
	inStream.open (file);
	char line[1024];
	//Get the first line to check that we are building a Finite Automata
	inStream.getline (line,1024);
	if (strstr(line,"Finite Automata")==NULL){
		return;
	}
	while (inStream.good()){
		inStream.getline (line,1024);
		//Handle States
		if (strstr(line,"state")!=NULL){
			state *curState = new state;
			char num[5]="    ";
			int i = 0;
			//Get State Number
			for (char *cur = &line[6];(*cur)!=' ';cur++){
				num[i] = (*cur);
				i++;
			}
			curState->num = atoi (num);
			//Check if the state is a strating state or accept state
			curState->start = (strstr(line,"start")!=NULL);
			curState->accept = (strstr(line,"accept")!=NULL);
			states.push_back(*curState);	
			//Set the current position at the start if the current state is the starting state
			if (curState->start){
				curPos = curState;
			}
		//Handle Transitions
		}else if (strstr(line,"transition")!=NULL){
			edge *curEdge = new edge;
			char num[5]="    ";
			int i = 0;
			char *cur;
			//Get starting location of current edge
			for (cur = &line[12];(*cur)!=',';cur++){
				num[i] = (*cur);
				i++;
			}
			curEdge->origin = stateSearch(atoi(num));
			//Get ending location and transition character
			char end[5]="    ";
			i= 0;
			cur ++;
			curEdge->trans = (*cur);
			for (cur=cur+5;(*cur)!=')';cur++){
				end[i] = (*cur);
				i++;
			}
			curEdge->end = stateSearch(atoi(end));
			//cout << "adding transition from state "<<curEdge->origin->num<<" to state "<<curEdge->end->num<<" with key "<<curEdge->trans<<endl;
			edges.push_back (*curEdge);
		}
	}	
}

//Args: transition character
//Transition function
int finiteAutomata::transition(char cur){
	for (vector<edge>::iterator it=edges.begin();it!=edges.end();it++){
		if (it->origin->num == curPos->num && it->trans == cur){
			curPos = it->end;
			//cout<<it->origin->num<<endl;
			return it->end->num;
		}
	}
	return -1;
}

//Get current position
int finiteAutomata::getCurrent(){
	return curPos->num;
}

//Check to see is the current position is an accept state
bool finiteAutomata::isAccept(){
	return curPos->accept;
}

<<<<<<< HEAD
//Search for a state and return a pointer to that state
state *finiteAutomata::stateSearch(int num){
	for (vector<state>::iterator it=states.begin();it!=states.end();it++){
		if (it->num==num){
			return &(*it);
		}	
	}
	return NULL;
}

//Destructor
finiteAutomata::~finiteAutomata(){
	delete &edges, &states;
}
=======
//Destructor
finiteAutomata::~finiteAutomata(){
	delete &edges, &states;
}
>>>>>>> b854ec74f5c946c507a05b11f20b06a8d50dc40b
