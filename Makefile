#OBJS specifies which files to compile as part of the project
OBJS = RenderingAnImage.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're
#using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of the executable
OBJ_NAME = RenderingAnImage

#This is the target that compiles our executables 
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)