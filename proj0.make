#Variables
TARGET = decode
SRC = project0.c
OBJ = $(SRC:.c=.o)
CFLAGS = -g

all: $(TARGET)

#Compiles TARGET using all the OBJ files
$(TARGET): $(OBJ)
  $(CC) $(CFLAGS) $(TARGET).c $(OBJ) -o $(TARGET)
  
#pattern rule to make all obj files. $< translates to source file. $@ is the target
%.o: %.c
  $(CC) -c $(CFLAGS) $< -o $@
  
#removes all object files and the exe
clean:
  rm -f $(OBJ) $(TARGET).o $(TARGET)
    
    

