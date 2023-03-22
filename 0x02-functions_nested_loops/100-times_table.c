#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the size of the times table to print
 *
 * Return: void
 */
void print_times_table(int n)
{
    int i, j;

    if (n > 15 || n < 0)
        return;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            int res = i * j;

            if (j == 0)
                printf("%d", res);
            else
                printf(" %d", res);

            if (j != n)
                printf(",");
        }
        printf("\n");
    }
}

