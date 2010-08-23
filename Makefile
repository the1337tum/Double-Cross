##
# A Bacic makefile to test and setup our build files
#     The test script is run by using the -t flag in make
#

# Explicitly use g++
CC=g++

# Compilation flags
#flags for libraries copied to a local subdirectory
#CFLAGS = -Ilib/glibmm-2.4/include -Iinclude/glib-2.0 -Ilib/glib-2.0/include

# More compilation flags, for warnings and errors
WFLAGS=-W -Werror -ansi -pedantic

# Libraries
# Both static and dynamically linked libraries
LIBS=-lncurses

make_objs = IO.o AI.o

load: $(make_objs)
    $(CC) -o $(make_objs) \
    $(CFLAGS) $(LIBS) $(WFLAGS)

######################################################
# IO files
io_objs = level.o display.o event.o

IO.o: $(io_objs)
    $(CC) -o $(io_objs) \
    $(CFLAGS) $(LIBS) $(WFLAGS)

# Test files - triggered by the -t option
ifneq (,$(findstring t,$(MAKEFLAGS)))
    display= /IO/Display.cpp test/test_DIsplay.cpp
    event=   /IO/Event.cpp   test/test_Event.cpp
    level=   /IO/Level.cpp   test/test_Level.cpp
else
    display= /IO/Display.cpp 
    event=   /IO/Event.cpp 
    level=   /IO/Level.cpp 
endif

# Object files
display.o: $(display)
    $(CC) $(WFLAGS) -c $(display)

event.o: $(display)
    $(CC) $(WFLAGS) -c $(display)

level.o: $(level)
    $(CC) $(WFLAGS) -c $(level)

######################################################
# AI files
# AI.o:


clean: 
    rm -f load FlockingP.o SimParameterSet.o Loader.o ExampleLoad.o
