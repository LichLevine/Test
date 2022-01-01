#include <stdio.h>
#include <stdlib.h>

extern ModeNumber;

void ChooseMode()
{
    printf("请选择你的游戏模式!\n");
    printf("1.人人对战\n");
    printf("2.人机对战\n");
    printf("请输入你的选择：");
    scanf("%d",&ModeNumber);
}
