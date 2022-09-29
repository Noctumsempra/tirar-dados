#ifndef	_HELPER_H
#define	_HELPER_H 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ENTER '\n'

enum seedtype { SECS = 1, MSECS = 2 };

void init_random_seed(seedtype seed_type)
{
    switch (seed_type)
    {
        case SECS: {
            time_t current_time = time(NULL);
            srand(current_time);
            break;
        }

        case MSECS: {
            struct timespec spec;
            clock_gettime(CLOCK_REALTIME, &spec);

            // Paso Nanosegs a Milisegs.
            long msecs = round(spec.tv_nsec / 1.0e6);
            srand(msecs);

            break;
        }
    }
}

void show_splash_screen() {
    printf("******************************************\n");
    printf("*****      TIRADA de DADOS 1.0       *****\n");
    printf("******************************************\n");
    printf("\n");
    printf("A continuación, 2 usuarios tirarán los dados,\n");
    printf("quien saque el número más alto será el ganador!\n");
    printf("\n");
    printf("Presione cualquier tecla para continuar...\n");

    getchar();
}

void show_options(int userNumber) {
    int option;

    printf("Usuario %02d: ", userNumber);
    scanf("%d", &option);
}

int prompt(const char* message) {
    int ch;

    printf("%s", message);

    ch = getchar();
    return (ch == '\n' || ch == EOF) ? getchar() : ch;
}

int roll_dice() {
    return 1 + rand() % 6;
}

char play_again() {
    char option;

    printf("Jugar de nuevo? S/N: ");
    do {
        option = toupper(getchar());
    } while (option != 'S' && option != 'N');

    return option != 'N';
}

bool check_draw(int dices[], int players) {
    bool is_draw = true;

    for (register int dice = 0; dice < players; dice++) {
        if (dice > 0 && dices[dice] != dices[dice-1]) {
            is_draw = false;
            break;
        }
    }

    return is_draw;
}

void print_dice(int player, int dice) {
    printf("\tJugador #%d tiró y sacó: %d\n", player, dice);
}

void print_winner(int winner, int winner_dice, bool is_draw) {
    if (is_draw) {
        printf("\nFue un empate!");
    } else {
        printf("\nGanó el jugador #%d (sacó un %d).", winner, winner_dice);
    }
    printf("\n\n");
}

int good_bye(void) {
    printf("\nGracias por jugar!\n\n");
    return 0;
}

#endif