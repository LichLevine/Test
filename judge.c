#include <stdio.h>
#include <stdlib.h>
#include "chessmap.h"

extern fallen[ROW][COLUMN];
extern End;
extern Timeflag;

/*判断游戏胜负*/
void gamejudge(int order)
{
    /*变量代表游戏方胜利，1为黑方获胜，2为白方获胜，3为平局*/
    int judgement = 0;

    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COLUMN;j++)
        {
            //黑方胜利方式
            //行获胜
            if(    fallen[i][j] == 1
                && fallen[i][j + 1] == 1
				&& fallen[i][j + 2] == 1
				&& fallen[i][j + 3] == 1
				&& fallen[i][j + 4] == 1)
				{
                    judgement = 1;
				}
            //列获胜
            else if( fallen[i][j] == 1
                && fallen[i + 1][j] == 1
				&& fallen[i + 2][j] == 1
				&& fallen[i + 3][j] == 1
				&& fallen[i + 4][j] == 1)
				{
				    judgement = 1;
				}
            //主对角线获胜
            else if(fallen[i][j] == 1
                && fallen[i + 1][j + 1] == 1
				&& fallen[i + 2][j + 2] == 1
				&& fallen[i + 3][j + 3] == 1
				&& fallen[i + 4][j + 4] == 1)
				{
				    judgement = 1;
				}
             //副对角线获胜
             else if(fallen[i][j] == 1
                && fallen[i + 1][j - 1] == 1
				&& fallen[i + 2][j - 2] == 1
				&& fallen[i + 3][j - 3] == 1
				&& fallen[i + 4][j - 4] == 1)
				{
				    judgement = 1;
				}

            //白方胜利方式
            //行获胜
            if(    fallen[i][j] == 2
                && fallen[i][j + 1] == 2
				&& fallen[i][j + 2] == 2
				&& fallen[i][j + 3] == 2
				&& fallen[i][j + 4] == 2)
				{
                    judgement = 2;
				}
            //列获胜
            else if( fallen[i][j] == 2
                && fallen[i + 1][j] == 2
				&& fallen[i + 2][j] == 2
				&& fallen[i + 3][j] == 2
				&& fallen[i + 4][j] == 2)
				{
				    judgement = 2;
				}
            //主对角线获胜
            else if(fallen[i][j] == 2
                && fallen[i + 1][j + 1] == 2
				&& fallen[i + 2][j + 2] == 2
				&& fallen[i + 3][j + 3] == 2
				&& fallen[i + 4][j + 4] == 2)
				{
				    judgement = 2;
				}
            //副对角线获胜
            else if(fallen[i][j] == 2
                && fallen[i + 1][j - 1] == 2
				&& fallen[i + 2][j - 2] == 2
				&& fallen[i + 3][j - 3] == 2
				&& fallen[i + 4][j - 4] == 2)
				{
				    judgement = 2;
				}

            //平局
            else if(fallen[i][j] == ' ')
                {
                    judgement = 3;
                }

        }
    }
    if(judgement == 1)
    {
        printf("*********************\n");
        printf("*****!黑方胜利！*****\n");
        printf("*********************\n");
        End = 1;
        Timeflag = 2;

    }
    else if(judgement == 2)
    {
        printf("*********************\n");
        printf("*****!白方胜利！*****\n");
        printf("*********************\n");
        End = 1;
        Timeflag = 2;
    }
    else if(judgement == 3)
    {
        printf("****************\n");
        printf("*****!平局！****\n");
        printf("****************\n");
        End = 1;
        Timeflag = 2;
    }
}
