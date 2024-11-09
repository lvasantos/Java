#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "iplot.h"

void createFileCommand(double lim)
{
    FILE *file = fopen("commandes.gp", "w");
    if (file == NULL)
    {
        perror("Erro ao criar arquivo de comandos");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "set samples 500\n");
    fprintf(file, "set title 'Sinus Cardinal'\n");
    fprintf(file, "set xlabel 'x'\n");
    fprintf(file, "set ylabel 'sin(x)/x'\n");
    fprintf(file, "set key font 'Times New Roman, 12'\n");
    fprintf(file, "set xrange [%f:%f]\n", -lim, lim);
    fprintf(file, "set border\n");
    fprintf(file, "set grid\n");
    fprintf(file, "plot sin(x)/x\n");

    fclose(file);
}

void executeGNUPlot()
{
    execlp("gnuplot", "gnuplot", "-persist", "commandes.gp", NULL);
    perror("Erro com o Gnuplot"); // Error avec GNU
    exit(EXIT_FAILURE);
}
