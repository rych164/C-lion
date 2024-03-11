#include <stdio.h>
int main()
{
    int i = 1;
    int* pointer = &i;
    *pointer = 20;
    printf("%d\n", i);
    printf("%d\n", *pointer);
    return 0;

}
