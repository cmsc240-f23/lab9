/**
 * @file IntVectorApp.cpp
 * @brief Application to demonstrate the functionality of IntVector class.
 */

#include <iostream>
#include "IntVector.h"
using namespace std;

int main() 
{
    IntVector vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (size_t i = 0; i < vec.size(); i++) 
    {
        cout << "Element at index " << i << ": " << vec[i] << endl;
    }

    vec.pop_back();

    cout << "After pop_back:" << endl;
    for (size_t i = 0; i < vec.size(); i++) 
    {
        cout << "Element at index " << i << ": " << vec[i] << endl;
    }

    IntVector vec2{vec};
    cout << "After copy:" << endl;
    for (size_t i = 0; i < vec2.size(); i++) 
    {
        cout << "Element at index " << i << ": " << vec2[i] << endl;
    }

    return 0;
}
