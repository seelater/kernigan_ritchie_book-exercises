#include <stdio.h>
#include <time.h>

#define SIZE 13

int old_binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid] )
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* найдено соответствие */
        return mid;
    }
    return -1; /* нет соответствия */

}




/*
 * x-target num
 * v-arr
 * n arr_size
 *
 * */
int binsearch(int x, int v[],int n)
{
    int low, high, mid;
    low=0;
    high=n-1;

    if (x < v[low])
    {
        return -1;     
    }else if (x > v[high])
    {
        return -1;
    }
    if(low == high)
    {
        if (x == v[low])
            return low;
    }
   
    while(low < high)
    {
        mid = (low + high) /2;
       
        if(x <= v[mid])
        {
            high = mid ;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (x == v[low])
    {
        return low;
    }

 

    

    return -1;
}



int main(void)
{
    int test[SIZE] = {1,2,4,6,7,13,14,15,16,21,32,43,55};
    
    int x = 13;
    int y = 43;
    int z = 1;
    int a = 14;

    clock_t begin = clock();
    printf(" 13 - 5   res=%8d\n"  ,old_binsearch(x,test,SIZE));
    printf(" 43 - 11  res=%8d\n"  ,old_binsearch(y,test,SIZE));
    printf(" 1  - 0   res=%8d\n"   ,old_binsearch(z,test,SIZE));
    printf(" 1  - 0   res=%8d\n"   ,old_binsearch(a,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,old_binsearch(2,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,old_binsearch(4,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,old_binsearch(6,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,old_binsearch(7,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,old_binsearch(15,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,old_binsearch(16,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,old_binsearch(21,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,old_binsearch(32,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,old_binsearch(55,test,SIZE));
    puts("---time---");
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf\n",time_spent);

    
    begin = clock();

    printf(" res=%6d\n"  ,binsearch(x,test,SIZE));
    printf(" res=%6d\n"  ,binsearch(y,test,SIZE));
    printf(" res=%6d\n"   ,binsearch(z,test,SIZE));
    printf(" res=%6d\n"  ,binsearch(a,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,binsearch(2,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,binsearch(4,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,binsearch(6,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,binsearch(7,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,binsearch(15,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,binsearch(16,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,binsearch(21,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,binsearch(32,test,SIZE));
    printf(" 14 - 6   res=%8d\n"  ,binsearch(55,test,SIZE));
    puts("---time---");
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf\n",time_spent);
    return 0;
}
