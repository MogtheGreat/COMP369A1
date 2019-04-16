CPP = gcc
OFLAG = -o
CPPFLAGS = -Wall
LIBFLAGS = `pkg-config --cflags --libs allegro` -lstdc++
.SUFFIXES : .o .cpp .c
.cpp.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<
.c.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<

Trivia:	main.cpp aux.h aux.o main.h
	$(CPP) $(CPPFLAGS) main.cpp aux.o $(LIBFLAGS) $(OFLAG) Trivia

aux.o:	aux.h aux.cpp

clean:
	rm -f *.o Trivia
