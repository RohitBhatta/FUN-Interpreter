CFLAGS=-g -std=c99 -O0 -Werror -Wall

p1 : p1.o Makefile
	gcc $(CFLAGS) -o p1 p1.o

%.o : %.c Makefile
	gcc $(CFLAGS) -MD -c $*.c

%.o : %.S Makefile
	gcc $(CFLAGS) -MD -c $*.S

test : Makefile p1
	./p1 "x = 123_345 ; a = 27; ; z = 2z2; c = 45; " > t1.out
	@((diff -b t1.out t1.ok > /dev/null) && echo "pass") || (echo "fail" ; echo "--- expected ---"; cat t1.ok; echo "--- found ---" ; cat t1.out)

clean :
	rm -f *.d
	rm -f *.o
	rm -f p1

-include *.d
