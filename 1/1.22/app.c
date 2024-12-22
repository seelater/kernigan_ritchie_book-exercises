#include<stdio.h>

#define MAXLINE 1000
#define DELIMETER 20


void print_line(char arr[],int size)
{
    
}



int main()
{

    char line[MAXLINE] = {0};
    int c = 0;
    int pos = 0;

    while ( (c = getchar()) != EOF)
    {
        if ( pos < DELIMETER )
        {
            line[pos] = c;
            pos++;
        }else 
        {
            line[pos] = '\n';
            pos++;
            line[pos] = '\0';
            pos++;

        }
    }
    if (pos < DELIMETER)
    {    
        for (int i = 0; i < pos;i++ )
        {
            printf("%c",line[i]);
            
        }
    }





    return 0;
}
