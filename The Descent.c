/*
 * @Author: magyu
 * @Date: 2023-03-20 18:14:16
 * @LastEditors: magyu
 * @LastEditTime: 2023-03-20 18:14:16
 * @Description: 请填写简介
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

int main()
{
    int mountain_h_input[8];
    int mountain_h_pos = 0;
    int mountain_h = 0;
    // game loop
    while (1) {
        
    
        for (int i = 0; i < 8; i++) {
            // represents the height of one mountain.
            scanf("%d", &mountain_h_input[i]);
        }

        mountain_h = mountain_h_input[0];

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        for(int i = 1; i < 8; i++ )
        {
            if(mountain_h_input[i] > mountain_h){
                mountain_h = mountain_h_input[i];
                mountain_h_pos = i;
            }
        }

        fprintf(stderr, "list mountain height is %d \n",mountain_h_pos);
        fprintf(stderr, "\n");

        printf("%d\n",mountain_h_pos); // The index of the mountain to fire on.
    }

    return 0;
}