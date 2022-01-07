#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long n;
    int dig = 0;
    int i = 1;
    int r;
    int rDig = 0;
    int firstSum = 0;
    int secondSum = 0;
    int totalSum = 0;
    int checkSum;
    long j = 0;
    long k = 0;
    
    do
    {
        n = get_long("Credit card number: ");
    }
    while (n < 0);                                      // get user's credit card number
    
    j = n;
    
    while (j >= 100)                                    //find first 2 digits
    {
        j = j / 10;
    }

    k = n;
    
    while (k >= 10)                                     //find first digit
    {
        k = k / 10;
    }

    while (n > 0)                                       //start the Luhn's algorithm, Checksum
    {
        dig = (n % 10);                                 //find the digits of the number, starting from the last digit
        
        if (i % 2 == 
            0)                                          //as initial i is 1, skips the last digit and process till the first digit by skipping 1 digit in every turn 
        {
            r = dig * 2;
            rDig = (r / 10) + (r % 10);
            firstSum += rDig;
        }
        else                                            //sum the digit that are not multiplied with 2
        {
            secondSum += dig;
        }
        n = n / 10;
        i++;                                            //in the end i-1 gives the number of digits in the credit card number
    }
    totalSum = firstSum + secondSum;
    checkSum = totalSum % 10;                           //finds the last digit of checksum total
    
    if (checkSum == 0 && k == 4 && (i - 1 == 13 || i - 1 == 16))
    {
        printf("VISA\n");
    }
    else if (checkSum == 0 && (j == 51 || j == 52 || j == 53 || j == 54 || j == 55) && i - 1 == 16)
    {
        
        printf("MASTERCARD\n");
    }
    else if (checkSum == 0 && (j == 34 || j == 37) && i - 1 == 15)
    {
        
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
    // printf("%i, %i, %i, %i\n", i-1, firstSum, secondSum, totalSum);
}
