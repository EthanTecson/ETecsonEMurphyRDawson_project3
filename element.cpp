//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// element.cpp
// Feb 2024
// This file contains the class template implementation for Element
//=================================

#include "element.h"

/**
 * @brief Constructor Class
 *
 * creates an element with no values for key or data
 *
 * @note Pre-Condition: None
 * @note Post-Condition: Creates an Element object
 * @returns none
 */
template <class T>
Element<T>::Element()
{
    // An element initialized with nothing should just be nothing
    data = NULL;
    key = -1;
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
    data = myElement.data;
    key = myElement.key;
}
