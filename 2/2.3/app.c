#include <stdio.h>

#define IN 1
#define OUT 0
#define SIZE 5


int power(int,int);
void htoi(char [],int);

void htoi( char s[],int size)
{
    int state=0;
    int n =0;
    int count =0;
    int t =1;
    
    for(int i= 0; i<size;++i)
    {
        if (state == OUT)
        {
            if (s[i]=='0' || count ==1) {
                ++count;
                if (count ==2 && (s[i]=='x'|| s[i]=='X')) {
                    state=IN;
                    count=0;
                }else if(count==2){count =0;}
            }
        }

        if (state ==IN  && ((s[i]>='A' && s[i]<='F') || (s[i]>='a' && s[i]<='f') || (s[i]>='0'&& s[i]<='9')))
        {
            if (s[i]>='a' && s[i]<='f'){
                n += (s[i]-'a')* power(16,t)+10;
               t--;
            }else if(s[i]>='A' && s[i]<='F'){
                n += (s[i]-'A')* power(16 , t)+10;
               t--;
            }else{
               n += (s[i]-'0')*power(16, t);
               t--;
            }
            if (t<0){
                state =OUT;
                printf("n= %d\n",n);
                n=0;
                t=1;
            }
        }
    }
}


int main(void)
{
    char test1[SIZE+9]="0x1f x04 0x1f"; //31
    char test2[SIZE]="0X50"; //32

    htoi(test1,SIZE+9);
    htoi(test2,SIZE);

    return 0;
}



int power(int base, int pow)
{
    int i,p;
    p=1;
    if( pow ==0)
    {
        return p;
    }
    for (i = 1;i <= pow;++i)
    {
        p=p*base;
    }
    return p;
}


