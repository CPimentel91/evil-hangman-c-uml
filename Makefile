CC = gcc
CFLAGS = -g -Wall --std=c99
DEPS = my_string.h Status.h
OBJECTS = my_string.o string_driver.o
OBJECTS2 = test_def.o unit_test.o my_string.o

all: string_driver unit_test

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

string_driver.o: my_string.c $(DEPS) 
	$(CC) $(CFLAGS) -c string_driver.c 

my_string.o: my_string.c $(DEPS)
	$(CC) $(CFLAGS) -c my_string.c

unit_test: $(OBJECTS2)
	$(CC) $(CFLAGS) -o unit_test $(OBJECTS2)

test_def.o: test_def.c $(DEPS) unit_test.h
	$(CC) $(CFLAGS) -c test_def.c

unit_test.o: unit_test.c $(DEPS) unit_test.h
	$(CC) $(CFLAGS) -c unit_test.c

clean:
	rm string_driver $(OBJECTS) unit_test test_def.o unit_test.o

