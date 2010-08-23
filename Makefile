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

test=true

make_objs = IO.o AI.o

load: $(make_objs)
    $(CC) -o $(make_objs) \
    $(CFLAGS) $(LIBS) $(WFLAGS)

####################################
# IO files
io_objs = level.o display.o event.o

IO.o: $(io_objs)
    $(CC) -o $(io_objs) \
    $(CFLAGS) $(LIBS) $(WFLAGS)

# Test files
ifeq ($(test), true)
    test_level=test/test_Level.cpp
    test_display=test/test_DIsplay.cpp
    test_event=test/test_Event.cpp
endif

# Object files
level.o: Level.cpp $(level_test)
    $(CC) $(WFLAGS) -c Level.cpp $(level_test)
 

display.o: Display.cpp $(test_display) 
    $(CC) $(WFLAGS) -c Display.cpp $(test_display) 

event.o: Event.cpp $(test_event) 
    $(CC) $(WFLAGS) -c Event.cpp $(test_event) 

####################################
# AI files
# AI.o:


clean: 
    rm -f load FlockingP.o SimParameterSet.o Loader.o ExampleLoad.o
