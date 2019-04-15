CPP = gcc
OFLAG = -o
CPPFLAGS = -Wall
LIBFLAGS = `pkg-config --cflags --libs allegro` -lstdc++
.SUFFIXES : .o .cpp .c
.cpp.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<
.c.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<

Trivia:	main.c
	$(CPP) $(CPPFLAGS) main.c $(LIBFLAGS) $(OFLAG) Trivia

clean:
	rm -f *.o Trivia
