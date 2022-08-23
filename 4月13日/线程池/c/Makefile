TAR = main
objects = main.o
CC = gcc

$(TAR): $(objects)
	$(CC) -o $@ $^
$(objects):

.PHONY:clean
clean:
	-del $(TAR).exe $(objects)