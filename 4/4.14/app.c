#include <stdio.h>


#define swap(t,x,y)  t temp; temp = x; x=y; y = temp;



int main()
{

    int a,b;

    a=5;
    b=3;

    swap(int, a, b);

    printf("a=5 b=3\nafter swap\na=%d,b=%d\n",a,b);


    return 0;

}
