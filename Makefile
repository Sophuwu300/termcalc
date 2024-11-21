default: src/
	g++ -std=c++17 -o build/calc src/*.cpp

release: src/
	zig c++ -std=c++17 -Os -o build/calc src/*.cpp

clean:
	@echo "clean target is for compatibility with autotools"
