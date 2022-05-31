#include <stdio.h>
/*INT maxes out for any slightly large input
Changed to double, however now leads trailing decimals, and still displays infinity for values greater than 20*/
long factorial( int n );

int main( void )
{
    int num;
    long fact;
    printf("Please enter a positive whole number (less than 25), or a negative number to exit\n>>");
    scanf( "%d", &num );
    while( num >= 0 )
    {
        fact = factorial( num );
        printf( "Your factorial is %lu", fact );
        printf( "\nPlease enter another whole number\n>>" );
        scanf( "%d", &num );
    }
    
    return 0;    
    
}

long factorial( int n )
{
    long fact = 1;
    while( n > 1 )
    {
        fact *= n;
        n -= 1;
    }

    return fact;
}
