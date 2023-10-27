/**
 * @file IntMatrix.cpp
 * @brief Implementation file for the IntMatrix class.
 * 
 * This file contains the definitions of the functions declared in IntMatrix.h.
 * It provides functionality for basic matrix operations including addition,
 * subtraction, and multiplication, as well as utility functions for matrix
 * manipulation.
 */

#include <stdexcept>
#include "IntMatrix.h"

/**
 * Constructor for the IntMatrix class.
 * 
 * It initializes a matrix of given dimensions with an optional initial value.
 * 
 * @param rows The number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 * @param initialValue (optional) The initial value to fill the matrix. Defaults to 0.
 */
IntMatrix::IntMatrix(size_t rows, size_t cols, int initialValue) 
{
    // Resizes the outer vector to the number of rows and each inner vector (row) to the number of columns.
    // Fills the matrix with the initial value provided.
    data.resize(rows, std::vector<int>(cols, initialValue));
}

/**
 * @brief Construct a new Int Matrix object using an initializer list.
 * 
 * This constructor allows initializing the matrix with a list of values for each row.
 * Example usage: IntMatrix matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
 * 
 * @param values An initializer list of initializer lists representing the matrix.
 */
IntMatrix::IntMatrix(std::initializer_list<std::initializer_list<int>> values) 
{
    for (const std::initializer_list<int>& row : values) 
    {
        data.push_back(std::vector<int>(row));
    }
}

/**
 * Retrieves the number of rows in the matrix.
 * 
 * @return The number of rows as a size_type.
 */
size_t IntMatrix::getRows() const 
{
    return data.size(); // Returns the size of the outer vector which represents the number of rows.
}

/**
 * Retrieves the number of columns in the matrix.
 * 
 * @return The number of columns as a size_type.
 */
size_t IntMatrix::getCols() const 
{
    return data[0].size(); // Returns the size of the first inner vector which represents the number of columns.
}

/**
 * Overloads the '+' operator to add two matrices.
 * 
 * @param other The matrix to be added to the current matrix.
 * @return A new IntMatrix instance representing the result of the addition.
 * @throws std::invalid_argument if the dimensions of the matrices do not match.
 */
IntMatrix IntMatrix::operator+(const IntMatrix& other) const 
{
    if (getRows() != other.getRows() || getCols() != other.getCols()) 
    {
        throw std::invalid_argument("Matrices dimensions do not match for addition.");
    }

    // Creates a new matrix to store the result of the addition.
    IntMatrix result(getRows(), getCols());

    // Iterates through each element of the matrices and adds them.
    for (size_t i = 0; i < getRows(); i++) 
    {
        for (size_t j = 0; j < getCols(); j++) 
        {
            result[i][j] = data[i][j] + other[i][j];
        }
    }

    return result;
}

/**
 * Overloads the '-' operator to subtract one matrix from another.
 * 
 * @param other The matrix to be subtracted from the current matrix.
 * @return A new IntMatrix instance representing the result of the subtraction.
 * @throws std::invalid_argument if the dimensions of the matrices do not match.
 */
IntMatrix IntMatrix::operator-(const IntMatrix& other) const 
{
    if (getRows() != other.getRows() || getCols() != other.getCols()) 
    {
        throw std::invalid_argument("Matrices dimensions do not match for subtraction.");
    }

    // Creates a new matrix to store the result of the subtraction.
    IntMatrix result(getRows(), getCols());

    // Iterates through each element of the matrices and subtracts them.
    for (size_t i = 0; i < getRows(); i++) 
    {
        for (size_t j = 0; j < getCols(); j++) 
        {
            result[i][j] = data[i][j] - other[i][j];
        }
    }

    return result;
}

/**
 * Overloads the '*' operator to multiply two matrices.
 * 
 * @param other The matrix to be multiplied with the current matrix.
 * @return A new IntMatrix instance representing the result of the multiplication.
 * @throws std::invalid_argument if the number of columns of the first matrix does not match the number of rows of the second matrix.
 */
IntMatrix IntMatrix::operator*(const IntMatrix& other) const 
{
    if (getCols() != other.getRows()) 
    {
        throw std::invalid_argument("Matrices dimensions do not match for multiplication.");
    }

    // Creates a new matrix to store the result of the multiplication.
    IntMatrix result(getRows(), other.getCols());

    // Performs matrix multiplication.
    for (size_t i = 0; i < getRows(); i++) 
    {
        for (size_t j = 0; j < other.getCols(); j++) 
        {
            for (size_t k = 0; k < getCols(); k++) 
            {
                result[i][j] += data[i][k] * other[k][j];
            }
        }
    }

    return result;
}

/**
 * Overloads the '[]' operator for non-const objects to allow access and modification of matrix elements.
 * 
 * @param index The row index to access.
 * @return A reference to the row vector at the given index.
 */
std::vector<int>& IntMatrix::operator[](size_t index) 
{
    return data[index]; // Returns a reference to the row vector, allowing modification.
}

/**
 * Overloads the '[]' operator for const objects to allow read-only access to matrix elements.
 * 
 * @param index The row index to access.
 * @return A const reference to the row vector at the given index.
 */
const std::vector<int>& IntMatrix::operator[](size_t index) const 
{
    return data[index]; // Returns a const reference to the row vector, preventing modification.
}

/**
 * Overloads the '<<' operator to output the matrix to an output stream.
 * 
 * @param os The output stream.
 * @param matrix The matrix to be output.
 * @return The modified output stream.
 */
std::ostream& operator<<(std::ostream& os, const IntMatrix& matrix) 
{
    // Iterates through each row and element to output the matrix.
    for (const std::vector<int>& row : matrix.data) 
    {   
        for (const int& elem : row) 
        {
            os << elem << ' ';
        }

        os << std::endl;
    }
    return os;
}
