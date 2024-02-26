#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

// Function to implement the battle outcomes
void performBattle(Champion** player1, Champion** player2) {

    // Get the champions for the battle
    Champion* champion1 = *player1;
    Champion* champion2 = *player2;

    // Implement battle outcomes based on champion roles
    switch (champion1->role) {
        case MAGE: {
            switch (champion2->role) {
                case MAGE: {
                    printf("Player 1 is a MAGE and Player 2 is a MAGE\n");
                    if (champion1->level > champion2->level) {
                        
                        /* Remove current champions from player lists
                        this outcome is consistent for all permutations and if-else cases*/
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        
                        *player1 = addChampion(*player1, createChampion());
                        *player2 = removeChampion(*player2);
                        printf("Player 1 (MAGE) wins and gains a new champion.\n");
                        printf("Player 2 (MAGE) loses one champion.\n");
                    } else if (champion1->level < champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player1 = removeChampion(*player1);
                        *player2 = addChampion(*player2, createChampion());
                        printf("Player 1 (MAGE) loses one champion.\n");
                        printf("Player 2 (MAGE) wins and gains a new champion.\n");
                    } else {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        printf("It's a tie. Nothing happens.\n");
                }
                    break;
                }
                case FIGHTER: {
                    printf("Player 1 is a MAGE and Player 2 is a FIGHTER\n");
                    if (champion1->level > champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player1 = addChampion(*player1, createChampion());
                        printf("Player 1 (MAGE) wins and gains a new champion.\n");
                        printf("Player 2 (FIGHTER) loses but with no penalty.\n");
                    } else if (champion1->level < champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player1 = removeChampion(*player1);
                        printf("Player 1 (MAGE) loses one champion.\n");
                        printf("Player 2 (FIGHTER) wins but gains no reward.\n");
                    } else {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        printf("It's a tie. Nothing happens.\n");
                    }
                        break;
                }
                case SUPPORT: {
                    printf("Player 1 is a MAGE and Player 2 is a SUPPORT\n");
                    if (champion1->level > champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player1 = addChampion(*player1, createChampion());
                        *player2 = removeChampion(*player2);
                        *player2 = removeChampion(*player2);
                        printf("Player 1 (MAGE) wins and gains one new champion.\n");
                        printf("Player 2 (SUPPORT) loses two champions.\n");
                    } else if (champion1->level < champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player1 = removeChampion(*player1);
                        *player2 = addChampion(*player2, createChampion());
                        *player2 = addChampion(*player2, createChampion());
                        printf("Player 1 (MAGE) loses one champion.\n");
                        printf("Player 2 (SUPPORT) wins and gains two new champions.\n");
                    } else {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        printf("It's a tie. Nothing happens.\n");
                    }
                        break;
                }
                case TANK: {
                    printf("Player 1 is a MAGE and Player 2 is a TANK\n");
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    *player1 = addChampion(*player1, createChampion());
                    *player2 = removeChampion(*player2);
                    printf("Player 1 (MAGE) gains a new champion.\n");
                    printf("Player 2 (TANK) loses one champion.\n");
                    break;
                }
            }
            break;
        }
        case FIGHTER: {
            switch (champion2->role) {
                case MAGE: {
                    printf("Player 1 is a FIGHTER and Player 2 is a MAGE\n");
                    if (champion1->level > champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player2 = removeChampion(*player2);
                        printf("Player 1 (FIGHTER) wins but gains no reward.\n");
                        printf("Player 2 (MAGE) loses one champion.\n");
                    } else if (champion1->level < champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player2 = addChampion(*player2, createChampion());
                        printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                        printf("Player 2 (MAGE) wins and gains a new champion.\n");
                    } else {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        printf("It's a tie. Nothing happens.\n");
                    }
                    break;
                }
                case FIGHTER: {
                    printf("Player 1 is a FIGHTER and Player 2 is a FIGHTER\n");
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    *player1 = addChampion(*player1, createChampion());
                    *player2 = addChampion(*player2, createChampion());
                    printf("Both players gain a new champion.\n");
                    break;
                }
                case SUPPORT: {
                    printf("Player 1 is a FIGHTER and Player 2 is a SUPPORT\n");
                    if (champion1->level > champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player2 = removeChampion(*player2);
                        printf("Player 1 (FIGHTER) wins but gains no reward.\n");
                        printf("Player 2 (SUPPORT) loses one champion.\n");
                    } else if (champion1->level < champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player2 = addChampion(*player2, createChampion());
                        printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                        printf("Player 2 (SUPPORT) wins and gains a new champion.\n");
                    } else {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        printf("It's a tie. Nothing happens.\n");
                    }
                    break;
                }
                case TANK: {
                    printf("Player 1 is a FIGHTER and Player 2 is a TANK\n");
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    *player1 = addChampion(*player1, createChampion());
                    printf("Player 1 (FIGHTER) wins and gains a new champion. \n");
                    printf("Player 2 (TANK) loses but with no penalty.\n");
                    break;
                }
            }
            break;
        }
        case SUPPORT: {
            switch (champion2->role) {
                case MAGE: {
                    printf("Player 1 is a SUPPORT and Player 2 is a MAGE\n");
                    if (champion1->level > champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player1 = addChampion(*player1, createChampion());
                        *player1 = addChampion(*player1, createChampion());
                        *player2 = removeChampion(*player2);
                        printf("Player 1 (SUPPORT) wins and gains two new champions.\n");
                        printf("Player 2 (MAGE) loses one champion.\n");
                    } else if (champion1->level < champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player1 = removeChampion(*player1);
                        *player1 = removeChampion(*player1);
                        *player2 = addChampion(*player2, createChampion());
                        printf("Player 1 (SUPPORT) loses two champions.\n");
                        printf("Player 2 (MAGE) wins and gains a new champion.\n");
                    } else {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        printf("It's a tie. Nothing happens.\n");
                    }
                    break;
                }
                case FIGHTER: {
                    printf("Player 1 is a SUPPORT and Player 2 is a FIGHTER\n");
                    if (champion1->level > champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player1 = addChampion(*player1, createChampion());
                        printf("Player 1 (SUPPORT) wins and gains a new champion.\n");
                        printf("Player 2 (FIGHTER) loses but with no penalty.\n");
                    } else if (champion1->level < champion2->level) {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        *player1 = removeChampion(*player1);
                        printf("Player 1 (SUPPORT) loses one champion.\n");
                        printf("Player 2 (FIGHTER) wins but gains no reward.\n");
                    } else {
                        *player1 = removeChampion(*player1);
                        *player2 = removeChampion(*player2);
                        printf("It's a tie. Nothing happens.\n");
                    }
                    break;
                }
                case SUPPORT: {
                    printf("Player 1 is a SUPPORT and Player 2 is a SUPPORT\n");
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    printf("Both players lose one champion.\n");
                    break;
                }
                case TANK: {
                    printf("Player 1 is a SUPPORT and Player 2 is a TANK\n");
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    *player2 = addChampion(*player2, createChampion());
                    printf("Player 1 (SUPPORT) loses but with no penalty.\n");
                    printf("Player 2 (TANK) wins and gains a new champion.\n");
                    break;
                }
            }
            break;
        }
        case TANK: {
            switch (champion2->role) {
                case MAGE: {
                    printf("Player 1 is a TANK and Player 2 is a MAGE\n");
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    *player1 = removeChampion(*player1);
                    *player2 = addChampion(*player2, createChampion());
                    printf("Player 1 (TANK) loses one champion.\n");
                    printf("Player 2 (MAGE) gains a new champion.\n");
                    break;
                }
                case FIGHTER: {
                    printf("Player 1 is a TANK and Player 2 is a FIGHTER\n");
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    *player2 = addChampion(*player2, createChampion());
                    printf("Player 1 (TANK) loses but with no penalty.\n");
                    printf("Player 2 (FIGHTER) wins and gains a new champion.\n");
                    break;
                }
                case SUPPORT: {
                    printf("Player 1 is a TANK and Player 2 is a SUPPORT\n");
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    *player1 = addChampion(*player1, createChampion());
                    printf("Player 1 (TANK) wins and gains a new champion.\n");
                    printf("Player 2 (SUPPORT) loses but with no penalty.\n");
                    break;
                }
                case TANK: {
                    printf("Player 1 is a TANK and Player 2 is a TANK\n");
                    *player1 = removeChampion(*player1);
                    *player2 = removeChampion(*player2);
                    printf("It's a tie. Nothing happens.\n");
                    break;
                }
            }
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_champions>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int numChampions = atoi(argv[1]);

    if (numChampions <= 0) {
        fprintf(stderr, "Number of champions must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    // Seed for random number generation
    srand((unsigned int)time(NULL));

    // Build player 1 and player 2 champion lists
    Champion* player1 = buildChampionList(numChampions);
    Champion* player2 = buildChampionList(numChampions);

    // Game loop
    printf("\n============= PLAYER 1 V PLAYER 2 SHOWDOWN =============\n");
    int round = 1;
    while (player1 && player2) {
        printf("\n----- ROUND %d -----\n", round);
        printf("Player 1: ");
        printChampionList(player1);
        printf("Player 2: ");
        printChampionList(player2);

        performBattle(&player1, &player2);

        ++round;
    }

    // Determine and print the final outcome of the game
    printf("\n============= GAME OVER =============\n");
    printf("\nPlayer 1 ending champion list: ");
    printChampionList(player1);
    printf("Player 2 ending champion list: ");
    printChampionList(player2);
    if (!player1 && !player2) {
        printf("\nTIE -- both players ran out of champions.\n");
    } else if (!player2) {
        printf("\nPlayer 2 ran out of champions. Player 1 wins.\n");
    } else {
        printf("\nPlayer 1 ran out of champions. Player 2 wins.\n");
    }

    // Free memory for the linked lists
    player1 = destroyChampionList(player1);
    player2 = destroyChampionList(player2);

    return EXIT_SUCCESS;
}
