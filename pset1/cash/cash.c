#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main()
{

    float amount;
    int coins = 0;
    // ask user for input
    do
    {
        amount = get_float("Change owed: ");
    }
    while (amount <= 0);
    //
    int total = round(amount * 100);

    // checking the condition and incrementing coins
    while (total > 0)
    {
        // total amount more than 25 cents
        if (total >= 25)
        {
            total = total - 25;
            coins++;
        }
        //total amount bw 25 and 10 cents
        else if (total >= 10)
        {
            total = total - 10;
            coins++;
        }
        // total bw 10 and 5 cents
        else if (total >= 5)
        {
            total = total - 5;
            coins++;
        }
        // total bw o and 5 cents
        else
        {
            total = total - 1;
            coins ++;
        }
    }
    printf("you are owed %i coins \n", coins);
}
