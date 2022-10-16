#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
int main(int argc, char *argv[])
{
//ensure one command line argument 
    if (argc != 2)
    {
        printf("Usage: /recover IMAGE\n");
        return 1;
    }
//open read file 
    FILE *card = fopen(argv[1], "r");
//display error message if file isn't opening
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
//declare string to write pictures
    char out_pic[8] = "000.jpg";
//open write file 
    FILE *image = NULL;
//initialize image  to zero
    int pic = 0;
//declare buffer to read data to & fro
    uint8_t buffer[512];
//read data in blocks of 512
    while (fread(buffer, sizeof(uint8_t), 512, card) == 512)
    {
//check if header satisfies conditions 
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
//check if first jpeg is found and store
            if (pic == 0)
            {
                sprintf(out_pic, "%03i.jpg", pic);
                image = fopen(out_pic, "w");
                pic++;
            }
//if others are found, close previous and store
            else
            {
                fclose(image);
                sprintf(out_pic, "%03i.jpg", pic);
                image = fopen(out_pic, "w");
                pic++;
            }
        }
//if write file isn't null, copy and recover jpegs
        if (image != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, image);
        }
    }
    fclose(image);
    fclose(card);
}