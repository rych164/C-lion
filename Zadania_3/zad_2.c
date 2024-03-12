#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomInt(int lower, int upper)
{
    int num=(rand()%(upper-lower+1))+lower;
    return num;
}
int main()
{
    srand(time(0));
    int width;
    int length;
    int *ptrWidth;
    int *ptrLength;
    printf("width =");
    scanf("%d",&width);
    printf("length =");
    scanf("%d",&length);
    int* ptr = malloc((length * width) * sizeof(int));

    for (int i = 0; i < length * width; i++)
        ptr[i] = generateRandomInt(0,100);

    /* Accessing the array values as if it was a 2D array */
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++)
            printf("%d ", ptr[i * width + j]);
        printf("\n");
    }

    free(ptr);
}
