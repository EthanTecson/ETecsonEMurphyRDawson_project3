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
    array = new T*[numSlots];
    for (int i = 0; i < numSlots; ++i){
        array[i] = nullptr;
    }
}

/**
 * @brief Constructor Class
 *
 * Creates a HashTable Object with slots set equal to parameter numSlots
 *
 * @note Pre-Condition: None
 * @note Post-Condition: Creates a HashTable object
 * @returns none
 */
// template <class T>
// HashTable<T>::HashTable(const HashTable<T> &myHashTable)
// {
//     slots = myHashTable.slots;
//     array = new T*[slots];
//     for (int i = 0; i < slots; ++i) {
//         if (myHashTable.array[i] != nullptr) {
//             // Allocate memory for a new element and copy the value
//             array[i] = new T(*(myHashTable.array[i]));
//         } else {
//             array[i] = nullptr; // Set nullptr for empty slots
//         }
//     }
// }

template <class T>
HashTable<T>::HashTable(const HashTable<T> &myHashTable) {
    // write code
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
    // Deallocate memory for each slot of the array
    for (int i = 0; i < slots; ++i) {
        if (array[i] != nullptr) {
            delete array[i];
        }
    }
    // Deallocate memory for the array itself
    delete[] array;
}

// Need to fix so that it iterates through the entire linked list at each slot
template <class T>
bool HashTable<T>::operator==(const HashTable<T>& other) const {

    // This is not correct but is still here fo rreference

    // Compare the number of slots
    if (slots != other.slots) {
        return false;
    }

    // Compare the elements in each slot
    for (int i = 0; i < slots; ++i) {
        // If one array is nullptr and the other is not, they are not equal
        if ((array[i] == nullptr && other.array[i] != nullptr) ||
            (array[i] != nullptr && other.array[i] == nullptr)) {
            return false;
        }
        // If both arrays are nullptr, they are considered equal for this slot
        if (array[i] == nullptr && other.array[i] == nullptr) {
            continue;
        }
        // Compare the elements pointed to by the pointers
        if (*array[i] != *other.array[i]) {
            return false;
        }
    }

    // If all comparisons passed, the hash tables are equal
    return true;
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
void HashTable<T>::insert(const T d, const T k)
{
    Element<T> e(d,k);
    if(!(member(d, k))) // should not insert duplicates
    {
        int position = k % slots;

        // Check if slot is empty (emptySlot function?)
            // If yes, head = e
            // Else, e->next = head->item, e->prev = NULL, head = e
    }
}

// /**
//  * @brief remove Class
//  *
//  * 
//  *
//  * @note Pre-Condition: 
//  * @note Post-Condition: 
//  * @returns 
//  */
// template <class T>
// void HashTable<T>::remove(const T k)
// {
//     /**
//     if((member(d, k))) // should only remove somethiing in the table
//     {
//         int position = k % slots;
//     }
//     */

// }              

/**
 * @brief member Class
 * 
 * 
 * 
 * @note Pre-Condition: 
 * @note Post-Condition: 
 * @returns none
 */
template <class T>
bool HashTable<T>::member(const T d, const T k) const{

    // Hash the key to find the correct slot
    // Initiate a pointer to the head of the linked list that is pointed to by the value in the hashed slot
    // traverse through the linked list to see if a given element has the same key and data as the given argument
    // Check if the list is empty


    // So how do we traverse the linked list?
    // My thought is that we initiate a new pointer to the head of the linked list
    // but HashTable has no attribute for pointers
}


/**
 * @brief to_string Class
 * 
 * 
 * 
 * @note Pre-Condition: 
 * @note Post-Condition: 
 * @returns 
 */
template <class T>
string HashTable<T>::to_string() const
{

}