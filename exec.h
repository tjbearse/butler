#ifndef EXEC_H
#define EXEC_H
#include <string>
#define PROG_NAME "butler"
#define SIZE_PROG_NAME sizeof(PROG_NAME)

const char PATH_SEPARATOR = '/';

inline bool isAbsolutePath(std::string path){
	return path[0] == PATH_SEPARATOR;
}

// need function declarations here
void setupPath();
void runArgv(int argc, char **argv);

#endif //EXEC_H
