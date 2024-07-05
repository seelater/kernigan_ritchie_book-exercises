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
    int p;
    for (p=1; n > 0; n--)
    {
        p = base * p;
    }
    return p;
}
