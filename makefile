#Variables
TARGET = project0
SRC = source.c list.c
OBJ = $(SRC:.c=.o)
HEAD = list.h
CFLAGS = -g
CC = gcc

all: $(TARGET)

#Compiles TARGET using all the OBJ files
$(TARGET): $(OBJ) $(HEAD)
	$(CC) $(CFLAGS) -c $^ -o $@

#pattern rule to make all obj files. $< translates to source file. $@ is the target
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#removes all object files and the exe
clean:
	rm -f *.o $(TARGET)
