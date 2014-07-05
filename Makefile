flags = --std=c++0x -Wall -Werror
comp = g++
every = $(comp) $(flags)
objects = butler.o exec.o
all: $(objects)
	$(every) $(objects) -o butler
exec.o: exec.h exec.cpp
	$(every) -c exec.cpp -o exec.o
butler.o: butler.cpp exec.h
	$(every) -c butler.cpp -o butler.o
clean:
	rm butler
	rm *.o
