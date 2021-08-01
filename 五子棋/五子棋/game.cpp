#include "game.h"


int GameMenu()
{
	system("cls");
	printf("������������������������������������������������������\n");
	printf("|**********************������************************|\n");
	printf("|****************************************************|\n");
	printf("|*1.��ʼ��Ϸ*****************************************|\n");
	printf("|*0.�˳���Ϸ*****************************************|\n");
	printf("|****************************************************|\n");
	printf("|*******************************************by:codesg|\n");
	printf("������������������������������������������������������\n\n");
	int Option = 0;
	char ch = 0;
	while (1)
	{
		int err = scanf("%d", &Option);
		if (err == 0)
		{
			//����������˳�
			while ((ch = getchar()) != EOF && ch != '\n');
			printf("(��_��)��\n");
		}
		else if (Option == 1)
		{
			//����1��ʼ��Ϸ
			break;
		}
		else if (Option == 0)
		{
			//����0�˳���Ϸ
			printf("�ݰ�\n");
			return 0;
		}
		else
		{
			printf("�������,����������\n");
		}	
	}
	return 1;
}

void ChessBoard(char chessman[ROW][COLUMN],int row, int column)
{

	for (int i = 0; i < column; i++)
	{
		printf("____");
	}
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (chessman[i][j] =='*')
			{
				printf("\033[31m\033[1m %c \033[0m" ,chessman[i][j]);
			}
			else if (chessman[i][j] == '#')
			{
				printf("\033[32m\033[1m %c \033[0m", chessman[i][j]);
			}
			else
			{
				printf(" %c ", chessman[i][j]);
			}
			printf("|");
		}
		printf("\n");
		for (int j = 0; j < column; j++)
		{
			printf("___|");
		}
		printf("\n");
	}
	printf("����������(x y):\n");
}

void SetplayXY(char chessman[ROW][COLUMN],int xy[], int row, int column)
{
	char ch = 0;
	while (1)
	{
		int err = scanf("%d %d", &xy[0], &xy[1]);
		if (err == 0)
		{ 
			while ((ch = getchar()) != EOF && ch != '\n');
			printf("����������\n");
		}
		else if (xy[0] >= 1 && xy[0] <= row && xy[1] >= 1 && xy[1] <= column)
		{
			if (chessman[xy[0]-1][xy[1]-1] == ' ')
			{
				chessman[xy[0]-1][xy[1]-1] = '*';
				xy[0]--;
				xy[1]--;
				break;
			}
			printf("������������\n");
		}
		else 
		{
			printf("��������ȷ������\n");
		}
		
	}

}

void SetaiXY(char chessman[ROW][COLUMN],int xy[] ,int row, int column)
{
	while (1)
	{
		xy[0] = rand() % 10;
		xy[1] = rand() % 10;
		if (xy[0] >= 0 && xy[0] < row && xy[1] >= 0 && xy[1] < column)
		{
			if (chessman[xy[0]][xy[1]] == ' ')
			{
				chessman[xy[0]][xy[1]] = '#';
				break;
			}
		}
	}
	
}

int Referee(char chessman[ROW][COLUMN], int xy[], int row, int column)
{
	//1,���ʤ 2,����ʤ 3,ƽ�� 4,����
	//�жϺ������Ƿ�5��
	char che = chessman[xy[0]][xy[1]];
	int x = xy[0];
	int y = xy[1];
	int countx = 1;
	int county = 1;


	if (che == '*' || che == '#')
	{
		//����
		for (int i = 1; i < 5 && x-i>=0; i++)
		{
			if (chessman[x - i][y] == che)
				countx++;
			else
				break;
		}
		for (int i = 1; i < 5 && x+i<row; i++)
		{
			if (chessman[x + i][y] == che)
				countx++;
			else
				break;
		}
		for (int i = 1; i < 5&& y-i>=0; i++)
		{
			if (chessman[x][y-i] == che)
				county++;
			else
				break;
		}
		for (int i = 1; i < 5 && y+i< column; i++)
		{
			if (chessman[x][y+i] == che)
				county++;
			else
				break;
		}
		//б��
		if (county < 5 && countx < 5)
		{
			county = 1;
			countx = 1;
			for (int i = 1; i < 5 && x - i >= 0 && y - i >= 0; i++)
			{
				if (chessman[x - i][y - i] == che)
					countx++;
				else
					break;
			}
			for (int i = 1; i < 5&& x+i<row && y + i < column; i++)
			{
				if (chessman[x+i][y + i] == che)
					countx++;
				else
					break;
			}
			for (int i = 1; i < 5 && x - i >= 0 && y + i < column; i++)
			{
				if (chessman[x-i][y + i] == che)
					county++;
				else
					break;
			}
			for (int i = 1; i < 5 && x + i < row && y - i >= 0; i++)
			{
				if (chessman[x+i][y - i] == che)
					county++;
				else
					break;
			}
		}
		if (countx >= 5 || county >= 5)
		{
			if (che == '*')
				printf("���ʤ\n");
			else
				printf("����ʤ\n");
			printf("�Ƿ������Ϸ��1.���� 2.�˳�\n");
			while (1)
			{
				char ch = 0;
				int err = 0;
				if (scanf("%d", &err) == 0)
				{
					while ((ch = getchar()) != EOF && ch != '\n');
					printf("(��_��)��\n");
				}
				else if (err == 1)
				{
					return 1;
				}
				else if (err == 2)
				{
					return 2;
				}
				else
				{
					printf("��������ȷ������\n");
				}
			}
		}
	}
	
	return 0;
}

void GameMain()
{
	int xy[2] = { 0 };//���ӵ�
	int decide = 0;
	int restart = 1;//���¿�ʼ
	int order = 0;
	srand((unsigned int)time(NULL));//�����������
	char chessman[ROW][COLUMN] = { 0 };	

	while (1)
	{
		if (restart == 1)
		{
			order = 0;
			memset(chessman, ' ', ROW * COLUMN); //��ʼ����������Ϊ�ո�	
			if (GameMenu() == 0)//��ʼ�˵�
			{
				return;
			}

		}	
		restart = 0;//��ʼ����� ��ʼ����
		system("cls");
		ChessBoard(chessman, ROW, COLUMN);//������
		decide = Referee(chessman, xy, ROW, COLUMN);
		if (decide == 1)
		{
			restart = 1; //���¿�ʼ��ʼ��
			continue;
		}
		else if (decide == 2)
		{
			return;
		}
		//���order == 0 ������� order == 1������
		if (order= !order)
		{	
			SetplayXY(chessman, xy,ROW, COLUMN);	//�����������
		}
		else
		{
			SetaiXY(chessman, xy, ROW, COLUMN);//����AI����
			Sleep(500);
		}
		//���� 1.������Ϸ2.�˳���Ϸ

	}
}