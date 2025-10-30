CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = bigbinary
OBJS = main.o BigBinary.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c BigBinary.h
	$(CC) $(CFLAGS) -c main.c

BigBinary.o: BigBinary.c BigBinary.h
	$(CC) $(CFLAGS) -c BigBinary.c

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
