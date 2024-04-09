#import "stdlib.h"
#import "stdio.h"
void add(int a,int b)
{
    printf("result of function add %d",a+b);
}

void multiply(int a,int b)
{
    printf("result of function multiply %d",a*b);
}

void subtract(int a, int b)
{
    printf("result of function subtract %d",a-b);
}

int main()
{
    int choose;
    int num1, num2;
    printf("Insert int:");
    scanf("%d",&num1);
    printf("Insert int:");
    scanf("%d",&num2);
    printf("Choose operation:");
    scanf("%d",&choose);
    void (*pointerToFunc) (int,int);
    switch(choose)
    {
        case 1:
            pointerToFunc=&add;
            break;
        case 2:
            pointerToFunc=&multiply;
            break;
        case 3:
            pointerToFunc=&subtract;
            break;
        default:
            printf("Incorrect choose");
    }
    pointerToFunc(num1,num2);
}
//
// Created by wawrz on 09.04.2024.
//
