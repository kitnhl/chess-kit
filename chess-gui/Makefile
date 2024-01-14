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
CPPFLAGS = -I./SFML/2.5.1/include -I./googletest/1.14.0/include

# Linker flags
LDFLAGS = -L./SFML/2.5.1/lib -Wl,-rpath,./SFML/2.5.1/lib -L./googletest/1.14.0/lib -Wl,-rpath,./googletest/1.14.0/lib

# Libraries
LDLIB = -lsfml-graphics -lsfml-window -lsfml-system -lgtest -lgtest_main

# Target executable
TARGET = chess_gui

# Test executable
TEST_TARGET = test_chess_gui

# Source files
SOURCES = main.cpp chess_gui.cpp

# Test files
TEST_SOURCES = test_chess_gui.cpp chess_gui.cpp

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SOURCES)
	$(ARCH) $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIB) $(SOURCES) -o $(TARGET)

$(TEST_TARGET): $(TEST_SOURCES)
	$(ARCH) $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIB) $(TEST_SOURCES) -o $(TEST_TARGET)

clean:
	rm $(TARGET) $(TEST_TARGET)