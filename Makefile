# Define the compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Wall -g

# Define the target executable
TARGET = sociopat.exe

# Define the object files
OBJS = obj/main.o obj/UserManager.o obj/PostManager.o obj/Display.o

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile main.cpp
obj/main.o: src/main.cpp
	@if not exist obj mkdir obj
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

# Compile UserManager.cpp
obj/UserManager.o: src/UserManager.cpp
	@if not exist obj mkdir obj
	$(CXX) $(CXXFLAGS) -c src/UserManager.cpp -o obj/UserManager.o

# Compile PostManager.cpp
obj/PostManager.o: src/PostManager.cpp
	@if not exist obj mkdir obj
	$(CXX) $(CXXFLAGS) -c src/PostManager.cpp -o obj/PostManager.o

# Compile Display.cpp
obj/Display.o: src/Display.cpp
	@if not exist obj mkdir obj
	$(CXX) $(CXXFLAGS) -c src/Display.cpp -o obj/Display.o

# Clean up build files
clean:
	del /q obj\*.o $(TARGET)
