CC=gcc
CFLAGS=-lWarn -pedantic

thermo: thermo.o libmyifttt.a
	$(CC) thermo.o -L. -lmyifttt -lcurl -o thermo
	
libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

thermo.o:	thermo.c ifttt.h
	$(CC) -c -ansi $(CFLAGS) thermo.c

clean:
	rm thermo *.o *.out 




