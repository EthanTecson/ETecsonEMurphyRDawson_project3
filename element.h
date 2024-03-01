//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// element.h
// Feb 2024
// This file contains the class template header for element
//=================================

#include <iostream>
#include <string>
using namespace std;

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
    Element(T d, T k);                    // Initialize element with data and key
    ~Element(void);                       // Deconstrcutor
    int get_key();                        // Instructions say that this method should return the NUMERIC key but I was not sure if keys were able to non-numeric like a string.
    T get_data();                         // Returns data of element
};

#endif