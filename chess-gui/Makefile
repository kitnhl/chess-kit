# Arcchitecture
ARCH = arch -x86_64

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++2a 

# Preprocessor flags
CPPFLAGS = -I./SFML/2.5.1/include 

# Linker flags
LDFLAGS = -L./SFML/2.5.1/lib 

# Libraries
LDLIB = -lsfml-graphics -lsfml-window -lsfml-system

# Target executable
TARGET = chess-gui

# Source files
SOURCES = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(ARCH) $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIB) $(SOURCES) -o $(TARGET)

clean:
	rm $(TARGET)