#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define progName "butler"
char * argv0Path = nullptr;
char * getArgv0(char * argv0){
	if(!argv0){
		return nullptr;
	}
	const char pathSeparator =
		#ifdef _WIN32
			'\\';
		#else
			'/';
		#endif
	char * slash = strrchr(argv0, pathSeparator);
	if(slash != nullptr){
		argv0Path = new char[slash-argv0+1];
		strncpy(argv0Path, argv0, slash-argv0);
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


void setupPath(){

}

void runArgv(int argc, char **argv){
	for(int i=0; i < argc; i++){
		cout << i << ' ' << argv[i] << endl;
	}
	exit(0);
}

int main(int argc, char **argv){
	// setup
	// get argv0
	char * cmd = getArgv0(argv[0]);
	if(!cmd){
		cmd = (char *) progName"-help";
	}
	cout << "cmd " << cmd << " argv0 " << argv[0] << endl;
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
