#include <stdio.h>
#include <stdlib.h>
#include "chessmap.h"

extern fallen[ROW][COLUMN];
extern End;
extern Timeflag;

/*白方玩家质疑黑方是否违反禁手原则*/
void Question()
{
    /*代表黑方存在禁手原则的结果，1为三三禁手，2为四四禁手，3为长连禁手*/
    int Q;

    /*保存白方提出的禁手原则质疑*/
    int Forbidden;

    printf("白方提出质疑！\n");
    printf("请按照首字母指出违反的禁手原则：\n");
    printf("1:三三禁手\n");
    printf("2:四四禁手\n");
    printf("3:长连禁手\n");
    printf("你的输入是：\n");

    /*取出白方玩家提出禁手原则质疑的种类*/
    scanf("%d",&Forbidden);
    printf("Get Forbidden value is %d\n",Forbidden);

    /*判断禁手原则质疑是否成立*/
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COLUMN;j++)
        {
            //黑方禁手原则
            //三三禁手(1)图1.3
            if(    fallen[i][j] == 1
                && fallen[i - 1][j - 1] == 1
				&& fallen[i + 1][j - 1] == 1
				&& fallen[i - 1][j + 1] == 1
				&& fallen[i + 1][j + 1] == 1)
				{
                    Q = 1;
				}

            //三三禁手（2）图1.2
            else if( fallen[i][j] == 1
                && fallen[i][j - 1] == 1
				&& fallen[i][j - 2] == 1
				&& fallen[i + 2][j] == 1
				&& fallen[i + 3][j] == 1)
				{
				    Q = 1;
				}
             else if( fallen[i][j] == 1
                && fallen[i][j - 1] == 1
				&& fallen[i][j - 2] == 1
				&& fallen[i - 2][j] == 1
				&& fallen[i - 3][j] == 1)
				{
				    Q = 1;
				}

             else if( fallen[i][j] == 1
                && fallen[i][j + 1] == 1
				&& fallen[i][j + 2] == 1
				&& fallen[i - 2][j] == 1
				&& fallen[i - 3][j] == 1)
				{
				    Q = 1;
				}
             else if( fallen[i][j] == 1
                && fallen[i][j + 1] == 1
				&& fallen[i][j + 2] == 1
				&& fallen[i - 2][j] == 1
				&& fallen[i - 3][j] == 1)
				{
				    Q = 1;
				}

            //四四禁手（1）图1.4
            else if( fallen[i][j] == 1
                && fallen[i + 1][j] == 1
				&& fallen[i + 2][j] == 1
				&& fallen[i + 3][j] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j - 2] == 1
				&& fallen[i][j - 3] == 1)
				{
				    Q = 2;
				}
            else if( fallen[i][j] == 1
                && fallen[i + 1][j] == 1
				&& fallen[i + 2][j] == 1
				&& fallen[i + 3][j] == 1
				&& fallen[i][j + 1] == 1
				&& fallen[i][j + 2] == 1
				&& fallen[i][j + 3] == 1)
				{
				    Q = 2;
				}
            else if( fallen[i][j] == 1
                && fallen[i - 1][j] == 1
				&& fallen[i - 2][j] == 1
				&& fallen[i - 3][j] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j - 2] == 1
				&& fallen[i][j - 3] == 1)
				{
				    Q = 2;
				}
            else if( fallen[i][j] == 1
                && fallen[i - 1][j] == 1
				&& fallen[i - 2][j] == 1
				&& fallen[i - 3][j] == 1
				&& fallen[i][j + 1] == 1
				&& fallen[i][j + 2] == 1
				&& fallen[i][j + 3] == 1)
				{
				    Q = 2;
				}

            //四四禁手（2）图1.5
            else if(fallen[i][j] == 1
                && fallen[i - 1][j] == 1
				&& fallen[i + 1][j] == 1
				&& fallen[i + 2][j] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j + 1] == 1
				&& fallen[i][j + 2] == 1)
				{
				    Q = 2;
				}
            else if(fallen[i][j] == 1
                && fallen[i - 1][j] == 1
				&& fallen[i + 1][j] == 1
				&& fallen[i + 2][j] == 1
				&& fallen[i][j + 1] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j - 2] == 1)
				{
				    Q = 2;
				}
            else if(fallen[i][j] == 1
                && fallen[i + 1][j] == 1
				&& fallen[i - 1][j] == 1
				&& fallen[i - 2][j] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j + 1] == 1
				&& fallen[i][j + 2] == 1)
				{
				    Q = 2;
				}
            else if(fallen[i][j] == 1
                && fallen[i + 1][j] == 1
				&& fallen[i - 1][j] == 1
				&& fallen[i - 2][j] == 1
				&& fallen[i][j + 1] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j - 2] == 1)
				{
				    Q = 2;
				}

            //四四禁手（3）图1.6
             else if(fallen[i][j] == 1
                && fallen[i][j - 3] == 1
				&& fallen[i][j - 2] == 1
				&& fallen[i][j + 1] == 1
				&& fallen[i][j + 3] == 1
				&& fallen[i][j + 4] == 1)
				{
				    Q = 2;
				}
             else if(fallen[i][j] == 1
                && fallen[i][j - 4] == 1
				&& fallen[i][j - 3] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j + 2] == 1
				&& fallen[i][j + 3] == 1)
				{
				    Q = 2;
				}
             else if(fallen[i][j] == 1
                && fallen[i - 3][j] == 1
				&& fallen[i - 2][j] == 1
				&& fallen[i + 1][j] == 1
				&& fallen[i + 3][j] == 1
				&& fallen[i + 4][j] == 1)
				{
				    Q = 2;
				}
             else if(fallen[i][j] == 1
                && fallen[i - 4][j] == 1
				&& fallen[i - 3][j] == 1
				&& fallen[i - 1][j] == 1
				&& fallen[i + 2][j] == 1
				&& fallen[i + 3][j] == 1)
				{
				    Q = 2;
				}

             //四四禁手（4）图1.7
             else if(fallen[i][j] == 1
                && fallen[i - 3][j] == 1
				&& fallen[i - 1][j] == 1
				&& fallen[i + 1][j] == 1
				&& fallen[i + 3][j] == 1)
				{
				    Q = 2;
				}
             else if(fallen[i][j] == 1
                && fallen[i][j - 3] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j + 1] == 1
				&& fallen[i][j + 3] == 1)
				{
				    Q = 2;
				}

             //长连禁手（1）图1.9
             else if(fallen[i][j] == 1
                && fallen[i][j - 2] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j + 1] == 1
                && fallen[i][j + 2] == 1
				&& fallen[i][j + 3] == 1)
				{
				    Q = 3;
				}
             else if(fallen[i][j] == 1
                && fallen[i][j - 3] == 1
                && fallen[i][j - 2] == 1
				&& fallen[i][j - 1] == 1
				&& fallen[i][j + 1] == 1
                && fallen[i][j + 2] == 1)
				{
				    Q = 3;
				}
             else if(fallen[i][j] == 1
                && fallen[i - 2][j] == 1
                && fallen[i - 1][j] == 1
				&& fallen[i + 1][j] == 1
				&& fallen[i + 2][j] == 1
                && fallen[i + 3][j] == 1)
				{
				    Q = 3;
				}
             else if(fallen[i][j] == 1
                && fallen[i - 3][j] == 1
                && fallen[i - 2][j] == 1
				&& fallen[i - 1][j] == 1
				&& fallen[i + 1][j] == 1
                && fallen[i + 2][j] == 1)
				{
				    Q = 3;
				}
        }
    }

    /*根据以上判断条件输出结果*/
    if(Q == 1 && Forbidden == 1)
        {
            printf("黑方违反三三禁手原则！\n");
            printf("白方质疑成功，白方获胜！\n");
            End = 1;
            Timeflag = 2;
        }
    else if(Q == 2 && Forbidden == 2)
        {
            printf("黑方违反四四禁手原则！\n");
            printf("白方质疑成功，白方获胜！\n");
            End = 1;
            Timeflag = 2;
        }
    else if(Q == 3 && Forbidden == 3)
        {
            printf("黑方违反长连禁手原则！\n");
            printf("白方质疑成功，白方获胜！\n");
            End = 1;
            Timeflag = 2;
        }
    else
        {
            printf("白方质疑错误！\n");
        }
}
