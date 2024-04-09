#include <stdio.h>
#include <stdlib.h>

union types{
    int theInt;
    float theFloat;
    char theChar;
};
int main()
{
    union types types1;
    types1.theInt=3;
    printf("%d\n",types1.theInt);
    types1.theFloat=2.4;
    printf("%f\n",types1.theFloat);
    types1.theChar='a';
    printf("%c\n",types1.theChar);
}
//
// Created by wawrz on 09.04.2024.
//
