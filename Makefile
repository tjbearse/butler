CC=g++
VARS= -DPROG_NAME='"$(EXECUTABLE)"'
CFLAGS=-c -Wall --std=c++0x $(VARS)
LDFLAGS=
SOURCES=butler.cpp exec.cpp builtins.cpp
DEBUG=-Werror -g
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=butler

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: Makefile
	$(CC) $(CFLAGS) $< -o $@

debug: .DBG all
	
.DBG:
	$(eval CFLAGS += $(DEBUG))

clean:
	-rm $(EXECUTABLE)
	-rm $(OBJECTS)
