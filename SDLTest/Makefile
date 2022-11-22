CXX = g++
FLAGS = -Wall

LIBPATHS = \
	-L D:/Documents/Development/SDL2/lib/x64

LIBS = \
	-l SDL2main \
	-l SDL2\
	-l SDL2_image

INCLUDES = \
	-I D:/Documents/Development/SDL2/include\

OBJECTS = \
	main.cpp\
	Game.cpp

all:
	$(CXX) $(OBJECTS) $(FLAGS) $(INCLUDES) $(LIBPATHS) $(LIBS) -o build/test.exe

run:
	build\test.exe
