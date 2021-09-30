#Variables
TARGET = project0
SRC = source.c list.c
OBJ = $(SRC:.c=.o)
HEAD = list.h
CC = gcc -g

all: $(TARGET)

#Compiles TARGET using all the OBJ files
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

#Both (all) .c files require list.h to build
%.o: %.c $(HEAD)
	$(CC) -c $< -o $@

#removes all object files and the exe
clean:
	rm -f $(OBJ) $(TARGET)
