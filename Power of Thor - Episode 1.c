/*
 * @Author: magyu
 * @Date: 2023-03-20 17:44:04
 * @LastEditors: magyu
 * @LastEditTime: 2023-03-20 18:12:35
 * @Description: 请填写简介
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
void turn_N(void){
    printf("N\n");
}

void turn_S(void){
    printf("S\n");
}

void turn_W(void){
    printf("W\n");
}

void turn_E(void){
    printf("E\n");
}

void turn_NE(void){
    printf("NE\n");
}

void turn_NW(void){
    printf("NW\n");
}

void turn_SE(void){
    printf("SE\n");
}

void turn_SW(void){
    printf("SW\n");
}


int main()
{

    bool isInline = false;
    // the X position of the light of power
    int light_x;
    // the Y position of the light of power
    int light_y;
    // Thor's starting X position
    int initial_tx;
    // Thor's starting Y position
    int initial_ty;
    scanf("%d%d%d%d", &light_x, &light_y, &initial_tx, &initial_ty);
    fprintf(stderr, "initial_tx = %d, initial_ty = %d, \
                     light_x = %d, light_y = %d\n", initial_tx,initial_ty,light_x, light_y);
    // game loop
    while (1) {
        // The remaining amount of turns Thor can move. Do not remove this line.
        int remaining_turns;
        scanf("%d", &remaining_turns);
        fprintf(stderr, "remaining_turns = %d \n",remaining_turns);
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        isInline = false;
        
        if(initial_tx == light_x){
            isInline = true;
            fprintf(stderr, "Thor is in line! \n");
            if(initial_ty > light_y){
                initial_ty -= 1;
                turn_N();
            }else{
                initial_ty += 1;
                turn_S();
            }
        }

        if(initial_ty == light_y){
            isInline = true;
            fprintf(stderr, "Thor is in line! \n");
            if(initial_tx > light_x){
                initial_tx -= 1;
                turn_W();
            }else{
                initial_tx += 1;
                turn_E();
            }
        }

        if(isInline == false){
            fprintf(stderr, "Thor is not in line! \n");
            if(initial_tx > light_x){
                if(initial_ty > light_y)
                {
                    initial_ty -= 1;
                    initial_tx -= 1;
                    turn_NW();  
                }else{
                    initial_ty += 1;
                    initial_tx -= 1;
                    turn_SW();
                }
            }else{
                if(initial_ty > light_y)
                {
                    initial_ty -= 1;
                    initial_tx += 1;
                    turn_NE();  
                }else{
                    initial_ty += 1;
                    initial_tx += 1;
                    turn_SE();
                }
            }

        }
        

        // A single line providing the move to be made: N NE E SE S SW W or NW
        //printf("SE\n");
    }

    return 0;
}