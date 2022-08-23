CC = g++
TAR = main
objects = main.o extern.o

$(TAR): $(objects)
	$(CC) -g -o $@ $^
$(objects):

.PHONY:clean
clean:
	-del $(TAR).exe $(objects)