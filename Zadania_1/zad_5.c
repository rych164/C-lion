#include <stdio.h>
int main()
{
    int liczba;
    printf("Wpisz dowolna liczbe dodatnia: ");
    scanf_s("%d", &liczba);
    int suma = 0;
    for (int i = 0; i <= liczba; i++)
    {
        if (i>=0)
        {
            if ((i % 3 == 0) && (i % 5 == 0))
            {
                printf("%d\n", i);
                suma += i;
            }
            else if (i % 5 == 0)
            {
                printf("%d\n", i);
                suma += i;
            }
            else if (i % 3 == 0)
            {
                printf("%d\n", i);
                suma += i;
            }
        }
        else
        {
            printf("%d\n",0);
        }
    }
    printf("%d\n", suma);
    return 0;
}//
// Created by wawrz on 11.03.2024.
//
