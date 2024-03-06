//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// hash_table.cpp
// Feb 2024
// This file contains the class template implementation for HashTable and Element
//=================================

#include "hash_table.h"
#include <sstream>
#include <list>

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
    // slots = numSlots; 
    // array = new list<T>*[slots];
    // for (int i = 0; i < slots; ++i){
    //     array[i] = new list<T>();
    // }
    slots = numSlots; 
    array = new list<T>[slots]; 
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
// template <class T>
// HashTable<T>::HashTable(const HashTable<T> &myHashTable) {
//     slots = myHashTable.slots;
//     array = new list<T>[slots];

//     // Loop through each slot in the original hash table
//     for (int i = 0; i < slots; ++i) {
//         // Check if the original slot is not empty
//         if (!myHashTable.array[i].empty()) {
//             // Create iterators for the beginning and end of the original slot's linked list
//             auto it = myHashTable.array[i].begin();
//             auto end = myHashTable.array[i].end();
            
//             // Loop through the elements in the original slot's linked list using iterators
//             while (it != end) {
//                 // Add a copy of the element to the new slot's linked list
//                 array[i].push_back(*it);
//                 ++it; // Move to the next element
//             }
//         }
//     }
// }


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
HashTable<T>::~HashTable(void) {
    delete[] array; // Deallocate memory for the array
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

    // Check if inserted item is a member (member method not made yet)
    Element<T> e(d,k);
    int position = k % slots;
    array[position].push_front(e);
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
void HashTable<T>::remove(const T k)
{
    // Code goes here
}              

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
bool HashTable<T>::member(const T d, const T k) const
{
    // Code goes here
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
// template <class T>
// string HashTable<T>::to_string() const
// {
//     stringstream stream;
//     int slots_counter = 0;
//     for (int i = 0; i < slots; ++i){
//         auto it = array[i].begin();
//         auto end = array[i].end();

//         while (it != end())
//         {
//             stream << *it.get_data();
//             stream << " ";
//         }
//     }
//     return stream.str();
// }

// template <class T>
// string Set<T>::to_string(void) const
// // Preconditions: A valid Set object must exist.
// // Postconditions: Returns a string represention of the set, including all of the elements in original order.
// {
//     stringstream stream;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         // iterates through each node and adds its' item to the stream
//         if (temp->next == NULL)
//         {
//             // final element does not have a trailing space
//             stream << temp->item;
//         }
//         else
//         {
//             stream << temp->item << " ";
//         }
//         temp = temp->next;
//     }
//     return stream.str();
// }