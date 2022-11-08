CC = g++
CFLAGS = -c -std=c++11 -pedantic
OBJ = pythagoras.o PTree.o Tree.o
LIBS  = -lsfml-graphics -lsfml-window -lsfml-system
EXE = treep

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
