//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// hash_table.h
// Feb 2024
// This file contains the class template header for hash_table
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
    T key;
    
public:
    Element();                            // Can just initialize element without values
    Element(const Element<T> &myElement); // Copy constructor
    Element(const T &d, const int &k);      // Initialize element with data and key
    ~Element(void);                       // Deconstrcutor
    int get_key();                        // Instructions say that this method should return the NUMERIC key but I was not sure if keys were able to non-numeric like a string.
    T get_data();                         // Returns data of element
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
    list<Element<T>>* table; 

public:
    HashTable(int numSlots);                       // After looking at test cases, I think HashTable always needs to be initiated with a number of slots
    HashTable(const HashTable<T> &myHashTable); // Copy Constructor
    ~HashTable(void);                           // Deconstructor
    void insert(const T d, const int k);          // Inserts data d with key k by inserting at head of double linked list. Reading says that if a slot is not empty, it contains a pointer that points to a doubly linked list.
    void remove(const int k);                     // Removes element of value k (we are allowed to assume that all keys are distinct)
    bool member(const T d, const int k) const;    // check to see if an element with data d and key k is apart of the HashTable
    string to_string() const;
};

#endif
