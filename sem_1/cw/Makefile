CC=gcc
all: program

program: program.o input.o hatred_repeated.o hatred_odd.o replacement.o special_characters.o comp.o hated_Cyrilli.o output.o
	$(CC) -o program program.o input.o hatred_repeated.o hatred_odd.o replacement.o special_characters.o comp.o hated_Cyrilli.o output.o

program.o: program.c
	$(CC) -c program.c

input.o: input.c
	$(CC) -c input.c

hatred_repeated.o: hatred_repeated.c
	$(CC) -c hatred_repeated.c

hatred_odd.o: hatred_odd.c
	$(CC) -c hatred_odd.c

replacement.o: replacement.c
	$(CC) -c replacement.c

special_characters.o: special_characters.c
	$(CC) -c special_characters.c

comp.o: comp.c
	$(CC) -c comp.c

hated_Cyrilli.o: hated_Cyrilli.c
	$(CC) -c hated_Cyrilli.c

output.o: output.c
	$(CC) -c output.c

clean:
	del /Q *.o