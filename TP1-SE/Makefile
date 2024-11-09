TARGET = main
CC = clang
CFLAGS = -Wall -Wextra -g
SRC = main.c iplot.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

distclean: clean
	rm -f commandes.gp
