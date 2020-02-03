/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.2
 *  \date       28.01.2020
 *
 *  Matrix class definition. Version 1.
 */

#include <iostream>

#include "matrix.h"

// Creates a simple matrix.
void test1()
{

    Matrix m;
    Matrix::SizePair mSize = m.getSize();

    std::cout << "Matrix's size: " << mSize << '\n';

    m.resize(3, 4);
    std::cout << "New matrix's size: " << m.getSize() << '\n';

    std::cout << m << '\n';

    m.resize(4, 5, 1);
    std::cout << "New matrix's size (2): " << m.getSize() << '\n';

    std::cout << m << "\n\n";     // TODO: want to print the matrix


    // creates a vector by using the factory method Matrix::createVector()
    Matrix::MatrixVector simpleVector =
            Matrix::createVector(10, 2);




    // how to get a row of a matrix:
    Matrix::MatrixVector& m0Row0 = m.getRow(0);  //
    m0Row0[0] = 42;
    std::cout << "The matrix m after changing an el:\n" << m << "\n\n";     // TODO: want to print the matrix

    const Matrix m2 = m;
    //std::cout << "The size of the matrix m2: " << m2.getSize() << '\n';
    //std::cout << "\nThe m2 matrix is:\n" << m2;

    const Matrix::MatrixVector& m2Row0 = m2.getRow(0);
    //m2Row0[0] = 42;       // not possible to assign to a const object


    int a = 0;
}


// tests the operator==
void test2()
{
    Matrix m1(3, 4);
    Matrix m2(3, 4, 42);

    bool l1 = (m1 == m2);
    bool l2 = (m1 != m2);

    int a = 0;
}


// tests the multiplications
void test3()
{
    Matrix m(3, 4, 1);
    std::cout << m << '\n';


    m *= 2;
    std::cout << m  << '\n';

    std::cout << (m *= 3)  << '\n' << m << '\n';

    // test operator+
    Matrix m1 = m * 2;
    std::cout << m1 << '\n';

    std::cout << m1 * 3 << '\n';
}



int main()
{
    std::cout << "Let's do some matrices!\n";

    test1();
    test2();
    test3();

    std::cout << "\n\nBye-bye!\n\n";
    return 0;
}

