objects = main.o


main: $(objects)
	g++ -o $@ $^ -lpthread
$(objects):

.PHONY:clean
clean:
	-del main.exe $(objects)