CC = g++
CFLAGS = -std=c++11 -Wall -Iinclude -Ilibs/glad/include
LIBS = -lglfw -lGL -ldl
GLAD_SRC = libs/glad/src/glad.c
TARGET = Mainer
BIN_DIR = bin
SRC_DIR = src/main

all: $(BIN_DIR) $(BIN_DIR)/$(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/$(TARGET): $(SRC_DIR)/Mainer.cpp
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(TARGET) $(SRC_DIR)/Mainer.cpp $(GLAD_SRC) $(LIBS)

clean:
	rm -rf $(BIN_DIR)/*

run: all
	./$(BIN_DIR)/$(TARGET)