EXE = footy
LIBS = -lcurl
CFLAGS = -O3 -g -Wall -Wextra

SRC_DIR = src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
# OBJ_DIR = obj
# SRC_DIR = src
# SRC_FILES = $(shell find . -name "*.c")
# OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(OBJ_FILES)
	$(CC) -o $(EXE) $^ $(LIBS) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean
clean:
	rm $(wildcard $(OBJ_DIR)/*.o) $(EXE)

