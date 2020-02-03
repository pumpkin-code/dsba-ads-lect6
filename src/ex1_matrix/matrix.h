/*! \file matrix.h
 *  Contains declaration of the clas Matrix and corresponding types.
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstddef> // size_t
#include <iostream>


/*! ******************************************************************
 *  \brief The Matrix class represents a matrix of floating-point
 *  numbers.
 ********************************************************************/


class Matrix {
public:
    typedef std::vector<double> MatrixVector;
    typedef MatrixVector RowVector;
    typedef MatrixVector ColVector;
    typedef std::vector<RowVector> VectorOfRows;
    typedef std::pair<size_t, size_t> SizePair;



public:

    // When we do not define any constructorsin a class, then
    // the compiler creates the default one for us.
    // Since we add any other type of constructors, the default
    // constructor is not available anymore.
    Matrix() { }


    /// The initializing constuctor.
    Matrix(size_t m, size_t n, double def = 42);


    /// Resizes the current matrix up to m*n cells.
    /// \a def is a defualt value for each newly added cell.
    void resize(size_t m, size_t n, double def = 0);

    /// Overloaded version of the resize() method dispatching the packed size.
    /// We define the body of the method right here, which makes it inline.
    /*inline*/ void resize(const SizePair& sz, double def = 0)
    {
        /*this->*/resize(sz.first, sz.second, def);
    }


    /// Returns the size of the matrix object.
    SizePair getSize() const;
    //SizePair getSize();
    //SizePair getSize(Matrix const * const this);

    /// \returns an i-th row of the matrix
    RowVector& getRow(size_t i);

    /// \return the row in a const context
    const RowVector& getRow(size_t i) const;


    /// Creates an independant vector of size \a n and fills it in be \a def values.
    static MatrixVector createVector(size_t n, double def);

    /// \returns an individual i-tj, j-th element of the matrix.
    double getEl(size_t i, size_t j) const;

    /// sets the i-th, j-th element of a matrix to the given value \a val
    void setEl(size_t i, size_t j, double val);


    /// another approach for overloading the operator==
    /// the lhv operand is now passed by used the this pointer
    bool operator == (const Matrix& rhv) const;

    /// multiplies the matrix to a scalar
    Matrix& operator *= (double rhv) ;

    /// return a matrix which is formed by multiplication of the
    /// intital matrix to a scalar
    Matrix operator * (double rhv) const;

private:
    VectorOfRows _matrix;           ///< Internal storage.

}; // class Matrix


/// Declaration of the output operator for printing pairs.
std::ostream& operator<<(std::ostream& s, const Matrix::SizePair& pr);

/// output a matrix to the given stream \a s
std::ostream& operator<<(std::ostream& s, const Matrix& m);

/// output a single vector to the given stream \a s
std::ostream& operator<<(std::ostream& s, const Matrix::MatrixVector& v);

bool operator!=(const Matrix& lhv, const Matrix& rhv);





// The following is not possible when overload an operator:

//// / compares two matrices
//bool operator==(const Matrix& lhv, const Matrix& rhv);


//int operator + (int lhv, int rhv);

//Matrix m;
//== m;
//m ==;

//Matrix m1, m2;
//Matrix m3 = m1 ** m2;

//Matrix operator = (Matrix& lhv, Matrix& rhv);


#endif // MATRIX_H
