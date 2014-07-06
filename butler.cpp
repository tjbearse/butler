#include "exec.h"

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

extern char * ARGV0_PATH;

char * getArgv0(char * argv0){
	if(!argv0){
		return nullptr;
	}
	char * slash = strrchr(argv0, PATH_SEPARATOR);
	if(slash != nullptr){
		ARGV0_PATH = new char[slash-argv0+1];
		strncpy(ARGV0_PATH, argv0, slash - argv0 + 1);
	}
	return slash + 1;
}

void handleOptions(int & argc, char **& argv){
	// handle global options here
	argc--;
	argv++;
}

void printHelp(){
	cout << "\"I need some help\" text" << endl;
}



int main(int argc, char **argv){
	// setup
	// get argv0
	char * cmd = getArgv0(argv[0]);
	if(!cmd){
		cmd = (char *) PROG_NAME"-help";
	}
	// if builtin, run
	// (global) options
	// argc and argv may be changed
	handleOptions(argc, argv);	
	// no command? run help
	if(argc == 0){
		printHelp();
		exit(1);
	}
	// path
	setupPath();
	// run command
	runArgv(argc, argv);
	// should have exited in runArgv
	exit(1);
}
