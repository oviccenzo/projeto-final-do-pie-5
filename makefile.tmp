CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = CPP/main.cpp
TARGET = bin/main

SDLFLAGS = $(shell pkg-config --cflags --libs sdl2 SDL2_ttf)

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(SDLFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean