#include <stdio.h>
#include <time.h>


#define SIZE 1000

void expand(char s1[], char s2[])
{

    int state = 0;
    int n_state=0;

    int i;
    int j=0;

    char start = '0';
    char mid = '0';
    char end = '0';

    char n_start ='0';
    char n_end = '0';

    for(i=0; s1[i]=='-' ;i++)
    {
        s2[j++] ='-';
    }

    while (s1[i] != '\0')
    {
        if ( (s1[i]>='a' && s1[i]<='z') || (s1[i]>='A' && s1[i]<='Z') )
        {
            if (state ==0)
            {
                start = s1[i];
                printf("start %c\n",start);
            }else if (state == 1)
            {
                end = s1[i];
                printf("end %c\n",end);
            }else if (state == 2)
            {
                mid=end;
                end = s1[i];
                printf("mid %c, end %c\n",mid,end);
            }else if (state !=0 && end == '0') 
            {
                start ='0';
                state =0;
            }

        }
        if (s1[i] >='1' && s1[i]<='9')
        {
            if (n_state ==0)
            {
                n_start = s1[i];
                printf("n_start %c\n",n_start);
            }else if (n_state == 1)
            {
                n_end = s1[i];
                printf("n_end %c\n",n_end);
            }
        }

        if (start !='0' && s1[i] =='-')
        {
            state++;
        }

        if(n_start!='0' && s1[i]=='-')
        {
            n_state++;
        }

        i++;
    }

    
    // loop to fill s2
    //


    if (start !='0'  && end !='0' )
    {
        if (mid != '0')
        {
            while (start<=mid)
            {
                s2[j]=start;
                start++;
                j++;
            }
            while (mid <=end)
            {
                s2[j]=mid;
                mid++;
                j++;
            }
        }else{
            while( start <= end)
            {
                s2[j]=start;
                start++;
                j++;
            }
        }
    }
    if(n_start!='0' && n_end !='0')
    {
        while (n_start<=n_end)
        {
            s2[j]=n_start;
            n_start++;
            j++;
        }
    }
    
    s2[j]='\0';

    printf("%s\n",s2);

}

void expand2(char s1[],char s2[])
{

    int i,j;
    int state =0;
    int in_abc =0;
    char c;

    for (i=0,j=0;s1[i]!='\0';i++)
    {
        if((s1[i]>='a' &&  s1[i]<='z') || (s1[i]>='A' && s1[i]<='Z')  
                                       || (s1[i]>='1'&& s1[i]<='9')) 
        {
            in_abc = 1;
            if (state ==1)
            {
                while(c<= s1[i])
                {
                    s2[j++] = c++;
                }
            }
        }else if(s1[i]==' ') {
            s2[j++]=s1[i];
            in_abc=0;
        }else if(state==0)
        {
            s2[j++]=s1[i];
        }

        if(in_abc == 1 && s1[i]=='-')
        {
            state = 1 ;
            c = s1[i-1];
        }                   
    }

    s2[j]='\0';
    printf("%s\n",s2);
}



int main(void)
{
    char s1[] ="a-z1-4";
    char s2[SIZE];
    clock_t begin = clock();
    expand(s1,s2);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf\n",time_spent);

    begin = clock();

    expand2(s1,s2);
    end = clock();
     time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf\n",time_spent);


    return 0;
}
