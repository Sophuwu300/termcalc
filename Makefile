NAME := termcalc

CXX := g++ -std=c++17
SRC := src/*.cpp
TARGET := $(NAME)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

