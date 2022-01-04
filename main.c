#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "chessmap.h"
#include "display.h"
#include "move.h"
#include "TimeCount.h"
#include "Mode.h"


//利用全局数组记录黑子和白子落脚点
int fallen[ROW][COLUMN];

//利用全局整型变量记录游戏结束的条件
int End = 0;

//利用全局字符型变量记录游戏模式选择
char ModeNumber;

//利用全局整型变量记录时间刷新点
int Timeflag = 1;

int main()
{
    /*对各变量进行初始化*/
    int i,j;
    int **board;
    int order=0;

    /*给棋盘分配内存空间*/
    board = malloc(sizeof(int*)*ROW);
    for(i = 0; i < ROW; i++)
        board[i] = malloc(sizeof(int)*COLUMN);

    /*初始化棋盘数组*/
    for(i = 0; i < ROW; i++)
        for(j = 0;j < COLUMN; j++)
            board[i][j] = 0;

    /*进入游戏模式选择界面*/
    ChooseMode();

    /*利用多线程创造一个倒数器*/
    pthread_t tid1;
    pthread_create(&tid1,NULL,*Countdown,NULL);

    /*人人对战模式*/
    if(ModeNumber == '1')
    {
        /*画出棋盘*/
        draw(board, ROW, COLUMN);

        while(1)
        {

            /*order为顺序号,奇数1为黑色方，偶数2为白色方*/
            order = order%2+1;
            Timeflag = 1;
            /*当轮到白方下棋前可以对黑方下棋进行禁手质疑*/
            if(order == 2)
            {
                fflush(stdin); //清空输入缓冲
                printf("白方是否发现黑方违反禁手原则？有则输入Y,否则输入N。\n");
                /*如果白方质疑，则需要输入'Y'字符进行下一步判断*/
                if(getchar() == 'Y')
                {
                    Question();
                }
                /*如果白方不质疑，则需要输入'N'字符不进行判断*/
                if(getchar() == 'N')
                {
                    ;
                }
            }

            /*每一方进行下棋操作指令*/
            playermove(board, ROW, COLUMN,order);

            /*刷新棋盘*/
            draw(board, ROW, COLUMN);

            /*判断输赢*/
            gamejudge(order);
            if(End == 1)
            {
               printf("游戏结束，请按任意键退出\n");
               break; /*退出人人对战模式循环*/
            }
        }
    }

    /*人机对战模式*/
    else if(ModeNumber == '2')
    {

        /*画出棋盘*/
        draw(board, ROW, COLUMN);

        while(1)
        {

            /*order为顺序号,奇数1为黑色方，偶数2为白色方*/
            order = order%2+1;
            Timeflag = 1;
            /*每一方进行下棋操作指令*/
            AImove(board, ROW, COLUMN,order);

            /*刷新棋盘*/
            draw(board, ROW, COLUMN);

            /*判断输赢*/
            gamejudge(order);
            if(End == 1)
            {
               printf("游戏结束，请按任意键退出\n");
               break; /*退出人机对战模式循环*/
            }
        }
    }
    else
    {
        printf("************************\n");
        printf("*非法输入，即将退出游戏*\n");
        printf("************************\n");
    }

    system("pause");
    /*释放（或回收）棋盘所占内存*/
    for(i = 0; i < ROW; i++)
        free(board[i]);
    free(board);
    return 0;
}

