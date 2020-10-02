// importing header files
#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

// Main Function
int main(int argc, string argv[])
{
    int key = 0;
    
    // convertes the argument of the function into an int if it exists
    if (argc == 2)
    {
        key = atoi(argv[1]);
    }

    // Takes the modulo of the key if it's bigger than the alphabet's length
    if (key >= 26)
    {
        key %= 26;
    }
    

    // validates user input, it must exist and be a positive integer, otherwise prints a message and return one
    if (argc != 2 || key <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //getting prompt input
    string text = get_string("plaintext: ");

    
    if (argc == 2)
    {
        for (int i = 0, n = strlen(text); i < n ; i++)
        {
            // Uppercase caesar ciper
            if (text[i] >= 65 && text[i] <= 90)
            {
                if (text[i] + key > 90)
                {
                    text[i] -= 26;
                }
                text[i] += key;
            }
            // Lowercase text cipher
            if (text[i] >= 97 && text[i] <= 122)
        
            {
                if (text[i] + key > 122)
                {
                    text[i] -= 26;
                }
                text[i] += key;
            }
        }
    }    
    // Prompt output
    printf("ciphertext: %s\n", text);
    

}