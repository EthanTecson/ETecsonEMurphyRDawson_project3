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
 * @brief Empty Constructor Class
 *
 * Creates an Element Object with no values for key or data
 *
 * @param none
 * @note Pre-Condition: none
 * @note Post-Condition: Creates an Element object
 * @returns none
 */
template <class T>
Element<T>::Element()
{
    // An element initialized with nothing should just be nothing
    data = T(); // Set to default null value for template data type
    key = -1;
}

/**
 * @brief Constructor Class
 *
 * Creates an Element object with values taken from parameter
 *
 * @param d the data we want to initiate the element with
 * @param k the key we want to initiate the element with
 * @note Pre-Condition: There exist an Element object that can be copied
 * @note Post-Condition: Element object has same data and key from parameter Element
 * @returns none
 */
template <class T>
Element<T>::Element(const T &d, const int &k)
{
    // Sets data and key to parameter values
    data = d;
    key = k;
}

/**
 * @brief Copy Constructor Class
 *
 * Creates an Element object with values taken from argument
 *
 * @param myElement Element object to be copied
 * @note Pre-Condition: none
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
 * @param none
 * @note Pre-Condition: There exist an Element object
 * @note Post-Condition: none
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
 * @param none
 * @note Pre-Condition: There exist an Element object with a key
 * @note Post-Condition: none
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
 * @param none
 * @note Pre-Condition: There exist an Element object with an object
 * @note Post-Condition: none
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
 * @param int numSlots
 * @note Pre-Condition: none
 * @note Post-Condition: Creates a HashTable object
 * @returns none
 */
template <class T>
HashTable<T>::HashTable(int numSlots)
{
    slots = numSlots;                    // Set slots to the given number of slots
    table = new list<Element<T>>[slots]; // Create a new array of lists of elements
}

/**
 * @brief Copy Constructor Class
 *
 * Copies a parameter HashTable object
 *
 * @param const HashTable<T> &myHashTable - hash table to be copied
 * @note Pre-Condition: none
 * @note Post-Condition: Creates a HashTable object
 * @returns none
 */
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
 * @param none
 * @note Pre-Condition: There exist a HashTable object
 * @note Post-Condition: none
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
 * Inserts an element with data d and key k into the hash table
 *
 * @param const T d data and const int k key
 * @note Pre-Condition: data is of the same data type as the hash table
 * @note Post-Condition: An element with data d and key k is in the hash table
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
 * Removes the element with key k from the hash table
 *
 * @param const int k key
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns none
 */
template <class T>
void HashTable<T>::remove(const int k)
{
    // If hash table is empty, nothing to remove
    if (slots == 0)
    {
        return;
    }
    int position = k % slots; // Find slot to be searched

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
 * @param const T d data and const int k key
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns True if Element is in the hash table, false otherwise
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
 * @param none
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns string version of HashTable object
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

/**
 * @brief get_slot_count Class
 *
 * Calculates number of items in given HashTable slot by using the list class method size().
 * Size() will return the number of elements in the linked list at the given slot.
 *
 * @param slot HashTable slot
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns An integer representing the number of items in a HashTable slot
 */
template <class T>
int HashTable<T>::get_slot_count(const int slot) const
{
    return table[slot].size();
}