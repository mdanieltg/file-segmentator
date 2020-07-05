CXX=g++
CPFLAGS=-std=c++17 -Wall

all: segment

segment: main.o
	g++ -o segment.exe file_seg.o main.o

main.o: file_seg.o main.cpp
	g++ -c $(CPFLAGS) main.cpp

file_seg.o: file_seg.cpp file_seg.h
	g++ -c $(CPFLAGS) file_seg.cpp

clean:
	rm -f file_seg.o main.o

distclean: clean
	rm -f segment.exe
