
#include <stdio.h>

/*strend возвращает 1 если строка t присутствукт в конце строки s и ноль в противном случае*/
int mystrend(char *s, char *t)
{
    char *ps;
    char *pt; 
    for ( ; *s; s++){
        for ( ps=s, pt=t; *pt && *ps == *pt; ps++,pt++ )
            ;

        if ( (*pt == *ps) == '\0'  && *pt != *t  )
            return 1;
    }
        
    return 0;
}

int mystrend_2(char *s,char *t)
{
    char *ps;
    char *pt;
    ps=s;
    pt=t;
    
    while(*ps++)
        ;
    while(*pt++)
        ;

    //s is shorter than t
    if( ps-s <  pt-t )
        return 0;
    for ( ps-=pt-t, pt = t; *ps; ps++,*pt++ )
        if (*ps != *pt)
            return 0;

    return 1;

}

int main()
{

    char *s="abllol";
    char *t="llola";
    int i;

    i = mystrend_2(s,t);

    printf("%d\n",i);


    return 0;
}
