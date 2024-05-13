CC=g++
CFLAGS=-Wall -g
LDFLAGS=
SOURCES= lqueue.h empty_collection_exception.h patient.h doctor.h doctors_office.h simulation.h main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Simulation

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o $(EXECUTABLE)
