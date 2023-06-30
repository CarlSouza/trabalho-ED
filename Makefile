# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -Wextra -std=c++17
# Target executable
TARGET = edprogram
# Directories
SRCDIR = src
BUILDDIR = build
# Source files
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
# Default rule
all: $(TARGET)
# Rule to build the target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
# Rule to compile source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
# Clean rule
clean:
	rm -f $(TARGET) $(BUILDDIR)/*.o