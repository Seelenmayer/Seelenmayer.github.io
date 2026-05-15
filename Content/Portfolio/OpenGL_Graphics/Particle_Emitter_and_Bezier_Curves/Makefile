#Instructions for compilation.

OBJ=./obj
INC=./inc
SRC=./src
CXX=g++
LFLAGS=-lGL -lGLU -lglut -lm
CFLAGS=-c -std=c++11 #-Wall -Wextra
INCLUDE=-I $(INC)
MAKE_OBJ=$(CXX) $(CFLAGS) $(INCLUDE) $< -o $@
MAKE_EXE=$(CXX) $(LFLAGS) $^ -o $@

all: emitter

#execute:
	./emitter &

emitter : $(OBJ)/Main.o $(OBJ)/Controller.o $(OBJ)/Particle.o
	$(MAKE_EXE)

$(OBJ)/Main.o : $(SRC)/Main.cpp $(INC)/Main.h $(INC)/Controller.h $(INC)/Particle.h $(INC)/mathvector.h
	$(MAKE_OBJ)

$(OBJ)/Controller.o : $(SRC)/Controller.cpp $(INC)/mathvector.h
	$(MAKE_OBJ)

$(OBJ)/Particle.o : $(SRC)/Particle.cpp $(INC)/mathvector.h
	$(MAKE_OBJ)

clean:
	rm ./obj/*.o 