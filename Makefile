CC = g++
LFLAGS = -W -lncurses -std=c++11 -I.
HDIR = src/include/
ODIR = src/obj/
SDIR = src/

_DEPS = animal.h cage.h cell.h driver.h renderable.h zoo.h
DEPS = $(patsubst %,$(HDIR)%,$(_DEPS))

_OBJ = animal.o cage.o cell.o driver.o test.o zoo.o
OBJ = $(patsubst %,$(ODIR)%,$(_OBJ))

$(ODIR)%.o : $(SDIR)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(LFLAGS)

Main : $(OBJ)
	$(CC) -o $@ $^ $(LFLAGS)

.PHONY : clean
clean :
	rm -f $(ODIR)*.o *~ core
