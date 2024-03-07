//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// hash_table.cpp
// Feb 2024
// This file contains the class template implementation for HashTable and Element
//=================================

#include "hash_table.h"
#include <sstream>
#include <list>
#include <iostream>

using namespace std;

//==================================
// Element Class
//==================================

/**
 * @brief Constructor Class
 *
 * Creates an Element Object with no values for key or data
 *
 * @note Pre-Condition: None
 * @note Post-Condition: Creates an Element object
 * @returns none
 */
template <class T>
Element<T>::Element()
{
    // An element initialized with nothing should just be nothing
    data = T();
    key = -1;
    // data(T());
    // key(-1);
}

/**
 * @brief Copy Constructor Class
 *
 * Duplicates the element that was given as an argument
 *
 * @note Pre-Condition: There exist an Element object that can copied
 * @note Post-Condition: Creates an Element object that is the same as the given Element
 * @returns none
 */
template <class T>
Element<T>::Element(const T &d, const int &k)
{
    data = d;
    key = k;
}

/**
 * @brief Constructor Class
 *
 * Creates an element object with values taken from argument
 *
 * @note Pre-Condition: None
 * @note Post-Condition: Creates an Element object whose values are set to the given arguments
 * @returns none
 */
template <class T>
Element<T>::Element(const Element<T> &myElement)
{
    data = myElement.data; // Set data to the given Element's data
    key = myElement.key;   // Set key to the given Element's key
}

/**
 * @brief Deconstructor Class
 *
 * Cleans resources allocated to Element Class
 *
 * @note Pre-Condition: There exist an Element object
 * @note Post-Condition: None
 * @returns none
 */
template <class T>
Element<T>::~Element()
{
    // Nothing needed
}

/**
 * @brief get_key Class
 *
 * Obtains key value from a given element
 *
 * @note Pre-Condition: There exist an Element object with a key
 * @note Post-Condition: None
 * @returns element object's key
 */
template <class T>
int Element<T>::get_key()
{
    return key; // Return the key value of the element
}

/**
 * @brief get_data Class
 *
 * Obtains data value from a given element
 *
 * @note Pre-Condition: There exist an Element object with an object
 * @note Post-Condition: None
 * @returns element object's data value
 */
template <class T>
T Element<T>::get_data()
{
    return data; // Return the data value of the element
}

//==================================
// Hash Table Class
//==================================

/**
 * @brief Constructor Class
 *
 * Creates a HashTable Object with slots set equal to parameter numSlots
 *
 * @note Pre-Condition: None
 * @note Post-Condition: Creates a HashTable object
 * @returns none
 */
template <class T>
HashTable<T>::HashTable(int numSlots)
{
    slots = numSlots;                    // Set slots to the given number of slots
    table = new list<Element<T>>[slots]; // Create a new array of lists of elements
}

// /**
//  * @brief Constructor Class
//  *
//  * Creates a HashTable Object with slots set equal to parameter numSlots
//  *
//  * @note Pre-Condition: None
//  * @note Post-Condition: Creates a HashTable object
//  * @returns none
//  */
template <class T>
HashTable<T>::HashTable(const HashTable<T> &myHashTable)
{
    slots = myHashTable.slots;           // Set slots to the given number of slots
    table = new list<Element<T>>[slots]; // Create a new array of lists of elements

    for (int i = 0; i < slots; ++i) // Copy the elements from the given hash table to the new hash table
    {
        if (myHashTable.table[i].empty()) // If the list is empty, move to the next list
        {
            continue; // Move to the next list
        }

        auto it = myHashTable.table[i].begin(); // iterator to the beginning of the list
        auto end = myHashTable.table[i].end();  // end of the list

        while (it != end) // Copy the elements from the given hash table to the new hash table
        {
            Element<T> e(it->get_data(), it->get_key()); // Create a new element with the same data and key as the given element
            table[i].push_front(e);                      // Insert the element at the front of the list
            ++it;                                        // Move to the next element in the list
        }
    }
}

/**
 * @brief Deconstructor Class
 *
 * Cleans resources allocated to HashTable Class
 *
 * @note Pre-Condition: There exist a HashTable object
 * @note Post-Condition: None
 * @returns none
 */
template <class T>
HashTable<T>::~HashTable(void)
{
    delete[] table; // Deallocate memory for the array
}

/**
 * @brief insert Class
 *
 *
 *
 * @note Pre-Condition:
 * @note Post-Condition:
 * @returns none
 */
template <class T>
void HashTable<T>::insert(const T d, const int k)
{
    // Check if hash table is initiated to 0
    if (slots == 0)
    {
        return;
    }
    Element<T> e(d, k); // Create an element with the given data and key
    int position = k % slots;

    // Check if inserted element is a member
    auto it = table[position].begin(); // iterator to the beginning of the list
    auto end = table[position].end();  // end of the list

    while (it != end) // Check if the element is already in the table
    {
        if (it->get_data() == d && it->get_key() == k) // If the element is already in the table, don't insert it again
        {
            return;
        }
        ++it; // Move to the next element in the list
    }
    // Otherwise insert
    table[position].push_front(e); // Insert the element at the front of the list
}

/**
 * @brief remove Class
 *
 *
 *
 * @note Pre-Condition:
 * @note Post-Condition:
 * @returns
 */
template <class T>
void HashTable<T>::remove(const int k)
{
    // Check if hash table is initiated to 0
    if (slots == 0)
    {
        return;
    }
    // Check if element to be removed is in table
    int position = k % slots;

    auto it = table[position].begin();
    auto end = table[position].end();

    while (it != end)
    {
        // If element with given key is in table, create Element object of the same attributes and remove given Element object
        if (it->get_key() == k)
        {
            table[position].erase(it); // Remove the element from the list
            return;
        }
        else
        {
            ++it; // Move to the next element in the list
        }
    }
}

/**
 * @brief member Class
 *
 * Checks to see if element with parameter data d and key k is in the hash table
 *
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns True if element
 */
template <class T>
bool HashTable<T>::member(const T d, const int k) const
{
    // Check if hash table is initiated to 0
    if (slots == 0)
    {
        return false; // Empty hash table has no members
    }

    int position = k % slots;          // Get the position of the element in the table
    auto it = table[position].begin(); // iterator to the beginning of the list
    auto end = table[position].end();  // end of the list

    if (table[position].empty()) // If the list is empty, the element is not in the table
    {
        return false; // Return false
    }
    else
    {
        while (it != end) // Check if the element is in the table
        {
            if (it->get_data() == d && it->get_key() == k)
            {
                return true;
            }
            ++it; // Move to the next element in the list
        }
        return false;
    }
}

/**
 * @brief to_string Class
 *
 * Converts a HashTable object into a string
 *
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns
 */
template <class T>
string HashTable<T>::to_string() const
{
    stringstream stream;            // Create a string stream
    int slots_counter = 0;          // Counter for the number of slots in the table
    for (int i = 0; i < slots; ++i) // Iterate through the table
    {
        auto it = table[i].begin(); // iterator to the beginning of the list
        auto end = table[i].end();  // end of the list
        stream << i << ":"          // Print the slot number
               << " ";
        while (it != end) // Print the elements in the list
        {
            stream << "(" << it->get_data() << "," << it->get_key() << ")"; // Print the element
            stream << " ";                                                  // Add a space between elements
            ++it;                                                           // Move to the next element in the list
        }
        stream << "\n"; // Add a new line between slots
    }
    return stream.str();
}
