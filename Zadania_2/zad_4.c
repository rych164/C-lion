#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    char name[20];
    float grade;
}Student;
void swap (Student*x,Student*y){
    Student temp=*x;
    *x=*y;
    *y=temp;
}
void bubleSort(Student arr[],int n)
{
    int i,j;
    bool swapped;
    for(i=0;i<n;i++)
    {
        swapped = false;
        for(j=0;j<n-i-1;++j)
        {
            if(arr[j].grade<arr[j+1].grade)
            {
                swap(&arr[j],&arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false)
        {
            break;
        }
    }
}


void printArray(Student arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("Name: %s\nGrade: %f\n",arr[i].name,arr[i].grade);
    }
}
int main()
{
    Student arraySt [100] = {{"Stefan",3},{"Jacek",4},{"Krzyś",5},{"Maciek",1},{"Tomek",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6},
                             {"Stefan",3},{"Jacek",4},{"Stefan",5},{"Maciek",1},{"Tomek",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6},
                             {"Stefan",3},{"Jacek",4},{"Krzyś",5},{"Maciek",1},{"Tomek",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6},
                             {"Stefan",3},{"Jacek",4},{"Krzyś",5},{"Maciek",1},{"Tomek",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6},
                             {"Stefan",3},{"Jacek",4},{"Krzyś",5},{"Maciek",1},{"Tomek",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6},
                             {"Stefan",3},{"Jacek",4},{"Krzyś",5},{"Maciek",1},{"Stefan",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6},
                             {"Stefan",3},{"Jacek",4},{"Krzyś",5},{"Maciek",1},{"Tomek",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6},
                             {"Stefan",3},{"Jacek",4},{"Krzyś",5},{"Maciek",1},{"Tomek",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6},
                             {"Stefan",3},{"Jacek",4},{"Krzyś",5},{"Maciek",1},{"Tomek",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6},
                             {"Stefan",3},{"Jacek",4},{"Krzyś",5},{"Maciek",1},{"Tomek",2},{"Czesław",6},{"zygmunt",3},{"Czarek",4},{"Miłosz",2},{"Szymon",6}
    };
    int n = sizeof(arraySt)/sizeof(arraySt[0]);
    //printArray(arraySt,n);
    bubleSort(arraySt,n);
    printf("Sorted array\n");
    printArray(arraySt,n);
}//
// Created by wawrz on 11.03.2024.
//
