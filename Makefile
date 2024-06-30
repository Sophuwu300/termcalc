NAME := termcalc
CXXFLAGS := -O3
SRC := src/*.cpp

all: $(SRC)
	@./zig-cc/zigcomp

zig: $(SRC)
	$(CXX) $(CXXFLAGS) -o build/$(NAME).$(ZIGTARGET) $(SRC)

clean:
	@echo "clean target is for compatibility with autotools"
