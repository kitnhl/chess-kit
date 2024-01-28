# Architecture
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)    # macOS
    ARCH = arch -x86_64
else
    ARCH =
endif

# Compiler
CC = clang++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++2a

# Preprocessor flags
CPPFLAGS = -I./libs/SFML/2.5.1/include -I./libs/googletest/1.14.0/include

# Linker flags
LDFLAGS = -L./libs/SFML/2.5.1/lib -Wl,-rpath,./libs/SFML/2.5.1/lib \
			-L./libs/googletest/1.14.0/lib -Wl,-rpath,./libs/googletest/1.14.0/lib

# Libraries
LDLIB = -lsfml-graphics -lsfml-window -lsfml-system -lgtest -lgtest_main

# Target executable
TARGET = chess_kit

# Test executable
TEST_TARGET = test_chess_gui

# Source files
SOURCES = src/main.cpp src/chess_gui.cpp src/position.cpp src/pieces/piece.cpp src/pieces/bishop.cpp \
			src/pieces/king.cpp src/pieces/knight.cpp src/pieces/pawn.cpp src/pieces/queen.cpp src/pieces/rook.cpp

# Test files
TEST_SOURCES = tests/test_chess_gui.cpp src/chess_gui.cpp

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SOURCES)
	$(ARCH) $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIB) $(SOURCES) -o $(TARGET)

$(TEST_TARGET): $(TEST_SOURCES)
	$(ARCH) $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIB) $(TEST_SOURCES) -o $(TEST_TARGET)

clean:
	rm $(TARGET) $(TEST_TARGET)