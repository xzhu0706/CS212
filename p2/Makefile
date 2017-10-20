CFLAGS = -O
CC = g++

test: sequence_exam.o sequence1.o
		$(CC) $(CFLAGS) -o test sequence_exam.o sequence1.o

sequence_exam.o: sequence_exam.cpp
		$(CC) $(CFLAGS) -c sequence_exam.cpp

sequence1.o: sequence1.cpp
		$(CC) $(CFLAGS) -c sequence1.cpp

clean:
		rm -f core *.o
