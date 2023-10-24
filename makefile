CC = g++
CFLAGS = -O3
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
TARGET = program

# List your source files
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/ioaalgorithms.cpp

# Create object file names
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Include directory
INC = -I$(INCLUDE_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

all: $(TARGET)
