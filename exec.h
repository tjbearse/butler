#ifndef EXEC_H
#define EXEC_H
#include <string>

const char PATH_SEPARATOR = '\\';
char * ARGV0_PATH = nullptr;

inline bool isAbsolutePath(std::string path){
	return path[0] == PATH_SEPARATOR;
}

// need function declarations here


#endif //EXEC_H
