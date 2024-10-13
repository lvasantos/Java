#include <iostream>
#include "matrix.h"
using namespace std;

// void firstTest();
// void secondTest();

void basicConstructors();
void operators();
void transpose();
void identity();
void moveConstructors();

int main()
{
    // basicConstructors();
    // operators();
    // transpose();
    // identity();
    moveConstructors();

    return 0;
}

void basicConstructors()
{
    // Default constructors for 1x1 Matrix
    std::cout << "Constructors for 1x1 Matrix" << std::endl;
    Matrix m1;
    m1.displayMatrix();

    // Constructors with rows and cols
    // Careful when using, it has no treatment for invalid matrix values
    std::cout << "Constructors with rows and cols" << std::endl;
    Matrix m2(2, 3);
    m2.displayMatrix();

    // Constructor with size and 1D array of values
    std::cout << "Constructor with size and 1D array of values" << std::endl;
    float array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix m3(3, 3, array);
    m3.display();

    // Constructor of copy
    std::cout << "Constructor of copy" << std::endl;
    Matrix m4(m3);
    m4.displayMatrix();
}

void operators()
{
    float array1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float array2[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    Matrix m1; // Empty matrix of 1x1
    Matrix m2(2, 3, array1);
    Matrix m3(3, 4, array2);
    m3 = m2; // Copy assignment operator

    // Move assignment operator
    Matrix m4(3, 4);
    m4 = std::move(m3);
    // Arithmetic operators
    Matrix m5(3, 3, array1); // Matrix with values
    std::cout << "Matrix 5" << std::endl;
    m5.display();
    Matrix m6(3, 3, array2); // Matrix with values
    std::cout << "Matrix 6" << std::endl;
    m6.display();
    Matrix m7 = m5 + m6; // Sum
    std::cout << "Matrix 7: Sum" << std::endl;
    m7.display();
    Matrix m8 = m5 * m6; // Multiplication
    std::cout << "Matrix 8: Multiplication" << std::endl;
    m8.display();
    Matrix m9 = m5 - m6; // Subtraction
    std::cout << "Matrix 9: Subtraction" << std::endl;
    m9.display();
    Matrix m10 = -m5; // Negative of a matrix
    std::cout << "Matrix 10: Negative" << std::endl;
    m10.display();
}

void transpose()
{

    float array1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Original:" << std::endl;
    Matrix m1(3, 3, array1);
    m1.displayMatrix();
    std::cout << "Transposed:" << std::endl;
    Matrix m2 = m1.transpose();
    m2.displayMatrix();
}

void identity()
{
    float array1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix m1(3, 3, array1);
    Matrix m2 = m1.identity(3);
    m2.display();
}

void moveConstructors()
{
    float array1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix m1(3, 3, array1);
    std::cout << "Before move: " << std::endl;
    m1.display();
    Matrix m2 = std::move(m1); // During construction
    // m1 = std::move(m2);        // Move assignment operator
    std::cout << "m1: " << std::endl;
    m1.display();
    std::cout << "m2: " << std::endl;
    m2.display();
}

// void firstTest()
// {
//     // Initialize with 0
//     Matrix m1;
//     cout << "m1: " << endl;
//     m1.displayMatrix();

//     // Define size
//     cout << "m2: " << endl;
//     Matrix m2(2, 3);
//     m2.displayMatrix();

//     // Fill with array 1D
//     float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     cout << "m3: " << endl;
//     Matrix m3(3, 4, &array[0]);
//     m3.displayMatrix();

//     // Recopy
//     cout << "m4: " << endl;
//     Matrix m4(m3);
//     m4.displayMatrix();
// }
