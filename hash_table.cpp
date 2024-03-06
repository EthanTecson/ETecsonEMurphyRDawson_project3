//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// hash_table.cpp
// Feb 2024
// This file contains the class template implementation for HashTable and Element
//=================================

#include "hash_table.h"
#include <sstream>

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
    head = NULL; // empty element should be null
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
    if (myElement.head == NULL)
    {
        head = NULL; // copying an empty element should result in an empty element
    }
    else
    {
        //creating a new instance of an element
        head = new Node;
        head->next = NULL;
        head->previous = NULL;

        // copy data and key from parameter element to new element
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
Element<T>::Element(const T &d, const int &k)
{
    // initialize a new element
    head = new Node;
    head->next = NULL;
    head->previous = NULL;

    // use parameters data and key for element attributes
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
    // check to see if element is null
    if (head)
    {
        return head->key; // return key value
    }
    return -1; // return -1 for an empty element
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
    // check to see if element is null
    if (head)
    {
        return head->data; // return data value
    }
    return -0; // return -0 for an empty element
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
    slots = numSlots;
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
template <class T>
HashTable<T>::HashTable(const HashTable<T> &myHashTable)
{
    slots = myHashTable.slots;
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
}

/**
 * @brief insert Class
 *
<<<<<<< HEAD
 *
 *
 * @note Pre-Condition:
 * @note Post-Condition:
=======
 * Inserts an element with data d and key k into the hash table
 *
 * @note Pre-Condition: d is of the same data type as the rest of the hash table
 * @note Post-Condition: none
>>>>>>> 05bb0dc53623960e6a32bcccabf7311b61655e5f
 * @returns none
 */
template <class T>
void HashTable<T>::insert(const T d, const T k)
{
    if (!(member(d, k))) // should only insert something not in the table
    {
        int position = hash(k);
        % slots; // placeholder for the hash function

        Node<T> *insertedNode = new Node<T>(d, k); // create a new node
        insertedNode->next = slots[position];      // set the next value of insertedNode to the current value of slots[position]
        insertedNode->previous = nullptr           // set the previous value of  insertedNode to null

            if (slots[position] != nullptr)
        {                                             // if the current value of slots[position] is not null
            slots[position]->previous = insertedNode; // set the previous value of slots[position] to insertedNode
        }
        slots[position] = insertedNode; // set the current value of slots[position] to insertedNode
    }
}

/**
 * @brief remove Class
 *
<<<<<<< HEAD
 *
 *
 * @note Pre-Condition:
 * @note Post-Condition:
 * @returns
=======
 * Deletes the element with key k from the hash table
 *
 * @note Pre-Condition: none
 * @note Post-Condition: Element with key k is not in the hash table
 * @returns none
>>>>>>> 05bb0dc53623960e6a32bcccabf7311b61655e5f
 */
template <class T>
void HashTable<T>::remove(const T k)
{
    if ((member(d, k))) // should only remove somethiing in the table
    {
        int position = hash(k); // placeholder for the hash function
    }
}

/**
 * @brief member Class
<<<<<<< HEAD
 *
 *
 *
 * @note Pre-Condition:
 * @note Post-Condition:
 * @returns none
=======
 * 
 * Checks to see if an element with data d and key k is in the hash table
 * 
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns True if element with data d and key k is in the hash table, false otherwise
>>>>>>> 05bb0dc53623960e6a32bcccabf7311b61655e5f
 */
template <class T>
bool HashTable<T>::member(const T d, const T k) const
{
}

/**
 * @brief to_string Class
<<<<<<< HEAD
 *
 *
 *
 * @note Pre-Condition:
 * @note Post-Condition:
 * @returns
=======
 * 
 * Creates a string representation of the hash table and returns it
 * 
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns string containing the hash table
>>>>>>> 05bb0dc53623960e6a32bcccabf7311b61655e5f
 */
template <class T>
string HashTable<T>::to_string() const
{
    std::ostringstream oss; // create an output string stream
    if (slots == 0)         // if the number of slots is 0
    {
        oss << "The Hash Table is empty"; // print that the hash table is empty
    }
    else
    {
        oss << " Hash Table with " << slots << "slots"; // print the number of slots
    }
    return oss.str(); // return the string
}