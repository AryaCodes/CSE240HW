all: main

CXXFLAGS+=-g -Wall
LDLIBS+=-lstdc++
main: tawde_list.o main.o