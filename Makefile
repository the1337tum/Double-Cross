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



make_objs = IO.o AI.o

load: $(make_objs)
    $(CC) -o $(make_objs) \
    $(CFLAGS) $(LIBS) $(WFLAGS)

# IO files
io_objs = level.o display.o event.o
IO.o: $(io_objs)
ifeq ($(test), true)
    $(CC) -o $(io_objs) \
    $(CFLAGS) $(LIBS) $(WFLAGS)
else
endif

level.o: Level.cpp
ifeq ($(test), true)
    $(CC) $(WFLAGS) -c Level.cpp
else
endif

display.o: Display.cpp
ifeq ($(test), true)
    $(CC) $(WFLAGS) -c Display.cpp
else
endif

event.o: Event.cpp
ifeq ($(test), true)
    $(CC) $(WFLAGS) -c Event.cpp
else
endif

# AI files
# AI.o:


clean: 
    rm -f load FlockingP.o SimParameterSet.o Loader.o ExampleLoad.o
