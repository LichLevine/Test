#include <stdio.h>
#include <stdlib.h>
#include "chessmap.h"

extern fallen[ROW][COLUMN];
extern End;


/*�׷�������ɺڷ��Ƿ�Υ������ԭ��*/
void Question()
{
    /*����ڷ����ڽ���ԭ��Ľ����1Ϊ�������֣�2Ϊ���Ľ��֣�3Ϊ��������*/
    int Q;

    /*����׷�����Ľ���ԭ������*/
    int Forbidden;

    printf("�׷�������ɣ�\n");
    printf("�밴������ĸָ��Υ���Ľ���ԭ��\n");
    printf("1:��������\n");
    printf("2:���Ľ���\n");
    printf("3:��������\n");
    printf("��������ǣ�\n");

    /*ȡ���׷�����������ԭ�����ɵ�����*/
    scanf("%d",&Forbidden);
    printf("Get Forbidden value is %d\n",Forbidden);

    /*�жϽ���ԭ�������Ƿ����*/
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COLUMN;j++)
        {
            //�ڷ�����ԭ��
            //��������(1)ͼ1.3
            if(    fallen[i][j] == 1
                && fallen[i - 1][j - 1] == 1
				&& fallen[i + 1][j - 1] == 1
				&& fallen[i - 1][j + 1] == 1
				&& fallen[i + 1][j + 1] == 1)
				{
                    Q = 1;
				}

            //�������֣�2��ͼ1.2
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

            //���Ľ��֣�1��ͼ1.4
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

            //���Ľ��֣�2��ͼ1.5
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

            //���Ľ��֣�3��ͼ1.6
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

             //���Ľ��֣�4��ͼ1.7
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

             //�������֣�1��ͼ1.9
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

    /*���������ж�����������*/
    if(Q == 1 && Forbidden == 1)
        {
            printf("�ڷ�Υ����������ԭ��\n");
            printf("�׷����ɳɹ����׷���ʤ��\n");
            End = 1;
        }
    else if(Q == 2 && Forbidden == 2)
        {
            printf("�ڷ�Υ�����Ľ���ԭ��\n");
            printf("�׷����ɳɹ����׷���ʤ��\n");
            End = 1;
        }
    else if(Q == 3 && Forbidden == 3)
        {
            printf("�ڷ�Υ����������ԭ��\n");
            printf("�׷����ɳɹ����׷���ʤ��\n");
            End = 1;
        }
    else
        {
            printf("�׷����ɴ���\n");
        }
}
