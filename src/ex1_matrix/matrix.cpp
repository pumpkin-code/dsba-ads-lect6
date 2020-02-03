// Implementation module for the Matrix class.
#include "matrix.h"


//------------------------------------------------------------------------------

Matrix::Matrix(size_t m, size_t n, double def)
{
    resize(m, n, def);
}

//------------------------------------------------------------------------------

void Matrix::resize(size_t m, size_t n, double def)
{
    if(m == 0 || n == 0)
        _matrix.clear();

    if(_matrix.size() != m)
    {
        size_t prevSize = _matrix.size();

        MatrixVector defVector = createVector(n, def);
        _matrix.resize(m, defVector);

    } // number of rows is changed

    if(_matrix[0].size() != n)
    {
        for(RowVector& row : _matrix)       // ref here is a must!
            row.resize(n, def);
    }
}


//------------------------------------------------------------------------------


Matrix::SizePair Matrix::getSize() const
{
    //const MatrixVector anotherMaV;
    //anotherMaV = this->_matrix;

    //this->_matrix             = Matrix();
    // LHV - left hand value    //RHV right hand value

    //_matrix.resize()
    //if( _matrix.size() != 0 )

    if( !/*this->*/_matrix.size())
        return {0, 0}; // return std::make_pair(0, 0,);

    return {_matrix.size(), _matrix[0].size() };
}

//------------------------------------------------------------------------------

Matrix::RowVector& Matrix::getRow(size_t i)
{
    if(i >= _matrix.size())
        throw std::out_of_range("There no such a row.");

    return _matrix[i];
}

//------------------------------------------------------------------------------

const Matrix::RowVector&  Matrix::getRow(size_t i) const
{
    if(i >= _matrix.size())
        throw std::out_of_range("There no such a row.");

    return this->_matrix[i];
}

//------------------------------------------------------------------------------

//static
Matrix::MatrixVector Matrix::createVector(size_t n, double def)
{
    //this->
    // std::vector<double>
    MatrixVector v(n, def);
    return v;
}

//------------------------------------------------------------------------------

double Matrix::getEl(size_t i, size_t j) const
{
    const RowVector& row = getRow(i);

    return row.at(j);
}

//------------------------------------------------------------------------------

void Matrix::setEl(size_t i, size_t j, double val)
{
    RowVector& row = getRow(i);
    row.at(j) = val;
}



//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& s, const Matrix::SizePair& ssPair)
{
    s << "(" << ssPair.first << ", " << ssPair.second << ")";
    return s;
}

//------------------------------------------------------------------------------



std::ostream& operator<<(std::ostream& s, const Matrix& m)
{
    Matrix::SizePair mSize = m.getSize(); //

    for(int i = 0; i < mSize.first; ++i)
    {
        s << m.getRow(i) << '\n';
        // TODO: create anather operator<< overloading
        // in order to output a single row
    }

    return s;
}

//------------------------------------------------------------------------------

std::ostream&operator<< (std::ostream& s, const Matrix::MatrixVector& vect)
{
    for(double val : vect)
    {
        s << val << '\t';
    }
    // not to put the line break here in order to make it a bit more flexible

    return s;
}

//------------------------------------------------------------------------------

//bool operator==(const Matrix& lhv, const Matrix& rhv)
//{
//    Matrix::SizePair sz = lhv.getSize();

//    if(sz != rhv.getSize())
//        return false;

//    for(int i = 0; i < sz.first; ++i)
//        for(int j = 0; j < sz.second; ++j)
//            if(lhv.getEl(i, j) != rhv.getEl(i, j))
//                return false;   //0;


//    return true;
//    //return false;   // DONE:
//}

//------------------------------------------------------------------------------

bool Matrix::operator==(const Matrix& rhv) const
{
    const Matrix& lhv = *this;        // * means dereferencing

    Matrix::SizePair sz = lhv.getSize();
    //Matrix::SizePair sz = /*lhv.*/this->getSize();

    if(sz != rhv.getSize())
        return false;

    for(int i = 0; i < sz.first; ++i)
        for(int j = 0; j < sz.second; ++j)
            if(lhv.getEl(i, j) != rhv.getEl(i, j))
                return false;   //0;

    return true;
}

//------------------------------------------------------------------------------

Matrix& Matrix::operator *=(double rhv)
{
    //Matrix::SizePair sz = this->getSize();
    //Matrix::SizePair sz = (*this).getSize();
    Matrix::SizePair sz =   getSize();
            // (*this).

    for(int i = 0; i < sz.first; ++i)
        for(int j = 0; j < sz.second; ++j)
            setEl(i, j,
                  getEl(i, j) * rhv
                  );

    return *this;
}

//------------------------------------------------------------------------------

Matrix Matrix::operator*(double rhv) const
{
    Matrix newMatrix = (*this); // we cannot omit using the this here!

    //return
    newMatrix *= rhv;

    return newMatrix;
}


//------------------------------------------------------------------------------

bool operator!=(const Matrix& lhv, const Matrix& rhv)
{
    return !(lhv == rhv);
}
