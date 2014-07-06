#include "builtins.h"

#include <iostream>
#include <cstdlib>
using namespace std;

const Builtin BUILTINS[] = {
	Builtin("help", cmd_help)
};
const int NUM_BUILTINS = sizeof(BUILTINS) / sizeof(Builtin);

int cmd_help(int argc, char ** argv){
	if(argc > 1 && *argv[0]){
		cout << "You asked for help about " << argv[1] << endl;
	}else{
		cout << "You asked for help" << endl;
	}
	exit(0);
}
