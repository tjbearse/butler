#include "exec.h"
#include "builtins.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <linux/limits.h>
#include <string>
#include <unistd.h>
using namespace std;

char * ARGV0_PATH = nullptr;

char * getPwdCwd(){
	static char cwd[PATH_MAX + 1];
	if (getcwd(cwd, PATH_MAX) == NULL)
		return NULL;
	return cwd;
}
 
string absolutePath(string path){
	const char * pwd = getPwdCwd();
	if(pwd){
		path.insert(path.begin(), PATH_SEPARATOR);
		path.insert(0, pwd);
	}
	return path;
}

string getPath(const char * path){
	if (path and *path) {
		string pathStr(path);
		if (isAbsolutePath(pathStr))
			return pathStr;
		else
			return absolutePath(pathStr);
	}
	return "";
}

char * gitExecPath(){
	return (char *) "";
}

void setupPath(){
	string path(getenv("PATH"));
	path.insert(0, ":");
	path.insert(0, getPath(ARGV0_PATH));

	setenv("PATH", path.c_str(), 1);
}

void handleBuiltin(int argc, char ** argv){
	if(!strncmp(argv[0], "butler-", 7)){
		// advance to part after dash
		argv[0] += 7;
	}
	Builtin help("", cmd_help);
	Builtin * builtin = & help;
	for(int i=0; i < NUM_BUILTINS; i++){
		if(!strcmp(BUILTINS[i].name, argv[0])){
			builtin = & BUILTINS[i];
		}
	}
	exit(builtin->fn(argc, argv));
}

void execvDashedExternal(char ** argv){
		
}

void runArgv(int argc, char ** argv){
	handleBuiltin(argc, argv);
	// will exit if it is builtin
	execvDashedExternal(argv);
	// wil exit if it runs
	exit(0);
}
