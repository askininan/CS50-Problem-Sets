#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string plaintext = NULL;
    int k = 0;
    int c = 0;
    int key = 0;
    int textLength = 0;

    if (argc < 1)                                                               //return exit code 1, just to be safe
    {
        return 1;
    }
    else if (argc > 1)                                                          //continue on getting the key with prompter if argc >1
    {
        printf("%s\n", argv[1]);
        int isdig = isdigit((char)argv[1]);
        if (isdig == 0)
        {
            k = (atoi((string)argv[1]));
            key = k % 26;
            if (k > 0)
            {
                plaintext = get_string("Plaintext: ");                          //get a plaintext to cipther from user
                textLength = strlen(plaintext);                                 //calculate the length of the plaintext
                printf("ciphertext: ");
            }
            else
            {
                printf("usage: ./caesar key\n");
            }
        }
        else
        {
            printf("usage: ./caesar key\n");
    
        }    
    }
    
    else
    {
        return 1;                                                               //return exit code 1 if argv[1] does not exist
    }

    for (int i = 0; i < textLength; i++)                                        
    {
        c = (plaintext[i] + key);
        
        
        //return uppercase ciphered letter if the plain letter is uppercase
        if (isupper(plaintext[i]) && (c > 'Z'))                                                 
        {
            c = (c - 26);
        }
        //return lowercase ciphered letter if the plain letter is lowercase
        if (islower(plaintext[i]) && (c > 'z'))                                                 
        {
            c = (c - 26);
        }
        if (isalpha(plaintext[i]))                                              //print c (ciphered letter) char if plain char is a letter
        {
            printf("%c", c);
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }

    printf("\n");
}