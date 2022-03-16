CC = g++
TARGET = main
objects = main.o calculator.o

main: $(objects)
	$(CC) -o $@ $^

.PHNOY: clean
clean:
	-del main.exe $(objects)