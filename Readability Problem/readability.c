#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    float letterCount = 0;
    float wordCount = 0;
    float sentenceCount = 0;
    int textLength;
    float L = 0;
    float S = 0;

    string text = get_string("Text: ");                                                 //get user input text
    textLength = strlen(text);                                                          //calculate the length of the given text

    for (int i = 0; i <= textLength; i++)
    {
        if (isalpha(text[i]) != 0)                                                      //calculate letter count
        {
            letterCount++;
        }
        if (text[i] == ' ' && text[i + 1] != ' ')                                       //calculate word count
        {
            wordCount++;
        }
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')                         //calculate sentence count
        {
            sentenceCount++;
        }
    }

    L = (letterCount / (wordCount + 1)) * 100.0;                                        //average number of letters per 100 words
    S = (sentenceCount / (wordCount + 1)) * 100.0;                                      //average number of senteces per 100 words
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    int roundIndex = (int) round(index);

    if (roundIndex >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", roundIndex);
    }
}
