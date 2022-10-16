#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
//Declare variables 
    int a, b, greyFilter; 
    double avPix;
//iterate through the rows
    for (a = 0; a < height; a++)
    {
//for each row, iterate through the columns
        for (b = 0; b < width; b++)
        {
//find the average of the sum of original pixel values
            avPix = (image[a][b].rgbtRed + image[a][b].rgbtGreen + image[a][b].rgbtBlue) / 3.0;
//round the average value and assign it to each pixel
            greyFilter = round(avPix);
            image[a][b].rgbtRed = greyFilter;
            image[a][b].rgbtGreen = greyFilter;
            image[a][b].rgbtBlue = greyFilter;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
//Declare variables
    int a, b; 
    double sepiaR, sepiaG, sepiaB;
//iterate through the rows
    for (a = 0; a < height; a++)
    {
//for each row, iterate through the columns
        for (b = 0; b < width; b++)
        {
//calculate each pixel's sepia value using the given formula. Remember not to exceed the boundary of 255
            sepiaR = round((0.393 * image[a][b].rgbtRed + 0.769 * image[a][b].rgbtGreen + 0.189 * image[a][b].rgbtBlue));
            if (sepiaR > 255)
            {
                sepiaR = 255;
            }
            sepiaG = round((0.349 * image[a][b].rgbtRed + 0.686 * image[a][b].rgbtGreen + 0.168 * image[a][b].rgbtBlue));
            if (sepiaG > 255)
            {
                sepiaG = 255;
            }
            sepiaB = round((0.272 * image[a][b].rgbtRed + 0.534 * image[a][b].rgbtGreen + 0.131 * image[a][b].rgbtBlue));
            if (sepiaB > 255)
            {
                sepiaB = 255;
            }
//replace each pixel to their calculated sepia value.
            image[a][b].rgbtRed = sepiaR;
            image[a][b].rgbtGreen = sepiaG;
            image[a][b].rgbtBlue = sepiaB;        
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
//Declare variables
    int a, b, c;
    RGBTRIPLE t;
//iterate through the rows
    for (a = 0; a < height; a++)
    {
//for each row, iterate halfway through the columns
        for (b = 0, c = width - 1; b < width / 2; b++)
        {
//swap the left half with right half
            t = image[a][b];
            image[a][b] = image[a][c - b];
            image[a][c - b] = t;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
//Declare variables
    RGBTRIPLE temp[height][width];
    int a, b, c, d;
//iterate through the rows
    for (a = 0; a < height; a++)
    {
//for each row, iterate through the columns 
        for (b = 0; b < width; b++)
        {
//make a copy of the original pixels 
            temp[a][b] = image[a][b];
        }
    }
//iterate through the rows
    for (a = 0; a < height; a++)
    {
//for each row, iterate through the columns
        for (b = 0; b < width; b++)
        {
            double rSum = 0, gSum = 0, bSum = 0, neighbor = 0;
//iterate through the rows of blur box
            for (c = a - 1; c < a + 2; c++)
            {
//for each row, iterate through the columns
                for (d = b - 1; d < b + 2; d++)
                {
//define the boundaries of the blur-box within the 2D array 
                    if (c < 0 || c > height - 1 || d < 0 || d > width - 1)
                    {
                        continue;
                    }
//sum up the values of red, green, and blue pixels. Also count the items in the blur-box
                    rSum += temp[c][d].rgbtRed;
                    gSum += temp[c][d].rgbtGreen;
                    bSum += temp[c][d].rgbtBlue;
                    neighbor++;
                }
            }
//find each average for red, green, blue in the blur-box and assign it to the original 
            image[a][b].rgbtRed = round(rSum / neighbor);
            image[a][b].rgbtGreen = round(gSum / neighbor);
            image[a][b].rgbtBlue = round(bSum / neighbor);
        }
    }
    return;
}
