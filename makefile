CC:=gcc
LD:=gcc

CFLAGS:=-g -Wall -Wextra -std=gnu17 -O2
LDFLAGS:= -lncurses 

OBJ:=obj
SRC:=src
BIN:=bin

DIRS:=$(shell find src/ -type d)
BUILD_DIRS:=$(patsubst $(SRC)/%, $(OBJ)/%, $(DIRS))


SRCS:=$(shell find src -name *.c)
OBJS:=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

TARGET:= $(BIN)/editor



.PHONY: all clean dirs run

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	@rm -rf bin/*
	@rm -rf obj/*

run:
	@./$(TARGET)
