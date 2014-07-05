#include "exec.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <linux/limits.h>
#include <string>
#include <unistd.h>
using namespace std;

char * getPwdCwd(){
	static char cwd[PATH_MAX + 1];
	if (getcwd(cwd, PATH_MAX) == NULL)
		return NULL;
	return cwd;
}
 
string absolutePath(string path){
	const char * pwd = getPwdCwd();
	if(pwd){
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

	path.insert(0, getPath(gitExecPath()));
	path.insert(0, getPath(ARGV0_PATH));

	setenv("PATH", path.c_str(), 1);
}

void runArgv(int argc, char **argv){
	for(int i=0; i < argc; i++){
		cout << i << ' ' << argv[i] << endl;
	}
	exit(0);
}
