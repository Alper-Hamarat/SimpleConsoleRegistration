CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

SRC = src/main.cpp src/User-IO.cpp
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))
TARGET = main

# Default rule
all: build $(TARGET)

# Linker: erstellt Binary aus den .o Dateien
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regel für .o-Dateien im build/ Ordner
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ordner build/ erstellen falls nicht vorhanden
build:
	mkdir -p build

# Aufräumen
clean:
	rm -rf build $(TARGET)
