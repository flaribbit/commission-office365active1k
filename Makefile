CC=g++
CFLAGS=-lcomctl32 -static -s -O2 -DNDEBUG -mwindows

all: main.cpp resource.o
	${CC} main.cpp resource.o ${CFLAGS} -o main.exe

resource.o: resource.h resource.rc
	windres resource.rc -o resource.o
