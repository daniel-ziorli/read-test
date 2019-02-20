all: unixio
	gcc unixio.c -o unixio -std=c11 -pedantic -Wall
clean:
	rm unixio
        

