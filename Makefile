CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -Wcast-align -Wconversion -Wunreachable-code
OBJ = main.o
TARGET = hrish

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(TARGET)