#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_from_header(void)
{
   printf("The value of CHAR_BIT: %d\n", CHAR_BIT);
   
   printf("The value of SCHAR_MIN: %d\n", SCHAR_MIN);
   printf("The value of SCHAR_MAX: %d\n", SCHAR_MAX);
   printf("The value of UCHAR_MAX: %u\n", UCHAR_MAX);
   
   printf("The value of CHAR_MIN: %d\n", CHAR_MIN);
   printf("The value of CHAR_MAX: %d\n", CHAR_MAX);
   
   printf("The value of SHRT_MIN: %d\n", SHRT_MIN);
   printf("The value of SHRT_MAX: %d\n", SHRT_MAX);
   printf("The value of USHRT_MAX: %u\n", USHRT_MAX);
   
   printf("The value of INT_MIN: %d\n", INT_MIN);
   printf("The value of INT_MAX: %d\n", INT_MAX);
   printf("The value of UINT_MAX: %u\n", UINT_MAX);
   
   printf("The value of LONG_MIN: %ld\n", LONG_MIN);
   printf("The value of LONG_MAX: %ld\n", LONG_MAX);
   printf("The value of ULONG_MAX: %lu\n", ULONG_MAX);
 
}

void print_char_diap(void)
{
    
    char min_ch = 0;
    char max_ch = 0;
    signed char min_sch = 0;
    signed char max_sch = 0;
    unsigned char min_uch = 0;
    unsigned char max_uch = 0;

    while (1) {   
        max_ch++;
        if(max_ch==0){
            min_ch=max_ch;
            max_ch--;
            break; 
        }
    }

    while (1){
        max_sch++;       
        if(max_sch< 0) {
            min_sch=max_sch;
            max_sch--;
            break;
        }
    }

    while (1) {
        max_uch++;       
        if((max_uch) == 0) {
            min_uch =max_uch;
            max_uch--;
            break;
        }
    }
    printf("The value of CHAR_MIN: %d\n", min_ch);
    printf("The value of CHAR_MAX: %d\n", max_ch);

    printf("The value of SCHAR_MIN: %d\n", min_sch);
    printf("The value of SCHAR_MIN: %d\n", max_sch);

    printf("The value of uCHAR_MAX: %u\n", min_uch);
    printf("The value of uCHAR_MAX: %u\n", max_uch);
}

void print_int_diap(void)
{
    int min_i=0;
    int max_i=0;
    signed int min_si=0;
    signed int max_si=0;
    unsigned int min_ui=0;
    unsigned int max_ui=0;
    while (1)
    {
        max_i++;
        if (max_i<1)
        {   
        printf("%d ",max_i);
            min_i=max_i;
            max_i--;
            break;
        }
        
    }

    printf("The value of CHAR_MIN: %d\n", min_i);
    printf("The value of CHAR_MAX: %d\n", max_i);

    printf("The value of SCHAR_MIN: %d\n", min_si);
    printf("The value of SCHAR_MIN: %d\n", max_si);

    printf("The value of uCHAR_MAX: %u\n", min_ui);
    printf("The value of uCHAR_MAX: %u\n", max_ui);
}


int main()
{
    print_from_header();
//    print_char_diap();

  //  print_int_diap();
   /*    short
    signed
    unsigned 

    int
    signed
    unsigned 

    long 
    signed
    unsigned 
*/
   
    
    return 0;
}
