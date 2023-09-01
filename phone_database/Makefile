CC = g++
CFLAGS = -std=c++14 -Wall -Wextra -pedantic

phone: phone.o funcs.o
	$(CC) $(CFLAGS) -o phone phone.o funcs.o

phone.o: phone.cpp funcs.h
	$(CC) $(CFLAGS) -c phone.cpp

funcs.o: funcs.cpp funcs.h
	$(CC) $(CFLAGS) -c funcs.cpp

clean:
	rm -f *.o ../*.o