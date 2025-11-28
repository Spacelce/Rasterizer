CC = g++
CFLAGS = -std=c++11 -Wall
LIBS = -lGL -lGLU -lglut -lGLEW
TARGET = Mainer

all: $(TARGET)

$(TARGET): ./src/main/Mainer.cpp
	$(CC) $(CFLAGS) -o $(TARGET) ./src/main/Mainer.cpp $(LIBS)

clean:
	rm -f $(TARGET)

run: all
	./bin/$(TARGET)