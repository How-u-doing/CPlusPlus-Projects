CC := g++
CFLAGS := -std=c++17 -Wall -g

OBJS := Student.o List.o
TESTS := Student_test List_test 

all: $(TESTS) 

test: $(TESTS)

Student_test: Student_test.cpp Student.o
	$(CC) -o $@ $^

List_test: List_test.cpp List.o Student.o
	$(CC) -o $@ $^

Student.o: Student.cpp Student.h
	$(CC) $(CFLAGS) -c $<

List.o: List.cpp List.h mySort.h Student.o
	$(CC) $(CFLAGS) -c $< 

clean:
	rm -f *.o $(TESTS)

.PHONY: all test clean
