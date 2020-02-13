CXX = g++
#CFLAGS=`wx-config --cxxflags` 
BIN=./bin
SRC=./src
INCL=./incl
CFLAGS=-g -ggdb `wx-config --cxxflags` -I$(INCL)

PROGRAM = $(BIN)/freepos
SOURCES := $(wildcard $(SRC)/*.cpp) 
OBJECTS := $(patsubst $(SRC)/%.cpp,$(BIN)/%.o,$(wildcard $(SRC)/*.cpp))

# implementation
.SUFFIXES: .o .cpp

$(BIN)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

all:    $(PROGRAM)

$(PROGRAM):$(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs std,richtext`

clean:
	rm -f *.o $(PROGRAM)
