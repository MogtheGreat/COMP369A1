CPP = gcc
OFLAG = -o
CPPFLAGS = -Wall
LIBFLAGS = `pkg-config --cflags --libs allegro` -lstdc++
.SUFFIXES : .o .cpp .c
.cpp.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<
.c.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<

Trivia:	main.cpp game.o game.h auxi.h auxi.o question.o question.h
	$(CPP) $(CPPFLAGS) main.cpp auxi.o game.o question.o $(LIBFLAGS) $(OFLAG) Trivia

auxi.o:	auxi.h auxi.cpp

game.o: game.cpp game.h

question.o: question.cpp question.h

clean:
	rm -f *.o Trivia
