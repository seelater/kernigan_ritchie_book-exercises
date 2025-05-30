
#include <stdio.h>

/*strend возвращает 1 если строка t присутствукт в конце строки s и ноль в противном случае*/


int mystrend_2(char *s,char *t)
{
    char *ps;
    char *pt;
    ps=s;
    pt=t;
    
    while(*s)
        s++;
    while(*t)
        t++;
    s--;
    t--;

    //s is shorter than t
    if( s-ps <  t-pt )
        return 0;

    printf("three%d %d\n",*s,*t);
    for ( ; t>=pt ; s--,t-- )
        if (*s == *t){
            printf("%d %d\n",*s,*t);
        }else 
            return 0;


    return 1;

}

int main()
{

    char *s="acllol";
    char *t="llol";
    int i;

    i = mystrend_2(s,t);

    printf("%d\n",i);


    return 0;
}
