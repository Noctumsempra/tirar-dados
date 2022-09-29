#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "inc/helper.h"

#define PLAYERS 2

int main (void) 
{
    int dice_roll[PLAYERS];

    init_random_seed(seedtype::MSECS);
    show_splash_screen();

    do {
        int winner = 0, max_dice = 1;

        for (register int i = 0; i < PLAYERS; i++)
        {
            int player_number = i+1;

            dice_roll[i] = roll_dice();
            print_dice(player_number, dice_roll[i]);

            if (dice_roll[i] > max_dice) {
                max_dice = dice_roll[i];
                winner = player_number;
            }
        }

        print_winner(winner, max_dice, check_draw(dice_roll, PLAYERS));

    } while (play_again());

    return good_bye();
}