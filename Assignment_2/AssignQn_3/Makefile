
all: test.c func.h func.c
	gcc test.c func.c -c

test.o: test.c func.h
	gcc test.c -c
func.o: func.c func.h
	gcc func.c -c

all.out: test.o func.o 
	gcc test.o func.o  -o all.out -lpthread

run: all.out
	./all.out
clean:
	rm -rf *.o all.out


