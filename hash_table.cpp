//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// hash_table.cpp
// Feb 2024
// This file contains the class template implementation for HashTable and Element
//=================================

#include "hash_table.h"

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
    head = NULL;
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
Element<T>::Element(const Element<T> &myElement)
{
    if (myElement.head == NULL){
        head = NULL;
    }
    else {
    head = new Node;

    head->next = NULL;
    head->previous = NULL;
    head->data = myElement.head->data;
    head->key = myElement.head->key;
    }
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
Element<T>::Element(const T &d, const T &k)
{
    head = new Node;
    head->next = NULL;
    head->previous = NULL;
    head->data = d;
    head->key = k;
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
    Node *ptr = head; // Set pointer to head
    while (ptr != NULL)
    {
        Node *next = ptr->next; // Set a pointer to next value of ptr
        delete ptr;             // Delete ptr node
        ptr = next;
    }
    head = NULL;
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
    if (head){
        return head->key;
    }
    return -1;
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
    if (head){
        return head->data;
    }
    return -0;
}

//==================================
// Hash Table Class
//==================================
//Default Constructor
template <class T>
HashTable<T>::HashTable(int numSlots)
{
    slots = numSlots;
}            

//Copy Constructor
template <class T>
HashTable<T>::HashTable(const HashTable<T> &myHashTable)
{
    slots = myHashTable.slots;
}

//Deconstructor
template <class T>
HashTable<T>::~HashTable(void)
{

}

//Insert
template <class T>
void HashTable<T>::insert(const T d, const T k)
{
    Element<T> e(d,k);
    if(!(member(d, k))) // should not insert duplicates
    {
        int position = hash(k); // placeholder for the hash function

        // Check if slot is empty (emptySlot function?)
            // If yes, head = e
            // Else, e->next = head->item, e->prev = NULL, head = e
    }
}

//Remove
template <class T>
void HashTable<T>::remove(const T k)
{
    if((member(d, k))) // should only remove somethiing in the table
    {
        int position = hash(k); //placeholder for the hash function
        

    }

}              

//Member 
template <class T>
bool HashTable<T>::member(const T d, const T k) const
{

}

//To-String
template <class T>
string HashTable<T>::to_string() const
{

}