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

    int size = atoi(argv[1]); // Number of slots in hashTable

    HashTable<Board> table(size);

    Board b;
    cin >> b;
    while (!cin.eof())
    {

        table.insert(b, b.getHashValue(size));

        cin >> b;
    }

    // The total number of unique items stored in the table
    int number_of_items = 0;
    for (int i = 0; i < size; ++i)
    {
        number_of_items = number_of_items + table.get_slot_count(i);
    }
    cout << "Total number of unique items: " << number_of_items << endl;

    // A bar chart showing the distribution of slot usage for each slot (see below)

    // The average number of items in each slot in the table
    int average_number_of_items_per_slot = number_of_items / size;
    cout << "Average number of items in each slot: " << average_number_of_items_per_slot << endl;

    // The standard deviation of the number of items in each slot

    // The slot count for the minimum number of items in a slot
    int min_slot_items = table.get_slot_count(0);
    for (int i = 1; i < size; ++i)
    {
        if (min_slot_items > table.get_slot_count(i))
        {
            min_slot_items = table.get_slot_count(i);
        }
    }
    cout << "Minimum number of items in a slot: " << min_slot_items << endl;

    // The slot count for the maximum number of items in a slot
    int max_slot_items = table.get_slot_count(0);
    for (int i = 1; i < size; ++i)
    {
        if (max_slot_items > table.get_slot_count(i))
        {
            min_slot_items = table.get_slot_count(i);
        }
    }
    cout << "Maximum number of items in a slot: " << max_slot_items << endl;

    return 0;
}
