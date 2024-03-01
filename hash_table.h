//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// hash_table.h
// Feb 2024
// This file contains the class template header for hash_table
//=================================

#include <iostream>
#include <string>
using namespace std;


#ifndef HASH_TABLE_H
#define HASH_TABLE_H


template <class T>
class HashTable
{
    private:

    // Still need to be done. May have to coorelate with linked list and how we decide to implement our hash function.
        
    public:
        HashTable(int slots); // After looking at test cases, I think HashTable always needs to be initiated with a number of slots
        HashTable(const HashTable<T> &myHashTable); // Not sure if we need this or not but I thew it in here
        ~HashTable(void); // Deconstructor
        void insert(const T d, const T k); // Inserts data d with key k by inserting at head of double linked list. Reading says that if a slot is not empty, it contains a pointer that points to a doubly linked list.
        void remove(const T k); // Removes element of value k (we are allowed to assume that all keys are distinct)
        bool member(const T d, const T k) const; // check to see if an element with data d and key k is apart of the HashTable
        string to_string() const;
};


#endif