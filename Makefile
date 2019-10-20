CC=gcc
CFLAGS=
LDFLAGS=
EXEC=cMatrice

all: $(EXEC)

cMatrice: testMatrice.o gauss.o cholesky.o main.o display.o testing.o
	$(CC) -o $@ $^ $(LDFLAGS) -lm

main.o: testing.o

testing.o: gauss.o testMatrice.o cholesky.o display.o

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -lm

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)