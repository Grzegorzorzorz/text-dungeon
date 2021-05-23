CXX       	:= g++
CXX_FLAGS 	:= -pedantic -pedantic-errors -Wall -Wextra -std=c++2a -ggdb

BIN       	:= bin
SRC       	:= $(shell cd ./obj && find ../ -name "*.cpp")
OBJ					:= obj
INCLUDE			:= include

LIBRARIES		:= -lncurses -ltinfo
EXECUTABLE	:= text-dungeon.elf

all: compile link

link: $(BIN) $(OBJ)
	$(CXX) $(shell find $(OBJ) -name *.o) -o $(BIN)/$(EXECUTABLE) $(LIBRARIES)

compile: clean $(OBJ)
	cd $(OBJ); \
	$(CXX) $(SRC) $(CXX_FLAGS) -I ../$(INCLUDE) -c

.PHONY : $(OBJ)
$(OBJ):
	-mkdir obj

.PHONY : $(BIN)
$(BIN):
	-mkdir bin

.PHONY : clean
clean:
	-rm $(BIN)/$(EXECUTABLE) $(shell find $(OBJ) -name *.o)

