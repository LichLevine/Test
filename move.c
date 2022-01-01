#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "chessmap.h"
#include "TimeCount.h"

/*引入全局数组保存黑白双方落棋点*/
extern fallen[ROW][COLUMN];


void playermove(int **state, int row, int column, int order)
{
	int x, y;
	char a, b;
	char str[100];
	sprintf(str, "玩家%d-%s走", order, order==1? "黑方" : "白方");
	printf("%s，如H行A列,则输入HA:\n", str);
	while (1)
    {
		scanf("%c%c",&a,&b);
		fflush(stdin); //清空输入缓冲
		//while (getchar() != '\n');
		x = a - 'A';
		y = b - 'A';
		if(x >=0 && x <= row-1 && y >= 0 && y <= column-1)
        {
			if (state[x][y])
                {
                    printf("该位置已经有棋子了，请下别的位置:");
                    /*返回输入循环*/
                    continue;
				}
			else
			{
				state[x][y] = order;

				/*保存双方落棋子位置在全局数组中*/
				if(order == 1)
                    {
                        fallen[x][y] = 1;
                    }
				else if(order == 2)
                    {
                        fallen[x][y] = 2;
                    }
                /*退出输入循环*/
				break;
            }
		}
		else
        {
			printf("非法输入，请重新输入:");
            /*返回输入循环*/
			continue;
		}
	}
}
