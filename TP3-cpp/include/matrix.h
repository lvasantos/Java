
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
    Matrix() : _rows(1), _cols(1)
    {
        data = new float[1];
        data[0] = 0.0f;
    }

    // 2. Construtor com número de linhas e colunas, inicializando com 0
    Matrix(int r, int c) : _rows(r), _cols(c)
    {
        data = new float[_rows * _cols];
        std::memset(data, 0, _rows * _cols * sizeof(float)); // Inicializa tudo com 0
    }

    // 3. Construtor com tamanho e array 1D de valores
    Matrix(int r, int c, const float *values) : _rows(r), _cols(c)
    {
        data = new float[_rows * _cols];
        std::memcpy(data, values, _rows * _cols * sizeof(float)); // Copia os valores fornecidos
    }

    // 4. Construtor de cópia
    Matrix(const Matrix &other) : _rows(other._rows), _cols(other._cols)
    {
        data = new float[_rows * _cols];
        std::memcpy(data, other.data, _rows * _cols * sizeof(float)); // Copia os dados da outra matriz
    }

    // 5. Operador de atribuição por cópia
    Matrix &operator=(const Matrix &other)
    {
        if (this != &other)
        {                  // Verifica auto-atribuição
            delete[] data; // Libera a memória atual

            // Aloca nova memória e copia os dados
            _rows = other._rows;
            _cols = other._cols;
            data = new float[_rows * _cols];
            std::memcpy(data, other.data, _rows * _cols * sizeof(float));
        }
        return *this;
    }
    // Destructors

    // arithmetics

    // Utils

    // overload for arithmetics
};

#endif // COMPLEX_H
