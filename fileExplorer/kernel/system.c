#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "system.h"

void minisystem()
{
    printf("minisystem\n");
}

void dicegame()
{
    srand(time(NULL));
    int Computer_a = rand()%6 + 1;
    int Computer_b = rand()%6 + 1;
    int sum_C = Computer_a + Computer_b;
    printf("computer's sum of dice is %d + %d = %d\n", Computer_a, Computer_b, sum_C);
    
    int player_a = rand()%6 + 1;
    int player_b = rand()%6 + 1;
    int sum_P = player_a + player_b;
    printf("player's sum of dice is %d + %d = %d\n", player_a, player_b, sum_P);
    
    if (sum_C > sum_P){
        printf("Computer's win..\n");
    }
    else if (sum_P > sum_C){
        printf("your win!\n");
    }
    else{//sum_P == sum_C
        printf("draw.\n");
    }
}





