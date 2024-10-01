
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

/*
    Is not possible to add the Polar form, since there is another constructor for (double r, double i), it flags for ambiguity in the constructors and so I did the enum to specify what type of entry I'm using, in this case Polar or Rectangular
*/

enum class ComplexForm
{
    Polar,
    Rectangular,
};

class Complex
{
private:
    double real;
    double img;

public:
    // Constructors
    Complex();
    Complex(double r, double i, ComplexForm form = ComplexForm::Rectangular);
    Complex(const Complex &otherComplex);

    // Destructors
    ~Complex();

    // Overload
    Complex &operator=(const Complex &otherComplex);

    // Fetch
    double getReal() const;
    double getImg() const;

    // arithmetics
    double module() const;
    double argument() const;

    // Utils
    void displayRectangularForm() const;
    void displayPolarForm() const;
    void swapParts();

    // overload for arithmetics
    Complex operator+(const Complex &c1) const;
    Complex operator-(const Complex &c1) const;
    Complex operator*(const Complex &c1) const;

    /// Rotates a Complex by an Angle(Degrees)
    void rotate(double angle);
};

// // Functions
Complex normalized(const Complex &c1);
const Complex &maxModule(const Complex &c1, const Complex &c2);
void roots(int n, Complex *array);

#endif // COMPLEX_H