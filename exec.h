#ifndef EXEC_H
#define EXEC_H
#include <string>

const char PATH_SEPARATOR = '/';

inline bool isAbsolutePath(std::string path){
	return path[0] == PATH_SEPARATOR;
}

// need function declarations here
void setupPath();
void runArgv(int argc, char **argv);

#endif //EXEC_H
