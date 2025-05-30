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
    
    int a,b;
    month_day(2001,64,&a,&b);
    printf("%d %d\n",a,b);
    month_day(2000,65,&a,&b);
    printf("%d %d\n",a,b);
    
    return 0;
}

int day_of_year(int year,int month, int day)
{
    int leap, i;
    
    if(day>31 || day < 1 || month > 12 || month < 1)
        return -1;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    for (i = 1; i<month;i++)
        day+=daytab[leap][i];
    return day;
}

void month_day(int year,int yearday,int *pmonth, int *pday)
{
    int leap, i;
    
    if (yearday > 366 || yearday < 1 )
        return;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0 ;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -=daytab[leap][i];
    *pday = yearday;
    *pmonth = i;

}

