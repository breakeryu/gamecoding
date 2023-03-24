
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void checkDirection(char *target, int * width_min, int *height_min, int *width_max, int *height_max, int *target_x, int *target_y)
{

    int c_length = strlen(target);

    if(c_length == 1){
        if(!strcmp(target,"U")){
            *height_max = *target_y;
            *width_max = *target_x;
            *width_min = *target_x;
            *target_y = (*target_y + *height_min) / 2;
        }
        if(!strcmp(target,"D")){
            *height_min = *target_y;
            *width_max = *target_x;
            *width_min = *target_x;
            *target_y = (*height_max + *target_y) / 2;
        } 
        if(!strcmp(target,"L")){
            *width_max = *target_x;
            *height_max = *target_y;
            *height_min = *target_y;
            *target_x = (*width_min + *target_x) / 2;
        }
        if(!strcmp(target,"R")){
            *width_min = *target_x;
            *height_max = *target_y;
            *height_min = *target_y;
            *target_x = (*width_max + *target_x) / 2;
        } 
    }else if(c_length == 2){
        if(!strcmp(target,"DL")){
            *height_min = *target_y;
            *width_max = *target_x;
            *target_y = (*height_max + *target_y) / 2;
            *target_x = (*width_min + *target_x) / 2;
        }
        if(!strcmp(target,"DR")){
           *height_min = *target_y;
           *width_min = *target_x;
           *target_y = (*height_max + *target_y) / 2;
           *target_x = (*width_max + *target_x) / 2;
        } 
        if(!strcmp(target,"UL")){
            *height_max = *target_y;
            *width_max = *target_x;
            *target_y = (*target_y + *height_min) / 2;
            *target_x = (*width_min + *target_x) / 2;
        }
        if(!strcmp(target,"UR")){
            *height_max = *target_y;
            *width_min = *target_x;
            *target_y = (*target_y + *height_min) / 2;
            *target_x = (*width_max + *target_x) / 2;
        }
    }
    
}
    

    



int main()
{
    // width of the building.
    int W;
    // height of the building.
    int H;
    scanf("%d%d", &W, &H);
    // maximum number of turns before game over.
    int N;
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);

    int min_X_position = 0; 
    int max_X_position = W;

    int min_Y_position = 0; 
    int max_Y_position = H;

    // game loop
    while (1) {
        // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        char bomb_dir[4];
        scanf("%s", bomb_dir);
        int dir_length = strlen(bomb_dir);
        fprintf(stderr, "* is in %s \n", bomb_dir);
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        checkDirection(bomb_dir,&min_X_position,&min_Y_position,&max_X_position,&max_Y_position,&X0,&Y0);
        fprintf(stderr, "(%d,%d):(%d,%d) \n",min_X_position,min_Y_position,max_X_position,max_Y_position );
        printf("%d %d\n",X0,Y0);

        // the location of the next window Batman should jump to.
        //printf("0 0\n");
    }

    return 0;
}