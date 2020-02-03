/*! \file       ex_1.cpp
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       14.03.2019
 *
 *  Generic swap function
 */

#include <iostream>


//void mySwap(int& x, int& y)
//{
//    int temp;
//    temp = x;
//    x = y;
//    y = temp;
//}

//void mySwap(double& x, double& y)
//{
//    int temp;
//    temp = x;
//    x = y;
//    y = temp;
//}

template<typename T>
void mySwap(T& x, T& y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
}

template<typename T, size_t n>
void mySwap(T(& x)[n], T(& y)[n])
{
    for(size_t i = 0; i < n; ++i)
        mySwap(x[i], y[i]);
}



template<typename T1, typename T2>
void mySwap(T1& x, T2& y)
{
    T1 temp;
    temp = x;
    x = y;      // implicit conversion if it's possible
    y = temp;
}



int main()
{
    int a = 10, b = 15;
    mySwap(a, b);
    mySwap<int>(a, b);

    double d1 = 3.14, d2 = 2.4;
    mySwap(d1, d2);

    mySwap(a, b);
    mySwap<double, int>(d1, a);     // some special case

    int ar1[] = { 1, 2, 3 };
    int ar2[] = { 10, 20, 30 };
    mySwap(ar1, ar2);


    return 0;
}
