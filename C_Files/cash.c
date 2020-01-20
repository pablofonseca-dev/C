#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    //Program variables
    float dollars;         //Get the user cash.
    int coins;             //Convert cash to cents and store the value in coins
    int coins_counter = 0; //Counts the amount of coins.
    do
    {
        dollars = get_float("Change owed: ");
        //If dollars are less than 0.0, so it is a negative number
        if (dollars <= 0.0)
        {
            printf("The value is invalid\n");
        }
        else
        {
            coins = round(dollars * 100);
            //Just enter in loops if the coin is higher to the current values,
            //if it is true, is increment the coins counter and then substract
            //the value of the total coins with the same coin kind.
            while (coins >= 25)
            {
                coins = coins - 25;
                coins_counter = coins_counter + 1; //Increments quarters
            }
            while (coins >= 10)
            {
                coins = coins - 10;
                coins_counter = coins_counter + 1; //Increments dimes
            }
            while (coins >= 5)
            {
                coins = coins - 5;
                coins_counter = coins_counter + 1; //Increments nickes coins
            }
            while (coins >= 1)
            {
                coins = coins - 1;
                coins_counter = coins_counter + 1; //Increments pennies coins
            }
            //Prints the final result
            printf("%i\n", coins_counter);
        }
    } 
    while (dollars <= 0.0);
}
