// Readability
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int main()
{
    //Inititialising variables
    int words = 0;
    int letters = 0;
    int sentences = 0;

    //Taking input text
    string text = get_string("Enter text: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // counts the letters using ascii code

        if (text[i] >= 65 && text[i] <= 122)
        {
            letters++;
        }

        // counts the words by reading spaces and avoids exclamation marks, full stop and commas
        else if (text[i] == 32 && (text[i - 1] != 33 && text[i - 1] != 46 && text[i - 1] != 63))
        {
            words++;
        }
        // counts the sentences by finding dots, exclamation marks and interrogatives
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
            words++;
        }
    }
    // Calculating L and S
    float L = (float)letters * 100 / words;
    float S = (float)sentences * 100 / words;

    // calculating readability
    int readability = round(0.0588 * L - 0.296 * S - 15.8);

    // printing readability
    if (readability < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readability >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", readability);
    }

}