all:
	gcc -std=c11 src/main.c -Wall -lmingw32 -lSDL2main -lSDL2 -o main.exe
