CPP = gcc
OFLAG = -o
CPPFLAGS = -Wall
LIBFLAGS = `pkg-config --cflags --libs allegro` -lstdc++
.SUFFIXES : .o .cpp .c
.cpp.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<
.c.o:
	$(CPP) $(LIBFLAGS) $(CPPFLAGS) -c $<

Trivia:	main.cpp
	$(CPP) $(CPPFLAGS) main.cpp $(LIBFLAGS) $(OFLAG) Trivia

clean:
	rm -f *.o Trivia
