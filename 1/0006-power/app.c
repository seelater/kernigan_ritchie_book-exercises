#include <stdio.h>

int power(int,int);


int main()
{
    int size =10;
    for (int i = 0;i<size;i++)
    {
        printf("%d %d %d\n",i,power(2,i),power(-3,i));
    }
    return 0;
}


int power(int base,int n)
{
    int p=1;

    for (int i = 0; i < n; i++)
    {
        p = base * p;
    }
    return p;
}
