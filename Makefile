all: gcc.o
	cc -o main.out main.o
gcc.o:
	cc -c main.c

.PHONY: clean run
clean:
	rm -rf *.out *.o
run:
	./main.out
