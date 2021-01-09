all:test.c prod_con.h prod_con.c
	gcc test.c prod_con.c -c

test.o:test.c prod_con.h
	gcc test.c -c
prod_con.o:prod_con.c prod_con.h
	gcc prod_con.c -c

all.out:test.o prod_con.o 
	gcc test.o prod_con.o  -o all.out -lpthread

run:all.out
	./all.out
clean:
	rm -rf *.o all.out


