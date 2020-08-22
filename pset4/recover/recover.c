#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image");
        return 1;
    }
    // Remember filenames
    char *infile = argv[1];
    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    // Create buffer space
    unsigned char buffer[512];
    // Create filename space
    char filename[8];
    // Filename depends on image number
    int counter = 0;
    // Create output file
    FILE *outptr;
    // Create a flag to know if jpeg open or not
    bool jpeg = false;
    // Read memory card
    while (fread(buffer, sizeof(buffer), 1, inptr))
    {
        // Find beginning of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If we already have an open jpeg || jpeg == true
            if (jpeg)
            {
                fclose(outptr);
                // Set flag to false
                jpeg = false;
            }
            // Create new filename for it
            sprintf(filename, "%03i.jpg", counter);
            // Open output file in write mode
            outptr = fopen(filename, "w");
            // Write current buffer to file
            fwrite(buffer, 512, 1, outptr);
            // Set flag to true
            jpeg = true;
            // Increment filename counter
            counter++;
        }
        // If it doesn't start with a jpeg header
        else
        {
            if (jpeg)
            {
                // Write left buffer to file
                fwrite(buffer, 512, 1, outptr);
            }
        }
    }
    fclose(inptr);
    fclose(outptr);
}