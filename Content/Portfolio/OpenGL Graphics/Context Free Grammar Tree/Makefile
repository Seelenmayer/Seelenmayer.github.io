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

all: cfg

#execute:
	./cfg &

assignment4 : $(OBJ)/Main.o $(OBJ)/LoadObj.o $(OBJ)/Controller.o $(OBJ)/LSystem.o
	$(MAKE_EXE)

$(OBJ)/Main.o : $(SRC)/Main.cpp $(INC)/Main.h $(OBJ)/LoadObj.o $(INC)/Controller.h $(INC)/LSystem.h $(INC)/mathvector.h $(INC)/bitmap.h $(INC)/Matrix.h
	$(MAKE_OBJ)

$(OBJ)/LoadObj.o : $(SRC)/LoadObj.cpp $(INC)/LoadObj.h $(INC)/mathvector.h
	$(MAKE_OBJ)

$(OBJ)/Controller.o : $(SRC)/Controller.cpp $(INC)/mathvector.h $(INC)/Matrix.h
	$(MAKE_OBJ)

$(OBJ)/LSystem.o : $(SRC)/LSystem.cpp $(INC)/Main.h $(INC)/mathvector.h $(INC)/Matrix.h
	$(MAKE_OBJ)

clean:
	rm ./$(OBJ)/*.o 
