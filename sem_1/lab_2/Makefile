CC=gcc
CFLAGS += -finput-charset=utf-8
all: program

program: program.o index_first_negative.o index_last_negative.o sum_between_negative.o sum_before_and_after_negative.o
	$(CC) $(CFLAGS) -o program program.o index_first_negative.o index_last_negative.o sum_between_negative.o sum_before_and_after_negative.o

program.o: program.c
	$(CC) $(CFLAGS) -c program.c

index_first_negative.o: index_first_negative.c
	$(CC) $(CFLAGS) -c index_first_negative.c

index_last_negative.o: index_last_negative.c
	$(CC) $(CFLAGS) -c index_last_negative.c

sum_between_negative.o: sum_between_negative.c
	$(CC) $(CFLAGS) -c sum_between_negative.c

sum_before_and_after_negative.o: sum_before_and_after_negative.c
	$(CC) $(CFLAGS) -c sum_before_and_after_negative.c

clean:
	del /Q *.o