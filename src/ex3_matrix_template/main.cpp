/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.2
 *  \date       30.01.2020
 *
 *  →
 */

#include <iostream>
#include <string>

#include "matrix.hpp"


int main()
{
    Matrix<int> m1;
    Matrix<int> m2(3, 4, 42);

    Matrix<std::string> m3(4, 5, "Abc");

    Matrix<int>::MatrixVector vec = Matrix<int>::createVector(10, 42);


    return 0;
}
