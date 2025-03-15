CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR=bin

$(OBJ_DIR)/Matriz.o: $(INCLUDE_DIR)/Matriz.hpp $(SRC_DIR)/Matriz.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Matriz.cpp -I$(INCLUDE_DIR) -o $@

$(OBJ_DIR)/redeNeural.o: $(INCLUDE_DIR)/redeNeural.hpp $(SRC_DIR)/redeNeural.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/redeNeural.cpp -I$(INCLUDE_DIR) -o $@

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Matriz.hpp $(INCLUDE_DIR)/redeNeural.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $@

run: $(OBJ_DIR)/Matriz.o $(OBJ_DIR)/redeNeural.o $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

all: run

greetings:
	@echo "Compilação realizada com sucesso!"

build: run greetings

clean: $(OBJ_DIR)/Matriz.o $(OBJ_DIR)/redeNeural.o $(OBJ_DIR)/main.o
	rm $^

