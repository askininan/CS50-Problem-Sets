
#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int n;    int l = 1;
    
    do
    {
        n = get_int("Rows: ");
    }
    while (n < 1 || n > 8);                     // get user input between 1 & 8
    

    for (int i = 1; i <= n; i++)                // create n amount of rows
    {
        for (int k = n - i ; k > 0  ; k--)
        {
            printf(" ");
        }
        // output spaces
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int m = 1; m <= i; m++)
        {
            printf("#");
        }
        
        // create bricks
        printf("\n");
    }

}










