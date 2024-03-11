#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[15];
    char lastName[15];
    char number[15];
}Contact;
void printContacts(Contact arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("\nName: %s\n",arr[i].name);
        printf("Last name: %s\n",arr[i].lastName);
        printf("Number: %s\n",arr[i].number);
    }
}
void append(Contact arr[],int n,Contact ele)
{
    arr[n]=ele;
}
int search(Contact arr[],char lastName[],int size)
{
    int index;
    for(int i=0;i<size;i++)
    {
        if(strcmp(arr[i].lastName,lastName)==0)
        {
            printf("\nName: %s\nLastName: %s\nNumber: %s\nIndex: %d",arr[i].name,arr[i].lastName,arr[i].number,i);
            index=i;
        }
    }
    return index;
}
void removeContact(Contact arr[],char lastname[],int size)
{
    int indexToRemove=search(arr,lastname,size);
    for(int i=indexToRemove+1;i<size;i++)
    {
        Contact temp=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=temp;
    }
    for(int i=0;i<size-1;i++)
    {
        printf("\nName: %s\nLastName: %s\nNumber: %s\n",arr[i].name,arr[i].lastName,arr[i].number);
    }
}
int main()
{
    Contact arrayCon[8];
    arrayCon[0]=(Contact){"Stefan","Wyszynski","123456789"};
    arrayCon[1]=(Contact){"Maciek","Dobrzyk","432543654"};
    arrayCon[2]=(Contact){"Czeslam","Modry","987654321"};
    arrayCon[3]=(Contact){"Szymon","Francuz","987321654"};
    arrayCon[4]=(Contact){"Zygmunt","Wielki","123789654"};
    int lastIndex=4;
    int n=sizeof(arrayCon)/sizeof(arrayCon[0]);
    int decide;
    printf("\nTo add new Contact press 1.\nTo search Contact by last name press 2.\nTo remove Contact using last name press 3\nTo print all Contacts press4\ndecide:");
    scanf("%d",&decide);
    char name[15];
    char lastname[15];
    char number[15];
    Contact ele={*name,*lastname,*number};
    switch(decide)
    {
        case 1:


            printf("write name of contact: ");
            scanf("%s",name);
            printf("write last name of contact: ");
            scanf("%s",lastname);
            printf("write number of contact: ");
            scanf("%s",number);
            append(arrayCon,++lastIndex,ele);
            printContacts(arrayCon,n);
            break;
        case 2:
            scanf("%s",lastname);
            search(arrayCon,lastname,n);
            break;
        case 3:
            scanf("%s",lastname);
            printf("after removal");
            removeContact(arrayCon,lastname,n);
            break;
        case 4:
            printContacts(arrayCon,n);
            break;
        default:
            printf("Wrong input");
    }
}//
// Created by wawrz on 11.03.2024.
//
