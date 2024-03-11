#include <stdio.h>

int main()
{
    int grades[2][5] = { {3,1,4,2,5},{2,6,4,2,3} };
    int sumaMatematyka=0;
    double sredniaMatematyka;
    for (int i = 0; i <=sizeof(grades,0); i++)
    {
        sumaMatematyka += grades[0][i];
        printf("%d\n", grades[0][i]);
    }
    printf("%d\n", sumaMatematyka);
    sredniaMatematyka = sumaMatematyka / sizeof(grades,0);
    printf("%f\n", sredniaMatematyka);
    int sumaFizyka = 0;
    double sredniaFizyka;
    for (int i = 0; i <= sizeof(grades, 1); i++)
    {
        sumaFizyka += grades[1][i];
        printf("%d\n", grades[1][i]);
    }
    printf("%d\n", sumaFizyka);
    sredniaFizyka = sumaFizyka / sizeof(grades, 1);
    printf("%f", sredniaFizyka);
    return 0;
}