CFLAGS = -g -Wall -Wextra -pedantic -Wno-unused-parameter
#CFLAGS = -g -Wno-unused-parameter
CC = gcc

PROGRAMS = biblioLC entreeSortieLC main

.PHONY:	all clean

all: $(PROGRAMS)

biblioLC: biblioLC.o entreeSortieLC.o main.o
	$(CC) -o $@ $(CFLAGS) $^


entreeSortieLC: entreeSortieLC.o biblioLC.o main.o
	$(CC) -o $@ $(CFLAGS) $^

main: entreeSortieLC.o main.o biblioLC.o
	$(CC) -o $@ $(CFLAGS) $^

biblioLC.o: biblioLC.c biblioLC.h
	gcc $(CFLAGS) -c biblioLC.c

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h
	gcc $(CFLAGS) -c entreeSortieLC.c

main.o: main.c entreeSortieLC.h
	gcc $(CFLAGS) -c main.c


#Ou plus simplement
#%.o:%.c %.h
#	$(CC)  $(GCC_FLAGS) -c  $<


clean:
	rm -f *.o *~ $(PROGRAMS)
