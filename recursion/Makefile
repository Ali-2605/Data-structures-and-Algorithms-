CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS := $(wildcard *.c)
EXEC := $(patsubst %.c,%,$(SRCS))

all: $(EXEC)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

run-%: %
	./$<
	
clean:
	rm -f $(EXEC)

