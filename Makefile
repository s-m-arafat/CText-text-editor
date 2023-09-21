main: main.cpp
	g++ main.cpp -o main -Wall -Wextra -pedantic -std=c++17

run:
	./main

clean:
	rm main

br: main run clean