
#include <iostream>
#include "books.h"
/*
    2.2.2 Saisie de livres
*/

Book readBook()
{
    Book book;
    std::cout << "Enter book title(One name books only): ";
    std::cin >> book.title;

    do
    {
        std::cout << "Enter the number of pages between 2-2000: ";
        std::cin >> book.pages;
        if (not std::cin)
        {
            std::cerr << "no input detected" << std::endl;
        }

    } while (book.pages < 2 || book.pages > 2000);

    return book;
}

void readBookTab(Book books[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        std::cout << " Data for Book " << (i + 1) << std::endl;
        books[i] = readBook();
    }
}

void showBookName(const Book &book)
{
    std::cout << "Title: " << book.title << ", Pages: " << book.pages << std::endl;
}

void showBookTabName(const Book books[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        showBookName(books[i]);
    }
}

void swapPages(Book &book1, Book &book2)
{
    std::swap(book1.pages, book2.pages);
}

Book &findLongBook(Book books[], int tam)
{
    int pageMax = books[0].pages;
    int index = 0;
    for (int i = 1; i < tam; i++)
    {
        if (books[i].pages > pageMax)
        {
            pageMax = books[i].pages;
            index = i;
        }
    }
    return books[index];
}

Book &findShortBook(Book books[], int tam)
{
    int pageMin = books[0].pages;
    int index = 0;
    for (int i = 1; i < tam; i++)
    {
        if (books[i].pages < pageMin)
        {
            pageMin = books[i].pages;
            index = i;
        }
    }
    return books[index];
}

void blague(Book books[], int tam)
{
    swapPages(findLongBook(books, tam), findShortBook(books, tam));
    std::cout << "\nAfter wapping pages >:D (Blague)" << std::endl;
    showBookTabName(books, tam);
}

void bis(Book books[], int tam)
{
    Book &longestBook = findLongBook(books, tam);
    Book &shortestBook = findShortBook(books, tam);

    swapPages(longestBook, shortestBook);

    std::cout << "\nAfter swapping pages >:D (Bis)" << std::endl;
    showBookTabName(books, tam);
}
/*
    2.2.1 Validation de saisie
*/

// o número de páginas lido
int GetByValue::readPages()
{
    int pages;

    do
    {
        std::cout << "(func 1) Enter the number of pages between 2-2000: ";
        std::cin >> pages;
        std::cout << "Your Value: " << pages << std::endl;
    } while (pages < 2 || pages > 2000);
    return pages;
}

// modifica o número de páginas através de um ponteiro
void GetByAddress::readPages(int *pages)
{
    do
    {
        std::cout << "(func 2) Enter the number of pages between 2-2000: ";
        std::cin >> *pages;
        std::cout << "Your Value: " << *pages << std::endl;
    } while (*pages < 2 || *pages > 2000);
}

// tenta modificar o valor (mas não o faz porque é passado por valor)
void GetByValueAgain::readPages(int pages)
{
    do
    {
        std::cout << "(func 3) Enter the number of pages between 2-2000: ";
        std::cin >> pages;
        std::cout << "Your Value: " << pages << std::endl;
    } while (pages < 2 || pages > 2000);
}

// modifica o valor através de referência
void GetByReference::readPages(int &pages)
{
    do
    {
        std::cout << "(func 4) Enter the number of pages between 2-2000: ";
        std::cin >> pages;
        std::cout << "Your Value: " << pages << std::endl;
    } while (pages < 2 || pages > 2000);
}
