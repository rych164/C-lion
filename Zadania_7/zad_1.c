#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int stringToDigit(const char *str)
{
    const char *digits[]={"zero","one","two","three",
                          "four","five","six","seven",
                          "eight","nine"};

    for(int i=0;i<10;i++)
    {
        if(strcmp(str,digits[i])==0){
            return i;
        }
    }
    return -1;
}

int main() {
    FILE *file;
    char *filename = "input1.txt"; // Adjust the relative path as necessary
    char line[1000];
    char *token;
    int sum=0;
    char firstDigit[2],lastDigit[2];

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        int firstDigitFound = 0;
        firstDigit[0] = lastDigit[0] = '\0';

        token=strtok(line,"\n\t");
        while(token !=NULL)
        {
            if(isdigit(token[0]))
            {
                if(!firstDigitFound)
                {
                    firstDigit[0]=token[0];
                    firstDigit[1]='\0';
                    firstDigitFound=1;
                }
                lastDigit[0]=token[0];
                lastDigit[1]='/0';
           }
            else
            {
                int digit= stringToDigit(token);
                if(digit!=-1)
                {
                    if(!firstDigitFound)
                    {
                        sprintf(firstDigit,"%d",digit);
                        firstDigitFound=1;
                    }
                    sprintf(lastDigit,"%d",digit);
                }
            }
            token= strtok(NULL," \n\t");
        }
        if(firstDigitFound)
        {
            if(firstDigit[0]!='\0' && lastDigit[0]!='\0')
            {
                int num=atoi(firstDigit)*10+ atoi(lastDigit);
                sum+=num;
            }
        }
    }
    printf("Sum of all numbers %d\n",sum);
    fclose(file);
    return 0;
}
