#include "matrix.h"
#include <iostream>
#include <cstring>
using namespace std;

/*
 * Constructors
 */

Matrix::Matrix() : _rows(0), _cols(0), data(nullptr)
{
    // Default constructors for 1x1 Matrix
    /*
        Empty matrix does not allocate in the memory
    */
}

Matrix::~Matrix()
{
    // Destructor
    delete[] data;
}

Matrix::Matrix(int r, int c) : _rows(r), _cols(c)
{
    // Default constructors with rows and cols
    data = new float[_rows * _cols];
    memset(data, 0, _rows * _cols * sizeof(float)); // Inicializa tudo com 0
}

Matrix::Matrix(int r, int c, const float *values) : _rows(r), _cols(c)
{
    // Constructor with size and 1D array of values
    data = new float[_rows * _cols];
    memset(data, 0, _rows * _cols * sizeof(float));
    memcpy(data, values, _rows * _cols * sizeof(float));
}

Matrix::Matrix(const Matrix &other) : _rows(other._rows), _cols(other._cols)
{
    // Constructor of copy
    data = new float[_rows * _cols];
    memcpy(data, other.data, _rows * _cols * sizeof(float));
}
Matrix &Matrix::operator=(const Matrix &otherMatrix)
{
    // Copy assignment operator
    if (this == &otherMatrix)
    {
        return *this;
    }
    delete[] data;

    _rows = otherMatrix._rows;
    _cols = otherMatrix._cols;

    data = new float[_rows * _cols];
    memcpy(data, otherMatrix.data, _rows * _cols * sizeof(float));
    return *this;
}

Matrix::Matrix(Matrix &&otherMatrix) : _rows(otherMatrix._rows), _cols(otherMatrix._cols), data(otherMatrix.data)
{
    // Constructor of move
    otherMatrix._rows = 0;
    otherMatrix._cols = 0;
    otherMatrix.data = nullptr;
    std::cout << "Move constructor called" << std::endl;
}

Matrix &Matrix::operator=(Matrix &&otherMatrix)
{
    // Move assignment operator
    if (this != &otherMatrix)
    {
        delete[] data;
        _rows = otherMatrix._rows;
        _cols = otherMatrix._cols;
        data = otherMatrix.data;

        otherMatrix._rows = 0;
        otherMatrix._cols = 0;
        otherMatrix.data = nullptr;
    }
    std::cout << "Move assignment operator called" << std::endl;
    return *this;
}

Matrix Matrix::operator+(const Matrix &m2) const
{
    if (this->getRows() != m2.getRows() || this->getCols() != m2.getCols())
    {
        throw "Wrong size matrix";
    }

    Matrix answer(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows() * this->getCols(); i++)
    {
        answer.getData()[i] = this->getData()[i] + m2.getData()[i];
    }
    return answer;
}

Matrix Matrix::operator*(const Matrix &m2) const
{
    if (this->getCols() != m2.getRows())
    {
        throw "Wrong size matrix. m1 Cols must be equal to m2 Rows";
    }

    Matrix answer(this->getRows(), m2.getCols());
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < m2.getCols(); j++)
        {
            for (int k = 0; k < this->getCols(); k++)
            {
                answer.getData()[i * m2.getCols() + j] += this->getData()[i * this->getCols() + k] * m2.getData()[k * m2.getCols() + j];
            }
        }
    }
    return answer;
}

Matrix Matrix::operator-(const Matrix &m2) const
{
    if (this->getRows() != m2.getRows() || this->getCols() != m2.getCols())
    {
        throw "The matrix does not have the correct size";
    }

    Matrix answer(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows() * this->getCols(); i++)
    {
        answer.getData()[i] = this->getData()[i] - m2.getData()[i];
    }
    return answer;
}

Matrix Matrix::operator-() const
{
    Matrix result(_rows, _cols);
    for (int i = 0; i < _rows * _cols; ++i)
    {
        result.data[i] = -data[i];
    }
    return result;
}

// Utils functions
int Matrix::getRows() const
{
    return _rows;
}

int Matrix::getCols() const
{
    return _cols;
}

void Matrix::displayMatrix() const
{
    for (int i = 0; i < _rows; ++i)
    {
        for (int j = 0; j < _cols; ++j)
        {
            std::cout << data[i * _cols + j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::display() const
{
    std::cout << "[";
    for (int i = 0; i < _rows; ++i)
    {
        std::cout << "[";
        for (int j = 0; j < _cols; ++j)
        {
            std::cout << data[i * _cols + j];
            if (j < _cols - 1)
                std::cout << ", ";
        }
        std::cout << "]";
        if (i < _rows - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

const float *Matrix::getData() const // Get
{
    return data;
}

float *Matrix::getData() // Set
{
    return data;
}

float *Matrix::operator[](int row)
{

    if (row >= _rows || row < 0)
        throw "No range: Index not in range";

    return &data[row * _cols];
}

const float *Matrix::operator[](int row) const
{
    if (row >= _rows || row < 0)
        throw "No range: Index not in range";

    return &data[row * _cols];
}

bool Matrix::isSquare() const
{
    return _rows == _cols;
}

Matrix Matrix::transpose() const
{
    Matrix result(_cols, _rows);
    for (int i = 0; i < _rows; ++i)
    {
        for (int j = 0; j < _cols; ++j)
        {
            result[j][i] = data[i * _cols + j];
        }
    }
    return result;
}

Matrix Matrix::identity(int size)
{
    Matrix result(size, size);
    for (int i = 0; i < size; ++i)
    {
        result[i][i] = 1.0f;
    }
    return result;
}
