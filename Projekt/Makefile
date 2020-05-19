CXX := g++
CFLAGS := -O3 -Wall
SFMLLIB := -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS := -s -lm

.PHONY: all clean

all: main.x

main.x: main.o GameClass.o

GameClass.o: GameClass.cc

main.o: main.cc

%.x: %.o
	$(CXX) $(LDFLAGS) $^ -o $@ $(SFMLLIB)
%.o: %.cc
	$(CXX) $(CFLAGS) $^ -c -o $@
clean:
	$(RM) $(wildcard *.[ox])
