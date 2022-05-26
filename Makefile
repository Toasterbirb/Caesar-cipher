CC=gcc
SRC=./caesar_cipher.c
BIN=./caesar_cipher

all:
	${CC} -g ${SRC} -o ${BIN}

clean:
	rm ./caesar_cipher
