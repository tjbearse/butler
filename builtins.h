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

extern const Builtin BUILTINS[];
extern const int NUM_BUILTINS;

#endif /* BUILTINS_H */
