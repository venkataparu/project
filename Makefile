TARGET=nbse 
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall
.PHONY: default all clean
default: $(TARGET)
all:  default
$(TARGET): nbserror.o
	$(CC) nbserror.o -Wall $(LIBS)

nbserror.o: nbserror.c
	$(CC) $(CFLAGS) -c nbserror.c -o nbserror.o
clean:
	-rm -f nbserror.o
	-rm -f $(TARGET)

