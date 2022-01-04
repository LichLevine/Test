#include <stdio.h>
#include <stdlib.h>
#include "chessmap.h"

/*����ȫ�����鱣��ڰ�˫�������*/
extern fallen[ROW][COLUMN];

void playermove(int **state, int row, int column, int order)
{
	int x, y;
	char a, b;
	char str[100];
	sprintf(str, "���%d-%s��", order, order==1? "�ڷ�" : "�׷�");
	printf("%s����H��A��,������HA:\n", str);
	while (1)
    {
        fflush(stdin); //������뻺��
		scanf("%c%c",&a,&b);
		x = a - 'A';
		y = b - 'A';
		if(x >=0 && x <= row-1 && y >= 0 && y <= column-1)
        {
			if (state[x][y])
                {
                    printf("��λ���Ѿ��������ˣ����±��λ��:");
                    /*��������ѭ��*/
                    continue;
				}
			else
			{
				state[x][y] = order;

				/*����˫��������λ����ȫ��������*/
				if(order == 1)
                    {
                        fallen[x][y] = 1;
                    }
				else if(order == 2)
                    {
                        fallen[x][y] = 2;
                    }
                /*�˳�����ѭ��*/
				break;
            }
		}
		else
        {
			printf("�Ƿ����룬����������:");
            /*��������ѭ��*/
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
        fflush(stdin); //������뻺��
        if(order == 1)
        {
            printf("����ߣ�(��H��A��,������HA):\n");
            scanf("%c%c",&a,&b);
            x = a - 'A';
            y = b - 'A';
            if(x >=0 && x <= row-1 && y >= 0 && y <= column-1)
            {
                if (state[x][y])
                    {
                        printf("��λ���Ѿ��������ˣ����±��λ��:");
                        /*��������ѭ��*/
                        continue;
                    }
                else
                {
                    state[x][y] = order;

                    /*����˫��������λ����ȫ��������*/
                    if(order == 1)
                        {
                            fallen[x][y] = 1;
                        }
                    /*�˳�����ѭ��*/
                    break;
                }
            }
            else
            {
                printf("�Ƿ����룬����������:\n");
                /*��������ѭ��*/
                continue;
            }
        }
        if(order == 2)
        {
            fflush(stdin); //������뻺��
            /*�������������д��ĸλ��*/
            srand((unsigned)time( NULL ));
            AI_x = 'A' + rand() % 26;
            AI_y = 'A' + rand() % 26;

            /*�����λ��ת�����������*/
            ai_x = AI_x - 'A';
            ai_y = AI_y - 'A';

            if(ai_x >=0 && ai_x <= row-1 && ai_y >= 0 && ai_y <= column-1)
            {
                if (state[ai_x][ai_y])
                {
                    printf("��λ���Ѿ��������ˣ����±��λ��:");
                    /*��������ѭ��*/
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
