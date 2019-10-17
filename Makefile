CC=gcc
CFLAGS=
LDFLAGS=
EXEC=cMatrice

all: $(EXEC)

cMatrice: testMatrice.o gauss.o main.o
	$(CC) -o $@ $^ $(LDFLAGS) -lm

main.o: gauss.o testMatrice.o

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -lm

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)