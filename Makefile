NAME := termcalc
CCFLAGS := -O3
SRC := src/*.c

all: $(SRC)
	@./zig-cc/zigcomp

zig: $(SRC)
	$(CC) $(CCFLAGS) -o build/$(NAME).$(ZIGTARGET) $(SRC)

clean:
	@echo "clean target is for compatibility with autotools"
