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

//����ȫ�ֱ�����¼��Ϸ����������
int End = 0;
int ModeNumber = 0;

int main() {

    ChooseMode();

    /*���˶�սģʽ*/
    if(ModeNumber == 1)
    {
        /*�Ը��������г�ʼ��*/
        int i,j;
        int **board;
        int order=0;

        //pthread_t tid1;
        //pthread_create(&tid1,NULL,*Countdown,NULL);

        /*�����̷����ڴ�ռ�*/
        board = malloc(sizeof(int*)*ROW);
        for(i = 0; i < ROW; i++)
            board[i] = malloc(sizeof(int)*COLUMN);

        /*��ʼ����������*/
        for(i = 0; i < ROW; i++)
            for(j = 0;j < COLUMN; j++)
                board[i][j] = 0;

        /*��������*/
        draw(board, ROW, COLUMN);

        while(1)
        {

            /*orderΪ˳���,����1Ϊ��ɫ����ż��2Ϊ��ɫ��*/
            order = order%2+1;
            /*���ֵ��׷�����ǰ���ԶԺڷ�������н�������*/
            if(order == 2)
            {
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

        system("pause");

        /*�ͷţ�����գ�������ռ�ڴ�*/
        for(i = 0; i < ROW; i++)
            free(board[i]);
        free(board);
    }
    return 0;
}

