#include <stdio.h>
#include <stdlib.h>

int main()
{
    //allocate memory
    int *list = malloc(3 * sizeof(int));
    
    if (list == NULL)
    {
        return 1;
    }
    
    // define the array
    list [0] = 1;
    list [1] = 2;
    list [2] = 3;
    
    // re-allocate memory
    int *temp = realloc(list, 4 * sizeof(int));
    list = temp;
    
    // fill the memory left
    list [3] = 4;
    
    // loop through and print
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
}
