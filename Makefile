# Game Maker Studio NEO

# Version
VERSION = 0.0

# Project Name
NAME = default

# Includes and Libs
INCS = 
LIBS = 

# Flags
CFLAGS = ${INCS}
LDFLAGS = ${LIBS}

# Compiler
CC = gcc

SRC = default.c
OBJ = ${SRC:.c=.o} default.h

all: options build

options:
	@echo gmsNEO build options:
	@echo "CFLAGS	= ${CFLAGS}"
	@echo "LDFLAGS	= ${LDFLAGS}"
	@echo "CC	= ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

build: ${OBJ}
	${CC} -o ${NAME} ${OBJ} ${LDFLAGS}

clean:
	rm -f ${NAME} ${OBJ}

.PHONY: all options clean