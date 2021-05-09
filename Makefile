CXX       	:= g++
CXX_FLAGS 	:= -pedantic -pedantic-errors -Wall -Wextra -std=c++2a -ggdb

BIN       	:= bin
SRC       	:= src
OBJ					:= obj
INCLUDE			:= include

LIBRARIES		:= 
EXECUTABLE	:= text-dungeon.elf

all: compile link

link: $(BIN)
	$(CXX) $(OBJ)/*.o -o $(BIN)/$(EXECUTABLE)

compile: clean $(SRC) $(OBJ)
	cd $(OBJ); \
	$(CXX) ../$(SRC)/*.cpp ../$(SRC)/*/*.cpp $(CXX_FLAGS) -I ../$(INCLUDE) -c

$(OBJ):
	-mkdir obj

$(BIN):
	-mkdir bin

clean:
	-rm -v $(BIN)/$(EXECUTABLE)
	-rm -v $(OBJ)/*.o

