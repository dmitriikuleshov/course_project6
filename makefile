# Компилятор и опции компиляции
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PARAMETER ?=

# Директории
SRC_DIR = src
BIN_DIR = bin
$(shell mkdir -p $(BIN_DIR))


all:
	$(CC) $(CFLAGS) $(SRC_DIR)/read_db.c -o $(BIN_DIR)/read_db
	$(CC) $(CFLAGS) $(SRC_DIR)/create_db.c -o $(BIN_DIR)/create_db
	$(CC) $(CFLAGS) $(SRC_DIR)/gentxt_db.c -o $(BIN_DIR)/gentxt_db


bin_db:
	$(CC) $(CFLAGS) $(SRC_DIR)/read_db.c -o $(BIN_DIR)/read_db
	$(CC) $(CFLAGS) $(SRC_DIR)/create_db.c -o $(BIN_DIR)/create_db
	$(CC) $(CFLAGS) $(SRC_DIR)/gentxt_db.c -o $(BIN_DIR)/gentxt_db
	./bin/gentxt_db -f ./bin/data.txt -p 20
	./bin/create_db ./bin/data.txt ./bin/data

read_db:
	./bin/read_db ./bin/data -f -p $(PARAMETER)
	

# Чистка проекта
clean:
	rm -rf $(BIN_DIR)

