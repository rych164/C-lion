#include <stdio.h>

void printArray(int array[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
void swap(int *xp,int *yp)
{
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}


void permute(int *array,int left,int right){
    if(left==right)
    {
        printArray(array,right+1);
        return;
    }
    for(int i=left;i<=right;i++)
    {
        swap(array+i,array+left);
        permute(array,left+1,right);
        swap(array+i,array+left);
    }

}

int main(){
    int len;
    printf("Enter length of array:");
    scanf("%d",&len);
    int array[len];
    for(int i=0;i<len;i++)
    {
        array[i]=i;
    }
    permute(array,array[0],array[len-1]);
    return 0;
}
//
// Created by wawrz on 12.03.2024.
//
