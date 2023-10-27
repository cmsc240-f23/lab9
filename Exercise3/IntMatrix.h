/**
 * @file IntMatrix.h
 * @brief Header file for the IntMatrix class.
 * 
 * The IntMatrix class provides basic matrix operations for integer matrices.
 */

#ifndef INTMATRIX_H
#define INTMATRIX_H

#include <iostream>
#include <vector>


class IntMatrix 
{
public:
    /**
     * Constructor to create a matrix of given dimensions initialized with a specified value.
     * 
     * @param rows Number of rows in the matrix.
     * @param cols Number of columns in the matrix.
     * @param initialValue The initial value to fill the matrix with.
     */
    IntMatrix(std::vector<int>::size_type rows, std::vector<int>::size_type cols, int initialValue = 0);

    /**
     * @brief Construct a new Int Matrix object using an initializer list.
     * 
     * This constructor allows initializing the matrix with a list of values for each row.
     * Example usage: IntMatrix matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
     * 
     * @param values An initializer list of initializer lists representing the matrix.
     */
    IntMatrix(std::initializer_list<std::initializer_list<int>> values);

    /**
     * Getter for the number of rows in the matrix.
     * 
     * @return Number of rows.
     */
    std::vector<int>::size_type getRows() const;

    /**
     * Getter for the number of columns in the matrix.
     * 
     * @return Number of columns.
     */
    std::vector<int>::size_type getCols() const;

    /**
     * Operator overloading for matrix addition.
     * 
     * @param other The matrix to add.
     * @return The resulting matrix after addition.
     */
    IntMatrix operator+(const IntMatrix& other) const;

    /**
     * Operator overloading for matrix subtraction.
     * 
     * @param other The matrix to subtract.
     * @return The resulting matrix after subtraction.
     */
    IntMatrix operator-(const IntMatrix& other) const;

    /**
     * Operator overloading for matrix multiplication.
     * 
     * @param other The matrix to multiply with.
     * @return The resulting matrix after multiplication.
     */
    IntMatrix operator*(const IntMatrix& other) const;

    /**
     * Operator overloading for accessing matrix elements.
     * Non-const version for writing to the matrix.
     * 
     * @param index Row index.
     * @return Reference to the row vector.
     */
    std::vector<int>& operator[](std::vector<int>::size_type index);

    /**
     * Operator overloading for accessing matrix elements.
     * Const version for reading from the matrix.
     * 
     * @param index Row index.
     * @return Const reference to the row vector.
     */
    const std::vector<int>& operator[](std::vector<int>::size_type index) const;

    /**
     * Overloading the insertion operator for outputting the matrix.
     * 
     * @param os Output stream.
     * @param matrix Matrix to output.
     * @return Modified output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const IntMatrix& matrix);

private:
    // 2D vector representing the matrix data
    std::vector<std::vector<int>> data; 
};

#endif // INTMATRIX_H
