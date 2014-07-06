CC=g++
CFLAGS=-c -Wall --std=c++0x
LDFLAGS=
SOURCES=butler.cpp exec.cpp help.cpp
DEBUG=-Werror -g
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=butler

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

debug: .DBG all
	
.DBG:
	$(eval CFLAGS += $(DEBUG))

clean:
	rm $(EXECUTABLE)
	rm $(OBJECTS)
