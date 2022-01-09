#include <stdio.h>
#include <stdlib.h>
#include "chessmap.h"

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
        fflush(stdin); //清空输入缓冲
		scanf("%c%c",&a,&b);
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


void AImove(int **state, int row, int column, int order)
{
    int x, y;
    int ai_x, ai_y;
    char AI_x, AI_y;
	char a, b;
	char str[100];
    while (1)
    {
        fflush(stdin); //清空输入缓冲
        if(order == 1)
        {
            printf("玩家走：(如H行A列,则输入HA):\n");
            scanf("%c%c",&a,&b);
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
                    /*退出输入循环*/
                    break;
                }
            }
            else
            {
                printf("非法输入，请重新输入:\n");
                /*返回输入循环*/
                continue;
            }
        }
        if(order == 2)
        {
            fflush(stdin); //清空输入缓冲
            /*随机生成两个大写字母位置*/
            srand((unsigned)time( NULL ));
            AI_x = 'A' + rand() % 26;
            AI_y = 'A' + rand() % 26;

            /*将随机位置转换成数组序号*/
            ai_x = AI_x - 'A';
            ai_y = AI_y - 'A';

            if(ai_x >=0 && ai_x <= row-1 && ai_y >= 0 && ai_y <= column-1)
            {
                if (state[ai_x][ai_y])
                {
                    printf("该位置已经有棋子了，请下别的位置:");
                    /*返回输入循环*/
                    continue;
                }
                else
                {
                    printf("Random Position:%d,%d",ai_x,ai_y);
                    state[ai_x][ai_y] = order;
                    fallen[x][y] = 2;
                    break;
                }
            }
            else
            {
                continue;
            }
        }
    }
}
