/**
 * @file main.cpp
 * @brief Main file for testing the IntMatrix class.
 */

#include <iostream>
#include "IntMatrix.h"
using namespace std;

int main() 
{
    // Create two matrices with initial values.
    IntMatrix matrixA = 
    {
        {4, 1, 2},
        {1, 5, 4},
        {2, 3, 3}
    };

    IntMatrix matrixB = 
    {
        {3, 3, 1},
        {1, 2, 2},
        {4, 2, 3}
    };

    // Testing addition.
    cout << "Addition:" << endl;
    cout << matrixA + matrixB << endl;

    // Testing subtraction.
    cout << "Subtraction:" << endl;
    cout << matrixA - matrixB << endl;

    // Testing multiplication.
    cout << "Multiplication:" << endl;
    cout << matrixA * matrixB << endl;

    return 0;
}
