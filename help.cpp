#include "builtins.h"

#include <iostream>
#include <cstdlib>

int cmd_help(int argc, char ** argv){
	if(argc > 0){
		cout << "You asked for help about " << argv[1] << endl;
	}else{
		cout << "You asked for help" << endl;
	}
	exit(0);
}
