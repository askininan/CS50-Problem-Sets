#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float blueInt = image[h][w].rgbtBlue;
            float greenInt = image[h][w].rgbtGreen;
            float redInt = image[h][w].rgbtRed;
            
            // Getting the average color of the pixel
            int avg = round((blueInt + greenInt + redInt) / 3);

            // Filter the pixtel 
            image[h][w].rgbtBlue = image[h][w].rgbtGreen = image[h][w].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Sepia formula
            float sepiaRed = .393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue;
            float sepiaGreen = .349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue;
            float sepiaBlue = .272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue;
        
            int red = round(sepiaRed);
            int green = round(sepiaGreen);
            int blue = round(sepiaBlue);
            
            // Check if the color value exceeds 255, ultimate number
            if (red > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = red;
            }
            if (green > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = green;
            }
            if (blue > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = blue;
            }
            
        }
    }    
    return;
}

// Reflect image
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w ++)
        {
            // Create a temporary image (tmp)
            RGBTRIPLE tmp = image[h][w];
            // Invert the image on w/2 axis
            image[h][w] = image[h][width - (w + 1)];
            image[h][width - (w + 1)] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Define sum of each colour of the grid of the pixel
            int sumRed = 0;
            int sumBlue = 0;
            int sumGreen = 0;
            float counter = 0.00;
            
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    // Check if the pixel is valid
                    if (h + i < 0 || h + i > height - 1 || w + j < 0 || w + j > width - 1)
                    {
                        continue;
                    }
                    
                    sumBlue += image[h + i][w + j].rgbtBlue;
                    sumRed += image[h + i][w + j].rgbtRed;
                    sumGreen += image[h + i][w + j].rgbtGreen;
                    
                    // Count valid pixels
                    counter++;
                }
            }
            
            // Write blurred to pixels to temporary image array
            temp[h][w].rgbtBlue = round(sumBlue / counter);
            temp[h][w].rgbtRed = round(sumRed / counter);
            temp[h][w].rgbtGreen = round(sumGreen / counter);
        }
    }
    
    // Overwrite the image with blurred pixels
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtBlue = temp[h][w].rgbtBlue;  
            image[h][w].rgbtRed = temp[h][w].rgbtRed;  
            image[h][w].rgbtGreen = temp[h][w].rgbtGreen;    
        }
    }
    return;
}
