CC = gcc
CFLAGS = -std=c99

SRCS = main.c champion.c
OBJS = $(SRCS:.c=.o)

TARGET = project3Exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c champion.h
champion.o: champion.c champion.h

clean:
	rm -f $(OBJS) $(TARGET)
