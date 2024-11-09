#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "iplot.h"

int main()
{
    double lim;

    while (1)
    {
        printf("Enter the limit: ");
        if (scanf("%lf", &lim) != 1)
        {
            printf("Invalid ! Closing...\n");
            break;
        }
        createFileCommand(lim);

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Error creating child process");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            sleep(2);
            executeGNUPlot();
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}
