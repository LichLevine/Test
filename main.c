#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "chessmap.h"
#include "display.h"
#include "move.h"
#include "TimeCount.h"
#include "Mode.h"


//����ȫ�������¼���ӺͰ�����ŵ�
int fallen[ROW][COLUMN];

//����ȫ�����ͱ�����¼��Ϸ����������
int End = 0;

//����ȫ���ַ��ͱ�����¼��Ϸģʽѡ��
char ModeNumber;

//����ȫ�����ͱ�����¼ʱ��ˢ�µ�
int Timeflag = 1;

int main()
{
    /*�Ը��������г�ʼ��*/
    int i,j;
    int **board;
    int order=0;

    /*�����̷����ڴ�ռ�*/
    board = malloc(sizeof(int*)*ROW);
    for(i = 0; i < ROW; i++)
        board[i] = malloc(sizeof(int)*COLUMN);

    /*��ʼ����������*/
    for(i = 0; i < ROW; i++)
        for(j = 0;j < COLUMN; j++)
            board[i][j] = 0;

    /*������Ϸģʽѡ�����*/
    ChooseMode();

    /*���ö��̴߳���һ��������*/
    pthread_t tid1;
    pthread_create(&tid1,NULL,*Countdown,NULL);

    /*���˶�սģʽ*/
    if(ModeNumber == '1')
    {
        /*��������*/
        draw(board, ROW, COLUMN);

        while(1)
        {

            /*orderΪ˳���,����1Ϊ��ɫ����ż��2Ϊ��ɫ��*/
            order = order%2+1;
            Timeflag = 1;
            /*���ֵ��׷�����ǰ���ԶԺڷ�������н�������*/
            if(order == 2)
            {
                fflush(stdin); //������뻺��
                printf("�׷��Ƿ��ֺڷ�Υ������ԭ����������Y,��������N��\n");
                /*����׷����ɣ�����Ҫ����'Y'�ַ�������һ���ж�*/
                if(getchar() == 'Y')
                {
                    Question();
                }
                /*����׷������ɣ�����Ҫ����'N'�ַ��������ж�*/
                if(getchar() == 'N')
                {
                    ;
                }
            }

            /*ÿһ�������������ָ��*/
            playermove(board, ROW, COLUMN,order);

            /*ˢ������*/
            draw(board, ROW, COLUMN);

            /*�ж���Ӯ*/
            gamejudge(order);
            if(End == 1)
            {
               printf("��Ϸ�������밴������˳�\n");
               break; /*�˳����˶�սģʽѭ��*/
            }
        }
    }

    /*�˻���սģʽ*/
    else if(ModeNumber == '2')
    {

        /*��������*/
        draw(board, ROW, COLUMN);

        while(1)
        {

            /*orderΪ˳���,����1Ϊ��ɫ����ż��2Ϊ��ɫ��*/
            order = order%2+1;
            Timeflag = 1;
            /*ÿһ�������������ָ��*/
            AImove(board, ROW, COLUMN,order);

            /*ˢ������*/
            draw(board, ROW, COLUMN);

            /*�ж���Ӯ*/
            gamejudge(order);
            if(End == 1)
            {
               printf("��Ϸ�������밴������˳�\n");
               break; /*�˳��˻���սģʽѭ��*/
            }
        }
    }
    else
    {
        printf("************************\n");
        printf("*�Ƿ����룬�����˳���Ϸ*\n");
        printf("************************\n");
    }

    system("pause");
    /*�ͷţ�����գ�������ռ�ڴ�*/
    for(i = 0; i < ROW; i++)
        free(board[i]);
    free(board);
    return 0;
}

