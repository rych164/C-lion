#include <stdlib.h>
#include <stdio.h>


int main()
{
    int array  [10];
    for(int i=0;i<sizeof(array)/sizeof(array[0]);i++)
    {
        array[i]=i;
    }
    int *pointer=&array[0];
    for(int i=0;i<sizeof(array)/sizeof(array[0]);i++)
    {
        printf("%d\n",*pointer);
        pointer++;
    }
}
//
// Created by wawrz on 09.04.2024.
//
