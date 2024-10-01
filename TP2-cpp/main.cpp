#include <iostream>
#include "complex.h"

int main()
{
    int n = 5;        // Exemplo: calcular as 5 raízes da unidade
    Complex array[5]; // Alocar array de 5 complexos na pilha

    // Atribuir as raízes n-ésimas da unidade ao array
    assignRootsOfUnity(n, array);

    // Exibir os resultados
    std::cout << "Raízes " << n << "-ésimas da unidade:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        array[i].displayRectangularForm();
    }

    return 0;
}

/*
    PART 1: DEFINITION DES COMPLEXES (Test for main)
        std::cout << "Before the sum:" << std::endl;
        std::cout << "C1: ";
        c1.displayRectangularForm();
        std::cout << "C2: ";
        c2.displayRectangularForm();

        std::cout s<< "Sum:" << std::endl;
        Complex newComplex = c1 + c2;
        newComplex.displayRectangularForm();

        std::cout << "Subtraction:" << std::endl;
        newComplex = c1 - c2;
        newComplex.displayRectangularForm();

        std::cout << "Multiplication:" << std::endl;
        newComplex = c1 * c2;
        newComplex.displayRectangularForm();

        std::cout << "Module and Phase" << std::endl;
        std::cout << newComplex.module() << std::endl;
        std::cout << newComplex.argument() << std::endl;

        // double module = 6.4031;
        // double phase = 0.6747;
        double module = 10.1980;
        double phase = 1.3734;

        // polar
        Complex c3(module, phase, ComplexForm::Polar);
        std::cout << "Rectangular form of Polar input:" << " Module:" << module << " Phase: " << phase << std::endl;
        c3.displayRectangularForm();
*/

/*
    PART 2: TRACES (Test for main)

        Complex c1(3.0, 2.0); // Rectangular
        Complex c2(2.0, 2.0); // Rectangular
        Complex c3;
        Complex c4(c2);

        c3 = c1 * c2;

        // Rotation

        Complex c1(3, 15);
        c1.displayPolarForm();
        c1.rotate(90);
*/

/*
    PART 3: Arguments, retour de fonction et références

    Complex c1(5, 10);
    Complex c2;

    std::cout << "Applying normalize: " << std::endl;
    c2 = normalized(c1);
    std::cout << "Module: " << c2.module() << " Arg: " << c2.argument() << std::endl;

    c2.displayRectangularForm();
    c2.displayPolarForm();

    ------

    Complex z1(3, 4);
    Complex z2(-3, 4);

    z1 = maxModule(z1, z2);

    std::cout << "Complex number with bigger module: " << std::endl;
    z1.displayRectangularForm();
    z1.displayPolarForm();

    ------

*/