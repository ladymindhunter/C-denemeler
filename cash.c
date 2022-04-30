#include <stdio.h>
#include <cs50.h>
#include <math.h>

// q -25c, d -10c, n-5c, p -1c

int main(void)
{

    float change; 
    do 
    {
        change = get_float("How much change is owned: "); 
    }
    while (change < 0); 


    int convertCents = round(change * 100); 
    int coins = 0; 

    while (convertCents >= 25) 
    {
        convertCents = convertCents - 25;
        coins++;
    }
    while (convertCents >= 10) //loop for dimes
    {
        convertCents = convertCents - 10;
        coins++;
    }
    while (convertCents >= 5) 
    {
        convertCents = convertCents - 5;
        coins++;
    }
    while (convertCents >= 1 && convertCents > 0)
    {
        convertCents = convertCents - 1;
        coins++;
    }

    printf("%d\n", coins);

}
