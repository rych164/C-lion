#include <stdio.h>
#include <stdbool.h>

void show(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
}
 int findIndex(int sortedArray[],int leftIndex,int rightIndex,int toFind)
 {
    if(rightIndex>=leftIndex)
    {
        int mid=leftIndex + (rightIndex-leftIndex)/2;
        printf("\n%d",mid);
        if(sortedArray[mid]==toFind)
        {
            return mid;
        }
        if(sortedArray[mid]>toFind)
        {
            return findIndex(sortedArray,leftIndex,mid-1,toFind);
        }
        else
        {
            return findIndex(sortedArray,mid+1,rightIndex,toFind);
        }
    }
    return -1;
}
void swap(int*xp,int*yp)
{
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}
void bubbleSort(int array[],int n)
{
    int i,j;
    bool swapped;
    for(i=0;i<n-1;i++)
    {
        swapped=false;
        for(j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(&array[j],&array[j+1]);
                swapped=true;
            }

        }
        if(swapped==false)
        {
            break;
        }
    }
}
int main(){

    int array[]={3,2,6,8,1,5,7,12,4,87,0};
    int lenght=sizeof(array)/sizeof(array[0]);
    show(array,lenght);
    bubbleSort(array,lenght);
    printf("\n");
    show(array,lenght);
    printf("\n%d",findIndex(array,0,lenght-1,12));
    return 0;
}
