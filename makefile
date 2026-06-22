CXX = g++
COBC = cobc

CPP_SRC = CPP/pong.cpp
COB_SRC = Cobol/pong.cob

LIB = bin/libpongCPP.so
EXE = bin/pong

SDL_FLAGS = $(shell pkg-config --cflags --libs sdl2 SDL2_ttf)

all: $(LIB) $(EXE)

$(LIB): $(CPP_SRC)
	mkdir -p bin
	$(CXX) -shared -fPIC $< -o $@ $(SDL_FLAGS)

$(EXE): $(COB_SRC) $(LIB)
	$(COBC) -x $< \
		-Lbin \
		-lpongCPP \
		-lstdc++ \
		-o $@

run: all
	LD_LIBRARY_PATH=bin ./$(EXE)

clean:
	rm -f $(LIB) $(EXE)

.PHONY: all run clean