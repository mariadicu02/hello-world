#include <stdio.h>
#include <stdlib.h>

int countOfDigit( int n, int digit)
{
    int totAppSoFar;
    if(n<10)//if 'n' is one digit
        if( n != digit)
        return 1;// 0 appearance ==> even appearance
    else // num==digit
        return 0;//digit appears once in num ==> odd appearancel
        if(n %10 == digit)
        return 1+ countOfDigit(n/10, digit);
    return countOfDigit(n/10, digit);
    totAppSoFar = countOfDigit( n/10, digit);
    if(totAppSoFar == 1)
        if(n%10 == digit)
         return 0;
        else
         return 1;
     else
        if(n % 10 == digit)
        return 1;
     else
        return 0;

     /*

    if(n<10)
        if( n != digit)
        return 1;
    else
        return 0;
        if(n %10 != digit)
           return countOfDigit(n/10, digit);
        else
            return !countOfDigit(n/10, digit);

