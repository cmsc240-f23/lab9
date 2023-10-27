/**
 * @file IntVector.cpp
 * @brief Implementation file for the IntVector class.
 */

#include <stdexcept>
#include "IntVector.h"

/**
 * @brief Default constructor. Initializes an empty IntVector.
 */
IntVector::IntVector()
    : array(nullptr), currentSize(0), currentCapacity(0) 
{

}

/**
 * @brief Destructor. Frees the allocated memory.
 */
IntVector::~IntVector() 
{
    delete[] array;
}

/**
 * @brief Copy constructor.
 * @param other The IntVector object to copy from.
 */
IntVector::IntVector(const IntVector& other)
    : currentSize(other.currentSize), currentCapacity(other.currentCapacity) 
{
    array = new int[currentCapacity];
    for (size_t i = 0; i < currentSize; i++) 
    {
        array[i] = other.array[i];
    }
}

/**
 * @brief Resizes the internal array.
 * @param newCapacity The new capacity of the vector.
 */
void IntVector::resize(size_t newCapacity) 
{
    int* newArray = new int[newCapacity];

    size_t elementsToCopy = currentSize < newCapacity ? currentSize : newCapacity;
    
    // Copy the elements from the smaller array into the new larger array.
    for (size_t i = 0; i < elementsToCopy; i++) 
    {
        newArray[i] = array[i];
    }
    
    // Free the original memory allocated on the heap. 
    delete[] array;

    // Put the new array in place.
    array = newArray;
    
    // Update the capacity.
    currentCapacity = newCapacity;
}

/**
 * @brief Adds a new element at the end of the vector.
 * @param value The value to be added.
 */
void IntVector::push_back(int value) 
{
    // Before adding a new element, check to see if the vector has the capacity to hold the new element.
    // If the size of the vector is equal to the capacity of what 
    // the vector can hold, increase the size. 
    if (currentSize == currentCapacity) 
    {
        // If the current capacity is 0, then start by resizing the vector capacity to 1.
        if (currentCapacity == 0)
        {
            resize(1);
        }
        else 
        {
            // Otherwise, double the current capacity. 
            resize(currentCapacity * 2);
        }
    }

    // Add the new value. 
    array[currentSize++] = value;
}

/**
 * @brief Removes the last element from the vector.
 */
void IntVector::pop_back() 
{
    if (currentSize == 0) 
    {
        throw std::out_of_range("Cannot pop from an empty vector.");
    }

    currentSize--;

    // Check if the size is less than half the capacity.
    if (currentSize < currentCapacity / 2) 
    {
        // Halve the currentCapacity but ensure it's not zero.
        if (currentCapacity / 2 > 0)
        {
            resize(currentCapacity / 2);
        }
        else
        {
            resize(1);
        }
    }
}

/**
 * @brief Accesses the element at the specified position.
 * @param index The index of the element.
 * @return Reference to the element at the specified index.
 */
int IntVector::at(size_t index) 
{
    if (index >= currentSize) 
    {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

/**
 * @brief Accesses the element at the specified position.
 * @param index The index of the element.
 * @return Reference to the element at the specified index.
 */
int IntVector::operator[](size_t index) 
{
    return array[index];
}

/**
 * @brief Clears the vector, removing all elements.
 */
void IntVector::clear() 
{
    currentSize = 0;
}

/**
 * @brief Returns the current size of the vector.
 * @return The size of the vector.
 */
size_t IntVector::size() const 
{
    return currentSize;
}

/**
 * @brief Returns the current capacity of the vector.
 * @return The capacity of the vector.
 */
size_t IntVector::capacity() const
{
    return currentCapacity;
}

/**
 * @brief Checks if the vector is empty.
 * @return True if the vector is empty, false otherwise.
 */
bool IntVector::empty() const 
{
    return currentSize == 0;
}
