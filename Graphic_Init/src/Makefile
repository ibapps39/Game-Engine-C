IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=./obj
LDIR =../lib
SDLDIR =../include/SDL2
LIBS=-lm

_DEPS = Graphics.h TestStateManager.h SDL/*.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = StateManager.o TestStateManager.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_SDL_DLL = SDL2.dll
SDL_DLL = $(patsubst %,$(SDLDIR)/%,$(_SDL_DLL))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Graphics: $(OBJ) $(SDL_DLL)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 