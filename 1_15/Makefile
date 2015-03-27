# Makefile for test project.

SOURCE := main.cpp
DIST := testprogram 

.PHONY : build test

all : build test

build : 
	g++ $(SOURCE) -o $(DIST)

test : build
	./$(DIST)

clean :
	rm $(DIST)