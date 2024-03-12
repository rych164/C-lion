#include <stdio.h>

unsigned int factorial(unsigned int number)
{
    if(number==0)
    {
        return 1;
    }
    return number*factorial(number-1);
}

int main()
{
    printf("%d\n", factorial(5));
    return 0;
}
