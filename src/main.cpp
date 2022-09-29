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
        bool is_draw = true;
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

        for (register int dice = 0; dice < PLAYERS; dice++) {
            if (dice > 0 && dice_roll[dice] != dice_roll[dice-1]) {
                is_draw = false;
                break;
            }
        }

        print_winner(winner, max_dice, is_draw);

    } while (play_again());

    return good_bye();
}