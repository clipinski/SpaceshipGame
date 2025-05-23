# Compiler settings
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++11 -g
# SDL2 flags using pkg-config (includes both compile and link flags)
SDL_FLAGS = $(shell sdl2-config --cflags --libs)
# Additional SDL2 libraries
SDL_LIBS = -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# Output executable name
TARGET = SpaceshipGame

# Source files (automatically find all .cpp files)
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(SDL_FLAGS) $(SDL_LIBS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(shell sdl2-config --cflags) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
