CXX := g++
CFLAGS := -O3 -Wall
SFMLLIB := -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS := -s -lm

.PHONY: all clean

all: main.x min.x

min.x: min.o

main.x: main.o GameClass.o GameState.o State.o MainMenuState.o

MainMenuState.o: MainMenuState.cc

State.o: State.cc

GameState.o: GameState.cc

GameClass.o: GameClass.cc

main.o: main.cc

mic.o: min.cc

%.x: %.o
	$(CXX) $(LDFLAGS) $^ -o $@ $(SFMLLIB)
%.o: %.cc
	$(CXX) $(CFLAGS) $^ -c -o $@
clean:
	$(RM) $(wildcard *.[ox])