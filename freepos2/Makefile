CXX = g++
CFLAGS=`wx-config --cxxflags` 
#CFLAGS=-g `wx-config --cxxflags` 

PROGRAM = freepos
SOURCES = imageCanvas.cpp \
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
	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs`

clean:
	rm -f *.o $(PROGRAM)
