CPP = gcc
OFLAG = -o
CPPFLAGS = -Wall
LIBFLAGS = `pkg-config --cflags --libs allegro` -lstdc++
.SUFFIXES : .o .cpp .c
.cpp.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<
.c.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<

Trivia:	main.cpp game.o game.h aux.h aux.o
	$(CPP) $(CPPFLAGS) main.cpp aux.o game.o $(LIBFLAGS) $(OFLAG) Trivia

aux.o:	aux.h aux.cpp

game.o: game.cpp game.h

clean:
	rm -f *.o Trivia
