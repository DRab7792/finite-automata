#include <iostream>
#include <string>
#include <typeinfo>
#include "fa.h"
using namespace std;

int main(int argc, char **argv){
	finiteAutomata *fa = new finiteAutomata(argv[1]);
	cout << fa->getCurrent() << "->";
	int i=0;
	for (char *cur=argv[2];i<strlen(argv[2]);cur++){
		int next = fa->transition(*cur);
		if (next<0){
			cout << " reject"<<endl;
			return 0;
		}
		if (i>0){
			cout << "->";
		}
		cout << next;
		i++;
	}
	bool accept = fa->isAccept();
	if (accept){
		cout << " accept";
	}else{
		cout << " reject";
	}
	cout <<endl;
	delete fa;
	return 0;
}
