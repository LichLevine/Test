#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "chessmap.h"
#include "TimeCount.h"

/*刷新棋盘*/
void draw(int **state, int row, int column)
{
    /*清空屏幕*/
	system("cls");

	int i,j;

    /*列序号对齐棋盘*/
    printf("  ");


	/*标出棋盘的列序号*/
	for (i = 0; i < column; i++)
		printf("%c ", (char)(i+65));
    printf("\n");

    /*标出棋盘的行序号以及每一行每一列的棋盘模样*/
	for (i = 0; i < row; i++)
    {
		printf("%c ", (char)(i+65));
		for (j = 0; j < column; j++)
		{
			switch(state[i][j])
			{
				case 0:
					if (j > 0 && j < column-1)
						printf("%s", (i == 0 ? TOP_CENTER : i == row-1? BOTTOM_CENTER : INTERNAL));
					else if (j == 0)
						printf("%s", (i == 0 ? LEFT_TOP : i == row-1 ? LEFT_BOTTOM : LEFT_CENTER));
					else if(j == column-1)
						printf("%s", (i == 0 ? RIGHT_TOP : i == row-1 ? RIGHT_BOTTOM : RIGHT_CENTER));
					break;
				case 1:
					printf("%s", BLACK);
					break;
				case 2:
					printf("%s", WHITE);
					break;
				default:
					break;
			}
		}
		printf("\n");
	}
}
