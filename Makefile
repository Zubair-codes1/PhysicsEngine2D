main: src/main.cpp
	clang++ -std=c++17 src/main.cpp -o bin/main -I/opt/homebrew/opt/sfml/include -L/opt/homebrew/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

run: bin/main
	./bin/main

clean:
	rm bin/main