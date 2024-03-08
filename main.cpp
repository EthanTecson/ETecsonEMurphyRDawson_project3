//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// main.cpp
// Feb 2024
// This file contains use case scenarios of our functions with the Board class
//=================================

#include "Board.h"
#include "hash_table.cpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: you must include the hash table size as a");
        printf(" command-line parameter.\n");
        exit(0);
    }
    int size = atoi(argv[1]);

    HashTable<Board> table(size);

    Board b;
    cin >> b;
    while (!cin.eof())
    {

        table.insert(b, b.getHashValue(size));

        cin >> b;
    }

    return 0;
}
