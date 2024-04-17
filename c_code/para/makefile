CC = gcc
CFLAGS = -Wall -Wextra -pedantic
SRCS = main.c sort.c compare.c
OBJS = $(SRCS:.c=.o)
EXEC = program

$(EXEC): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

%.o: %.c
    $(CC) $(CFLAGS) -c $<

clean:
    rm -f $(EXEC) $(OBJS)
