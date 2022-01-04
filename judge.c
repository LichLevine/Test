#include <stdio.h>
#include <stdlib.h>
#include "chessmap.h"

extern fallen[ROW][COLUMN];
extern End;
extern Timeflag;

/*�ж���Ϸʤ��*/
void gamejudge(int order)
{
    /*����������Ϸ��ʤ����1Ϊ�ڷ���ʤ��2Ϊ�׷���ʤ��3Ϊƽ��*/
    int judgement = 0;

    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COLUMN;j++)
        {
            //�ڷ�ʤ����ʽ
            //�л�ʤ
            if(    fallen[i][j] == 1
                && fallen[i][j + 1] == 1
				&& fallen[i][j + 2] == 1
				&& fallen[i][j + 3] == 1
				&& fallen[i][j + 4] == 1)
				{
                    judgement = 1;
				}
            //�л�ʤ
            else if( fallen[i][j] == 1
                && fallen[i + 1][j] == 1
				&& fallen[i + 2][j] == 1
				&& fallen[i + 3][j] == 1
				&& fallen[i + 4][j] == 1)
				{
				    judgement = 1;
				}
            //���Խ��߻�ʤ
            else if(fallen[i][j] == 1
                && fallen[i + 1][j + 1] == 1
				&& fallen[i + 2][j + 2] == 1
				&& fallen[i + 3][j + 3] == 1
				&& fallen[i + 4][j + 4] == 1)
				{
				    judgement = 1;
				}
             //���Խ��߻�ʤ
             else if(fallen[i][j] == 1
                && fallen[i + 1][j - 1] == 1
				&& fallen[i + 2][j - 2] == 1
				&& fallen[i + 3][j - 3] == 1
				&& fallen[i + 4][j - 4] == 1)
				{
				    judgement = 1;
				}

            //�׷�ʤ����ʽ
            //�л�ʤ
            if(    fallen[i][j] == 2
                && fallen[i][j + 1] == 2
				&& fallen[i][j + 2] == 2
				&& fallen[i][j + 3] == 2
				&& fallen[i][j + 4] == 2)
				{
                    judgement = 2;
				}
            //�л�ʤ
            else if( fallen[i][j] == 2
                && fallen[i + 1][j] == 2
				&& fallen[i + 2][j] == 2
				&& fallen[i + 3][j] == 2
				&& fallen[i + 4][j] == 2)
				{
				    judgement = 2;
				}
            //���Խ��߻�ʤ
            else if(fallen[i][j] == 2
                && fallen[i + 1][j + 1] == 2
				&& fallen[i + 2][j + 2] == 2
				&& fallen[i + 3][j + 3] == 2
				&& fallen[i + 4][j + 4] == 2)
				{
				    judgement = 2;
				}
            //���Խ��߻�ʤ
            else if(fallen[i][j] == 2
                && fallen[i + 1][j - 1] == 2
				&& fallen[i + 2][j - 2] == 2
				&& fallen[i + 3][j - 3] == 2
				&& fallen[i + 4][j - 4] == 2)
				{
				    judgement = 2;
				}

            //ƽ��
            else if(fallen[i][j] == ' ')
                {
                    judgement = 3;
                }

        }
    }
    if(judgement == 1)
    {
        printf("*********************\n");
        printf("*****!�ڷ�ʤ����*****\n");
        printf("*********************\n");
        End = 1;
        Timeflag = 2;

    }
    else if(judgement == 2)
    {
        printf("*********************\n");
        printf("*****!�׷�ʤ����*****\n");
        printf("*********************\n");
        End = 1;
        Timeflag = 2;
    }
    else if(judgement == 3)
    {
        printf("****************\n");
        printf("*****!ƽ�֣�****\n");
        printf("****************\n");
        End = 1;
        Timeflag = 2;
    }
}
