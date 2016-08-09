CC = g++
CCLIBS = -lcurl -ljson-c
CCFLAGS = 

SRC_DIR = source
SRC = $(SRC_DIR)/core/telegram.cpp $(SRC_DIR)/core/message.cpp $(SRC_DIR)/main.cpp
EXE = main

all:
	$(CC) $(SRC) -o $(EXE) $(CCLIBS)
	
clean:
	rm $(EXE)