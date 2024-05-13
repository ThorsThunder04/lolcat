CC=gcc
OPT=-Wall

lolcat: lolcat.c
	$(CC) $(OPT) -o lolcat lolcat.c

clean:
	rm *~
	rm *.swp
	rm *.exe
