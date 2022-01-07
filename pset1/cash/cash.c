#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int counter = 0;
    
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    // get user input for what is the change
    
    
    int amountLeft = round(change * 100);    // input amount is turned into cents

    while (amountLeft >= 25)                 // count quarters
    {
        amountLeft = amountLeft - 25;
        counter ++ ;
    }
    while (amountLeft >= 10)                 // count dimes
    {
        amountLeft = amountLeft - 10;
        counter ++ ;
    }
    while (amountLeft >= 5)                  // count nickels
    {
        amountLeft = amountLeft - 5;
        counter ++ ;
    }
    while (amountLeft >= 1)                  // count pennies
    {
        amountLeft = amountLeft - 1;
        counter ++ ;
    }
    printf("%i coins\n", counter);
}