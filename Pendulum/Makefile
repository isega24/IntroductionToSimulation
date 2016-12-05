CC=clang++-3.8
CFLAGS=-c
LDFLAGS=
BIN=./bin
SRC=./src
OBJ=./obj
RES=./results
TXT=./txt
vpath %.cpp src
vpath %.h include

PROGRAM=$(BIN)/pendulum
OBJS=$(OBJ)/pendulum.o
SRCS=$(SRC)/pendulum.cpp
PAINT=paint.py

all:$(PROGRAM)

git:
	make clean
	git add -A
	git commit -m "Planets program modifications"
	git push



$(PROGRAM): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

%.txt:all
	$(PROGRAM) < $(TXT)/$@ > $(RES)/results$@
	python $(PAINT) $(RES)/results$@


clean:
	rm $(BIN)/* $(OBJ)/* $(RES)/*
