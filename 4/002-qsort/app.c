#include <stdio.h>


/* qsort: сортировка v[left]...v[right] в порядке возрастания */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right) /* ничего не делать, если в массиве */
        return; /* меньше двух элементов */

    swap(v, left, (left+right)/2); /* переместить */
    last = left; /* разделитель в v[0] */
    
    for (i = left+1; i<= right; i++) /* упорядочение */
        if (v[i] < v[left] )
             swap(v, ++last, i);

    swap(v, left, last); /* вернуть разделитель на место */
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


/* swap: обмен местами v[i] и v[j] */
void swap(int v[], int i, int j)
{
    printf("swap i,j = %d %d\n",i,j);
    int temp;
    temp = v[i];
    v[i] = v[j] ;
    v[j] = temp;
}

int main(void)
{
    int test[5]={7,1,2,9,4};

        


    qsort(test,0,4);

    int i;
    i=0;
    while(i<5){ 
        printf("%d",test[i]);
        i++;
    }

    return 0;
}
