CFLAGS = -O
CC = g++ 

test: rec_fun_test.o rec_fun.o
		$(CC) $(CFLAGS) -o test rec_fun_test.o rec_fun.o

rec_fun_test.o: rec_fun_test.cpp
		$(CC) $(CFLAGS) -c rec_fun_test.cpp

rec_fun.o: rec_fun.cpp
		$(CC) $(CFLAGS) -c rec_fun.cpp

clean:
		rm -f core *.o
