CC = g++
TAR = main
objects = $(TAR).o Tree.o

$(TAR): $(objects)
	$(CC) -o $@ $^

$(objects):

.PHONY:clean
clean:
	-del $(TAR).exe $(objects)