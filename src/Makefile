
TARGET = main

SRC = main.c 2-3-tree-lib/2-3-tree.c
#SRC = $(wildcard **/*.c)
#INC = 2-3-tree-lib/2-3-tree.h common/common.h
BIN = bin

#SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %,$(BIN)/%, $(notdir $(SRC:.c=.o)))

CC = gcc
CFLAGS = -Wall -I$(INC)

#$(BIN)/$(TARGET) : $(OBJECT)
#	$(CC) -o $@ $ˆ

#$(BIN)/%.o : $(SRC)/%.c
#	$(CC) $(CFLAGS) -c $< -o $@



help:
	@echo "src: $(SRC)"
	@echo "obj: $(OBJECT)"

clean:
	rm -f $(OBJECT)
