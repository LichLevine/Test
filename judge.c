#include <stdio.h>
#include <stdlib.h>
#include "chessmap.h"

extern fallen[ROW][COLUMN];
extern End;

/*�ж���Ϸʤ��*/
void gamejudge(int order)
{
    /*����������Ϸ��ʤ����1Ϊ�ڷ���2Ϊ�׷�*/
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
        }
    }
    if(judgement == 1)
    {
            printf("�ڷ�ʤ����\n");
            End = 1;

    }
    else if(judgement == 2)
    {
            printf("�׷�ʤ����\n");
            End = 1;
    }

}
