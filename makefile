# all: hash1 hash2 hash3 test sampleRead

# sampleRead: sampleRead.cpp Board.h Board.cpp
# 	g++ -o sampleRead sampleRead.cpp Board.cpp
	
# hash3: main.cpp Board.h Board.cpp Hash.h Hash.cpp List.h List.cpp
# 	g++ -o hash3 -DHASHFUNCTION3 main.cpp Board.cpp

# hash2: main.cpp Board.h Board.cpp Hash.h Hash.cpp List.h List.cpp
# 	g++ -o hash2 -DHASHFUNCTION2 main.cpp Board.cpp

# hash1: main.cpp Board.h Board.cpp Hash.h Hash.cpp List.h List.cpp
# 	g++ -o hash1 -DHASHFUNCTION1 main.cpp Board.cpp


# compiles our HashTable + Element class into 'test' executable
test: hash_table.o test_hash_table.o
	g++ hash_table.o test_hash_table.o -o test

test_hash_table.o: test_hash_table.cpp
	g++ -std=c++11 -c test_hash_table.cpp

hash_table.o: hash_table.cpp hash_table.h 
	g++ -std=c++11 -c hash_table.cpp

# Compiles sampleRead
sampleRead: sampleRead.o Board.o
	g++ sampleRead.o Board.o -o sampleRead

sampleRead.o: sampleRead.cpp
	g++ -std=c++11 -c sampleRead.cpp

Board.o: Board.cpp Board.h
	g++ -std=c++11 -c Board.cpp

# # Hash 1
# hash1: main.o Board.o hash_table.o
# 	g++ -DHASHFUNCTION1 main.o Board.p hash_table.o -o hash1

# main.o: main.cpp
# 	g++ -std=c++11 -c main.cpp

# Board.o: Board.cpp Board.h
# 	g++ -std=c++11 -c Board.cpp

# hash_table.o: hash_table.cpp hash_table.h 
# 	g++ -std=c++11 -c hash_table.cpp

# # Hash 2
# hash2: main.o Board.o hash_table.o
# 	g++ -DHASHFUNCTION2 main.o Board.p hash_table.o -o hash2

# main.o: main.cpp
# 	g++ -std=c++11 -c main.cpp

# Board.o: Board.cpp Board.h
# 	g++ -std=c++11 -c Board.cpp

# hash_table.o: hash_table.cpp hash_table.h 
# 	g++ -std=c++11 -c hash_table.cpp


# # Hash 3
# hash3: main.o Board.o hash_table.o
# 	g++ -DHASHFUNCTION3 main.o Board.p hash_table.o -o hash3

# main.o: main.cpp
# 	g++ -std=c++11 -c main.cpp

# Board.o: Board.cpp Board.h
# 	g++ -std=c++11 -c Board.cpp

# hash_table.o: hash_table.cpp hash_table.h 
# 	g++ -std=c++11 -c hash_table.cpp


# all: hash1 hash2 hash3 test sampleRead

all: test sampleRead

clean:
	rm *.o hash1 hash2 hash3 test sampleRead a.out