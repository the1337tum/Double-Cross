# A pretty basic makefile for the XML parsing config loader system
# Should run on the uni machines now...
CC=g++

# Compilation flags
#CFLAGS=`pkg-config --cflags libxml++-2.6`
#flags for libraries copied to a local subdirectory
#CFLAGS = -Ilib/glibmm-2.4/include -Iinclude/glib-2.0 -Ilib/glib-2.0/include

# More compilation flags, for warnings and errors
WFLAGS=-W -Werror -ansi -pedantic

# Libraries - statically links to things other than libm, glib, and pthread
# Also using local subdirectories here
LIBS=-lncurses

load: IO.o AI.o Files.o test.o
    $(CC) -o load IO.o AI.o Files.o test.o \
    $(CFLAGS) $(LIBS) $(WFLAGS)
IO.o: FlockingP.cpp
    $(CC) $(WFLAGS) -c FlockingP.cpp
SimParameterSet.o: SimParameterSet.cpp
    $(CC) $(WFLAGS) -c SimParameterSet.cpp
Loader.o: Loader.cpp    
    $(CC) $(WFLAGS) $(CFLAGS) -c Loader.cpp
ExampleLoad.o: ExampleLoad.cpp
    $(CC) $(WFLAGS) -c ExampleLoad.cpp

clean: 
    rm -f load FlockingP.o SimParameterSet.o Loader.o ExampleLoad.o
