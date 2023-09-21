# make a variable to store the path to the include folder
P = ./headers
# create a variable group of cpp file names to compile in the command

FILES = main.cpp $P/terminal.cpp

main: main.cpp
	g++ $(FILES) -o main -Wall -Wextra -pedantic -std=c++17

run:
	./main

clean:
	rm main

br: main run clean