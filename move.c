#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "chessmap.h"
#include "TimeCount.h"

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
		scanf("%c%c",&a,&b);
		fflush(stdin); //������뻺��
		//while (getchar() != '\n');
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
