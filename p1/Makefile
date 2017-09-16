CFLAGS = -O
CC = g++

test: statistician.o stats.o
		$(CC) $(CFLAGS) -o test statistician.o stats.o

statistician.o: statistician.cpp
		$(CC) $(CFLAGS) -c statistician.cpp

stats.o: stats.cpp
		$(CC) $(CFLAGS) -c stats.cpp

clean:
		rm -f core *.o
