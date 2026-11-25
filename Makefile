# -*- MakeFile -*-


CC := gcc
CFLAGS := -Wall -Wextra -O2 -g -Iinclude
OBJS = obj/test.o obj/cdp.o obj/vector.o
BIN = bin/run_test


all:$(BIN)

bin/run_test : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -r bin/* obj/* 
