COMPILE = g++
FLAGS = -Werror -Wall -ansi
all: clean
	$(COMPILE) $(FLAGS) test.cpp iterator.cpp composite.cpp

clean:
	rm -rf ./a.out
