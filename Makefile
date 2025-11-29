CC = g++
CFLAGS = -std=c++11 -Wall -Iinclude -Ilibs/glad/include
LIBS = -lglfw -lGL -ldl
GLAD_SRC = libs/glad/src/glad.c
TARGET = Main
BIN_DIR = bin
SRC_DIR = src/main

# Source files
SOURCES = $(SRC_DIR)/Main.cpp \
          $(SRC_DIR)/VBO.cpp \
          $(SRC_DIR)/VAO.cpp \
          $(SRC_DIR)/EBO.cpp \
          $(SRC_DIR)/shaderClass.cpp

all: $(BIN_DIR) $(BIN_DIR)/$(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/$(TARGET): $(SOURCES) $(GLAD_SRC)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(TARGET) $(SOURCES) $(GLAD_SRC) $(LIBS)

clean:
	rm -rf $(BIN_DIR)/*

run: all
	./$(BIN_DIR)/$(TARGET)