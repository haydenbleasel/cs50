#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Initialise dollars to -1 (placeholder)
    float dollars = -1;

    // Define coin values
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // While the user hasn'
    while (dollars < 0) {
        dollars = get_float("Change owed: ");
    }

    int coins = round(dollars * 100);

    int sum = 0;

    while (coins > 0) {
        sum += 1;

        if (coins >= 25) {
            coins -= 25;
        } else if (coins >= 10) {
            coins -= 10;
        } else if (coins >= 5) {
            coins -= 5;
        } else if (coins >= 1) {
            coins -= 1;
        }
    }

    printf("%i\n", sum);
}
