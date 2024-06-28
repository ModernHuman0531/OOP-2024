OBJ = lab4.o
all:build run clean	#makefile include three element , target(usually the execution file name, sometimes will be action),prerequiste(the file is needed to run the command),command(action)

.PHONY: all #all is not execution file, it is fake target

build:lab4.cpp
	g++ lab4.cpp -o ${OBJ}
run:
	./${OBJ}
clean:
	rm ${OBJ}