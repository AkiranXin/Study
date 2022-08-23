CC = g++
objects = main.o student.o
TAR = main

$(TAR):$(objects)
	$(CC) -o $@ $^
$(objects):

.PHONY:clean
clean:
	-del $(TAR).exe $(objects)