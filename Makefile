EXE = footy
LIBS = -lcurl

all: main.o http.o
	$(CC) -o $(EXE) $^ $(LIBS)

main.o: main.c
	$(CC) -c $<

http.o: src/http.c
	$(CC) -c $<

clean:
	rm *.o $(EXE)
