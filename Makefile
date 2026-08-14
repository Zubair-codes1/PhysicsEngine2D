main: main.cpp
	clang++ -std=c++17 main.cpp -o main -I/opt/homebrew/opt/sfml/include -L/opt/homebrew/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

run: main
	./main

clean:
	rm -rf main.bin