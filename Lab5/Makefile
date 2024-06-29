OBJ = Lab5.o
all:build run clean

.PHONY:all
build:Lab5.cpp
	g++ Lab5.cpp -o  ${OBJ}
run:Lab5.o
	./${OBJ}
clean:
	rm ${OBJ}