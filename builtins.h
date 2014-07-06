#ifndef BUILTINS_H
#define BUILTINS_H

class Builtin{
public:
	const char * name;
	int (*fn)(int, char **);
	Builtin(const char * n, int (*func)(int, char **)):
		name(n){
			fn = func;
		};
};

int cmd_help(int argc, char ** argv);

Builtin BUILTINS[] = {
	Builtin("help", cmd_help)
};
const int NUM_BUILTINS = sizeof(BUILTINS);
#endif /* BUILTINS_H */
