#ifndef MATRIX_H
#define MATRIX_H


#include <vector>
#include <cstddef>      // size_t
#include <iostream>


template<typename ElType>
class Matrix {
public:
    typedef std::vector<ElType> MatrixVector;   ///< Common type for rows and columns.
    typedef MatrixVector RowVector;             ///< Alias for row type.
    typedef std::vector<RowVector> VectorOfRows;///< Matrix as vector of vectors.

private:
    //---- <Fields of the class.> ----
    VectorOfRows _matrix;                       ///< Represents a matrix as vector of vectors.


public:


    Matrix()
    {
    }

    /// Initializing constructor.
    Matrix(size_t m, size_t n, ElType def = 0)
    {
        resize(m, n, def);
    }


    static MatrixVector createVector(size_t sz, ElType val)
    {
        MatrixVector v(sz, val);
        return v;
    }

    /// Resizes the current matrix up to m*n cells.
    /// \a def is a defualt value for each newly added cell.
    void resize(size_t m, size_t n,
                 ElType def = 0)
    {
        // If either m or n is equal to 0, them the matrix is void.
        if(m == 0 || n == 0)
            _matrix.clear();

        // checks rows
        if(_matrix.size() != m)
        {
            // store the previous size
            size_t prevSize = _matrix.size();

            MatrixVector zeroVector = createVector(n, def/*0*/);
            _matrix.resize(m, zeroVector);
        }
    }

    /// \returns an i-th row of the matrix
    RowVector& getRow(size_t i);

    /// \return the row in a const context
    const RowVector& getRow(size_t i) const;

};


// We can take some definitions out from the class, but this is cumbersome.

template<typename ElType>
typename Matrix<ElType>::RowVector& Matrix<ElType>::getRow(size_t i)
{
    if(i >= _matrix.size())
        throw std::out_of_range("There no such a row.");

    return _matrix[i];
}

//------------------------------------------------------------------------------

template<typename ElType>
const typename Matrix<ElType>::RowVector&  Matrix<ElType>::getRow(size_t i) const
{
    if(i >= _matrix.size())
        throw std::out_of_range("There no such a row.");

    return this->_matrix[i];
}


#endif // MATRIX_H
