AR = ar
CC = gcc
FLAGS = -Wall

all: StrList libstrlist.a

StrList: Main.o libstrlist.a
	$(CC) $(FLAGS) -o StrList Main.o -L. -lstrlist

StrList.o: StrList.c
	$(CC) $(FLAGS) -c StrList.c

libstrlist.a: StrList.o
	$(AR) rcs libstrlist.a StrList.o

Main.o: Main.c
	$(CC) $(FLAGS) -c Main.c

clean:
	rm -f *.a *.o StrList
