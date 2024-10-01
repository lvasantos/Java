#include "complex.h"
#include <iostream>

// Construtores

// Constructors default
Complex::Complex() : real(0.0), img(0.0)
{
    std::cout << "At: " << this << std::endl;
    std::cout << "+++Complex()" << std::endl;
}

Complex::~Complex()
{
    std::cout << "At: " << this << std::endl;
    std::cout << "---Complex(" << real << "+i." << img << ")" << std::endl;
}

// Construtor inicia pedindo dois real e imaginario
Complex::Complex(double r, double i, ComplexForm form) : real(r), img(i)
{
    if (form == ComplexForm::Rectangular)
    {
        real = r;
        img = i;
        std::cout << "At: " << this << std::endl;
        std::cout << "+++Complex(" << real << "," << img << ")" << std::endl;
    }
    else if (form == ComplexForm::Polar)
    {
        real = r * std::cos(i);
        img = r * std::sin(i);

        std::cout << "At: " << this << std::endl;
        std::cout << "+++Complex(" << real << "," << img << ")" << std::endl;
    }
}
// Construtor de cópia
Complex::Complex(const Complex &otherComplex) : real(otherComplex.real), img(otherComplex.img)
{

    std::cout << "At: " << this << std::endl;
    std::cout << "rrrComplex(" << real << "+i." << img << ")" << std::endl;
}

// Construtor de atribuição
Complex &Complex::operator=(const Complex &otherComplex)
{
    if (this != &otherComplex)
    {
        real = otherComplex.real;
        img = otherComplex.img;

        std::cout << "At: " << this << std::endl;
        std::cout << "op=Complex(" << real << "+i." << img << ")" << std::endl;
    }
    return *this;
}

// Fetch
double Complex::getReal() const { return real; }
double Complex::getImg() const { return img; }

// Math funcs
double Complex::module() const
{
    return std::sqrt((real * real) + (img * img));
}

double Complex::argument() const
{
    double result = atan2(img, real);

    // convert result to degrees
    double degree = result * (180.0 / 3.141592);

    return degree;
}

// Utils (a + i.b)
void Complex::displayRectangularForm() const
{
    std::cout << real << " + i." << std::round(img) << std::endl;
}

void Complex::displayPolarForm() const
{
    std::cout << this->module() << "∠" << this->argument() << std::endl;
}

void Complex::swapParts()
{
    std::swap(real, img);
}

// Overloard for arithmetics
// sum of two complex
Complex Complex::operator+(const Complex &c1) const
{

    return Complex(c1.getReal() + this->getReal(), c1.getImg() + this->getImg()); // c3 = c1+c2
}

Complex Complex::operator-(const Complex &c1) const
{
    return Complex(c1.getReal() - this->getReal(), c1.getImg() - this->getImg());
}

Complex Complex::operator*(const Complex &c1) const
{
    return Complex(
        c1.getReal() * this->getReal() - c1.getImg() * this->getImg(),
        c1.getReal() * this->getImg() + c1.getImg() * this->getReal());
}

/* This returns a compilation error trying to access a private member.

    Complex sum(const Complex &c1, const Complex &c2)
    {
        return Complex(c1.real + c2.real, c1.img + c2.img);
    }

*/

// PART 3: Arguments, retour de fonction et références

Complex normalized(const Complex &c1)
{

    return Complex(c1.getReal() / c1.module(),
                   c1.getImg() / c1.module());
}

void Complex::rotate(double angle)
{
    // degrees  to radians to make arithmetics
    double PI = 3.14159;

    double radians = angle * (PI / 180.0);

    double re = this->real * cos(radians) - this->img * sin(radians);
    double im = this->real * sin(radians) + this->img * cos(radians);
    this->real = re;
    this->img = im;

    std::cout << "New value after rotation:" << std::endl;
    this->displayRectangularForm(); // rect form
    std::cout << " Module: " << this->module() << ", Argument: " << this->argument() << std::endl;
}

const Complex &maxModule(const Complex &c1, const Complex &c2)
{
    return ((c1.module() > c2.module()) ? c1 : c2);
}

void roots(int n, Complex *array)
{
    // As raízes n-ésimas da unidade têm módulo 1 e ângulos iguais
    for (int k = 0; k < n; ++k)
    {
        double angle = 2 * M_PI * k / n;                  // Ângulo em radianos
        array[k] = Complex(1, angle, ComplexForm::Polar); // Usar a forma polar para atribuir
    }
}