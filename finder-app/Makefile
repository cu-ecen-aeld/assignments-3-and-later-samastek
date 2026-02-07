CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror -g
TARGET := writer finder

.PHONY: all clean

all: $(TARGET)

writer: writer.c
	$(CC) $(CFLAGS) -o writer writer.c

finder: finder.c
	$(CC) $(CFLAGS) -o finder finder.c
clean:
	rm -f $(TARGET) *.o