#include <stdio.h>


int day_of_year(int year,int month, int day);
void month_day(int year,int yearday,int *pmonth, int *pday);

  static char daytab[2][13] = { 
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };
int main(void)
{
    printf("%i\n",day_of_year(2001,3,5));
    printf("%i\n",day_of_year(2000,3,5));
    printf("%i\n",day_of_year(2001,12,31));
    
    int a,b;
    month_day(2001,64,&a,&b);
    printf("%d %d\n",a,b);
    month_day(2000,65,&a,&b);
    printf("%d %d\n",a,b);
    month_day(2001,65,&a,&b);
    printf("%d %d\n",a,b);
    
    return 0;
}

int day_of_year(int year,int month, int day)
{
    int leap ;
    char* p;
    
    if(day > 31 || day < 1 || month > 12 || month < 1)
        return -1;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = daytab[leap];

    while (month--){
        day += *p++;
    }
    return day;
}

void month_day(int year,int yearday,int *pmonth, int *pday)
{
    int leap;
    char *p, *pstart;

    if (yearday > 366 || yearday < 1 )
        return;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ;
    p = daytab[leap];
    pstart = daytab[leap];
    
    while(yearday > *p){
        yearday -= *p++;
    }
    *pmonth = p-pstart;
    *pday = yearday;

}

