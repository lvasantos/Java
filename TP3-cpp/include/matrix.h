
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix
{
private:
    int _rows;
    int _cols;
    float *data;

public:
    // Constructors
    // Default constructors for 1x1 Matrix
    Matrix();
    // Destructors
    ~Matrix();
    // 2. Construtor com número de linhas e colunas, inicializando com 0
    Matrix(int r, int c);
    // 3. Construtor com tamanho e array 1D de valores
    Matrix(int r, int c, const float *values);

    // 4. Construtor de cópia
    Matrix(const Matrix &other);
    // 5. Operador de atribuição por cópia
    Matrix &operator=(const Matrix &other);
    // 6. Construtor de movimentação
    Matrix(Matrix &&otherMatrix);
    // Operador de atribuição por movimentação
    Matrix &operator=(Matrix &&otherMatrix);

    // arithmetics
    Matrix operator+(const Matrix &m2) const;
    Matrix operator*(const Matrix &m2) const;
    Matrix operator-(const Matrix &m2) const;
    Matrix operator-() const;

    // TODO: operadores de >> e <<

    // Utils
    int getRows() const;
    int getCols() const;
    void displayMatrix() const; // Show Matrix as Matrix
    void display() const;       // Show Matrix as [ [0, 0], [0, 0] ]
    const float *getData() const;
    float *getData();
    float *operator[](int row);             // You can write at the position
    const float *operator[](int row) const; // Read-only
    bool isSquare() const;
    Matrix transpose() const;
    Matrix identity(int size);
};

#endif // COMPLEX_H
