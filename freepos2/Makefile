CXX = g++
#CFLAGS=`wx-config --cxxflags` 
CFLAGS=-g -ggdb `wx-config --cxxflags` 

PROGRAM = freepos
SOURCES = salesFrame.cpp \
					imageCanvas.cpp \
					cashierFrame.cpp \
          statusPanel.cpp \
          frame1.cpp \
          main.cpp

OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

# implementation
.SUFFIXES: .o .cpp

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

all:    $(PROGRAM)

$(PROGRAM):$(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs std,richtext`

clean:
	rm -f *.o $(PROGRAM)
