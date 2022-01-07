#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <ctype.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    // Open input file
    FILE *sourceFile = fopen(argv[1], "r");
    
    // Check if source file is null
    if (sourceFile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 1;
    }

    // Declare buffer file
    FILE *JPG;
    
    // Declare block of bytes
    BYTE block[512];

    bool foundjpg = false;
    int counter = 0;

    while (fread(block, sizeof(block), 1, sourceFile) == 1)
    {
        // Check first four bytes if jpg
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            
            // Create file name
            char filename[8];
            sprintf(filename, "%03i.jpg", counter);

            if (foundjpg == true)
            {
                fclose(JPG);
            }
            else
            {
                foundjpg = true;
            }
            
            // Write found jpg to file
            JPG = fopen(filename, "w");
            fwrite(block, sizeof(block), 1, JPG);
            counter++;
        }
        else
        {
            if (foundjpg == true)
            {
                fwrite(block, sizeof(block), 1, JPG);
            }
        }
    }
    fclose(sourceFile);
    fclose(JPG);
}