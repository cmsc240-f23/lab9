/**
 * @file IntVector.h
 * @brief Header file for the IntVector class.
 */

#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <cstddef>

/**
 * @class IntVector
 * @brief Custom implementation of a dynamic array (vector) for integers.
 */
class IntVector 
{
public:
    // Constructor.
    IntVector();
    // Destructor.
    ~IntVector();
    // Copy Constructor.
    IntVector(const IntVector& other);

    void push_back(int value);
    void pop_back();
    int at(size_t index);
    int operator[](size_t index);
    void clear();
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
private:
    // Pointer to the array of integers.
    int* array;

    // Current size of the vector.               
    size_t currentSize;

    // Current capacity of the vector.       
    size_t currentCapacity;   

    void resize(size_t newCapacity);
};

#endif // INTVECTOR_H
