//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// hash_table.h
// Feb 2024
// This file contains the class template header for the HashTable class and Element Class
//=================================

#include <iostream>
#include <string>
#include <list>
using namespace std;

//==================================
// Element Class
//==================================

#ifndef ELEMENT_H
#define ELEMENT_H

template <class T>
class Element
{
private:
    T data;
    int key;

public:
    Element();                            // Can just initialize element without values
    Element(const Element<T> &myElement); // Copy constructor
    Element(const T &d, const int &k);    // Initialize element with data and key
    ~Element(void);                       // Deconstrcutor
    int get_key();                        // returns key
    T get_data();                         // returns data
};

#endif

//==================================
// Hash Table Class
//==================================

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <class T>
class HashTable
{
private:
    int slots;
    list<Element<T>> *table;

public:
    HashTable(int numSlots);                    // HashTable initiated with number of slots
    HashTable(const HashTable<T> &myHashTable); // Copy Constructor
    ~HashTable(void);                           // Deconstructor
    void insert(const T d, const int k);        // Insert data and key (no duplicates of data,key pair)
    void remove(const int k);                   // Removes element with key k
    bool member(const T d, const int k) const;  // check to see if an element with data d and key k is apart of the HashTable
    string to_string() const;                   // Convert HashTable to a string
    int get_slot_count(const int slot) const;   // Returns number of elements in a given slot
};

#endif
