foo = a.o b.o c.o
bar = $(foo:.o=.c)
CC = gcc
libs_for_gcc = -lgnu
normal_libs = 

ifeq ($(CC), gcc)
	libs = $(libs_for_gcc)
else
	libs = $(normal_libs)
endif

ifdef foo
	frobozz = yes
else
	frobozz = no
endif

ifndef normal_libs
	is_null = yes
else
	is_null = no
endif


all: test func_test
	@echo "Hello World!"
test:
	@echo $(foo) $(bar) $(libs) $(frobozz) $(is_null)
func_test:
	$(subsst ee,EE,feet on the street)