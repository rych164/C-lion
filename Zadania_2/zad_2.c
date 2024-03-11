#include <stdio.h>

void doubleValue(float *x)
{
    (*x)*=2;
}

int main()
{
    float x = 12.4;
    printf("%f\n", x);
    doubleValue(&x);
    printf("%f\n", x);
    return 0;

}
