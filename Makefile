default: src/
	g++ -std=c++17 -o build/termcalc src/*.cpp

release: src/
	zig c++ -std=c++17 -Os -o build/termcalc src/*.cpp

clean:
	@echo "clean target is for compatibility with autotools"
