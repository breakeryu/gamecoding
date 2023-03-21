/*
 * @Author: magyu
 * @Date: 2023-03-21 18:00:15
 * @LastEditors: magyu
 * @LastEditTime: 2023-03-21 20:06:09
 * @Description: 请填写简介
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void Int2AscII(int val, char *asc);

void output_Result(int rotate, int power){
    char stringRotote [10] ;
    char stringPower [10];
    memset(stringRotote, 0, 10);
    memset(stringPower, 0, 10);
    Int2AscII(rotate,stringRotote);
    Int2AscII(power,stringPower);
    
    strcat(stringRotote," ");
    strcat(stringRotote,stringPower);
    fprintf(stderr, "stringRotote = %s\n", stringRotote);
    printf("%s\n",stringRotote);
    
}

int main()
{
    // the number of points used to draw the surface of Mars.
    int surface_n;
    scanf("%d", &surface_n);
    int land_x[surface_n];
    int land_y[surface_n];
    for (int i = 0; i < surface_n; i++) {
        // X coordinate of a surface point. (0 to 6999)
       
        // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        
        scanf("%d%d", &land_x[i], &land_y[i]);
    }

    int flatGroundStartx = 0;
    int flatGroundEndx = 0;
    int flatGroundy = 0;
    bool isfindFlatGround = false;
    for(int i = 0; i < surface_n - 1 ; i++){
        if(land_y[i] == land_y[i+1]){
            isfindFlatGround = true;
            flatGroundStartx = land_x[i];
            flatGroundEndx = land_x[i+1];
            flatGroundy = land_y[i];
            fprintf(stderr, "flatGroundStartx = %d, flatGroundEndx = %d, flatGroundy = %d \n", flatGroundStartx, flatGroundEndx,flatGroundy);
            break;
        }
    }

    int rotote = 0;
    int power = 0;
    float timeMax = 0;
    float timeReality = 0;

    int shipMax_VSpeed = 40;
    int shipMax_HSpeed = 20;
    // game loop
    while (1) {
        int X;
        int Y;
        // the horizontal speed (in m/s), can be negative.
        int h_speed;
        // the vertical speed (in m/s), can be negative.
        int v_speed;
        // the quantity of remaining fuel in liters.
        int fuel;
        // the rotation angle in degrees (-90 to 90).
        int rotate;
        // the thrust power (0 to 4).
        int power;
        scanf("%d%d%d%d%d%d%d", &X, &Y, &h_speed, &v_speed, &fuel, &rotate, &power);
        fprintf(stderr, "ship_x_position = %d, ship_y_position = %d \n", X, Y);
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        
        if(Y >= flatGroundy){
            timeMax = (float)(Y - flatGroundy)/shipMax_VSpeed;
            timeReality = (float)(Y - flatGroundy)/abs(v_speed);

            if( X < flatGroundStartx || X > flatGroundEndx ){
 
            }else{
                if(timeMax >= timeReality){
                    power += 1;
                    if(power >= 4){
                        power = 4;
                    }
                }else{
                    power -= 1;
                    if(power <= 0){
                        power = 0;
                    }
                }
            }

            output_Result(rotate, power);
        }
        
        
        
        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        //printf("0 3\n");
    }

    return 0;
}


void Int2AscII(int val, char *asc)
{
	int NumInt;
	unsigned char i;
	unsigned char IntBuff[32];
	unsigned char IntCnt,addi;

	if(val >= 0)
	{
		addi = 0;
		NumInt=val;
	}
	else
	{
		asc[0] = 45;
		addi = 1;
		NumInt=-val;
	}


	IntCnt=0;
	for(i=0;i<32;i++)
	{
		IntBuff[i] = NumInt%10;
		NumInt = NumInt/10;

		if(0 == NumInt)
		{
			IntCnt = i + 1;
			break;
		}
	}

	for(i=0;i<IntCnt;i++)
	{
		asc[addi + i] = IntBuff[IntCnt - 1  -i] + 48;
	}
}

