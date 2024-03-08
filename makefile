all: hash1 hash2 hash3 test 

# Compile hash3
hash3: main.cpp Board.h Board.cpp hash_table.cpp hash_table.h
	g++ -std=c++11 -o hash3 -DHASHFUNCTION3 main.cpp Board.cpp

# Compile hash2
hash2: main.cpp Board.h Board.cpp hash_table.cpp hash_table.h
	g++ -std=c++11 -o hash2 -DHASHFUNCTION2 main.cpp Board.cpp

# Compile hash1
hash1: main.cpp Board.h Board.cpp hash_table.cpp hash_table.h
	g++ -std=c++11 -o hash1 -DHASHFUNCTION1 main.cpp Board.cpp


# compiles our HashTable + Element class into 'test' executable
test: hash_table.o test_hash_table.o
	g++ hash_table.o test_hash_table.o -o test

test_hash_table.o: test_hash_table.cpp
	g++ -std=c++11 -c test_hash_table.cpp

hash_table.o: hash_table.cpp hash_table.h 
	g++ -std=c++11 -c hash_table.cpp


clean:
	rm *.o hash1 hash2 hash3 test sampleRead a.out