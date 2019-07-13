CC=g++
CFLAGS=-I/usr/include/python3.6 
INCLUDES=-lpython3.6
LDFLAGS=-L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu
INCL=-I/opt/include/python3.6m -I/opt/include/python3.6m -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes
LINK=-L/opt/lib/python3.6/config-3.6m -lpthread -ldl -lutil -lm -lpython3.6m -Xlinker -export-dynamic

all: test test2

test:
	$(CC) $(CFLAGS) executabletest.cpp $(LDFLAGS) $(INCLUDES) -o test

test2:
	$(CC) $(CFLAGS) executabletest2.cpp $(LDFLAGS) $(INCLUDES) -o test2
