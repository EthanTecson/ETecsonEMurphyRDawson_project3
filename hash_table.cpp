//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// hash_table.cpp
// Feb 2024
// This file contains the class template implementation for HashTable and Element
//=================================

#include "hash_table.h"
#include <sstream>
#include <list>

using namespace std;

//==================================
// Element Class
//==================================

/**
 * @brief Constructor Class
 *
 * Creates an Element Object with no values for key or data
 * 
 * @param none
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
 * @param const Element<T> &myElement - element to be copied
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
 * @param const T &d data and const int &k key
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
 * @param none
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
 * @param none
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
 * @param none
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
 * @param int numSlots - number of slots for the hash table
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
 * @param const HashTable<T> &myHashTable - hash table to be copied
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
 * @param none
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
 * Inserts an element with data d and key k into the hash table
 *
 * @param const T d data and const int k key of element to be inserted
 * @note Pre-Condition: d is of the same data type as the rest of the hash table
 * @note Post-Condition: none
 * @returns none
 */
template <class T>
void HashTable<T>::insert(const T d, const int k)
{
    /**
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
    */
    Element<T> elem(d, k);
    position = k % slots;
    if (!(member(d,k)))
    {
        //access array at position
            //list_name.push_front(elem);
    }
    

}

/**
 * @brief remove Class
 *
 * Deletes the element with key k from the hash table
 *
 * @param const T k key of element to be removed
 * @note Pre-Condition: none
 * @note Post-Condition: Element with key k is not in the hash table
 * @returns none
 */
template <class T>
void HashTable<T>::remove(const T k)
{
    if ((member(d, k))) // should only remove somethiing in the table
    {
        int position = k % slots; // placeholder for the hash function
    }
}

/**
 * @brief member Class
 * 
 * Checks to see if an element with data d and key k is in the hash table
 * 
 * @param const T d data and const int k of element to be searched for
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns True if element with data d and key k is in the hash table, false otherwise
 */
template <class T>
bool HashTable<T>::member(const T d, const int k) const
{
    position = k % slots;
    //access array at position
        // iterate through array checking if .get_key == k
            // if .get_data == d
                //return true
            // return false because keys are distinct
        //return false

}

/**
 * @brief to_string Class
 * 
 * Creates a string representation of the hash table and returns it
 * 
 * @param none
 * @note Pre-Condition: none
 * @note Post-Condition: none
 * @returns string containing the hash table
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


    // for int i = 0; i < slots; i ++
    //      str << i << ":" << linked list elements formatted as (data, key)
    //      str << "/n"
}