#include "game.h"

int Headmenu()
{
	printf("---------------------------------------------\n");
	printf("------------      ɨ��      -----------------\n");
	printf("---------------------------------------------\n");
	printf("-1.��ʼ��Ϸ   -------------------------------\n");
	printf("-0.�˳���Ϸ   -------------------------------\n");
	printf("---------------------------------------------\n");
	printf("--------------------------------BY:codesg----\n");
	printf("������:\n");
	return Getenter();
}
void Format(char arr[ROWS][COLS], int row, int col, char set)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{ 
			arr[i][j] = set;
		}
	}
}

void Displayboard(char arr[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

int Getenter()
{
	int enter = 0;
	int err = 0;
	char ch = 0;
	while (1)
	{
		if (err = scanf("%d", &enter) == 0)
		{
			printf("(��_��)��\n");
			while ((ch = getchar()) != EOF && ch != '\n');
		}
		else if (enter == 1 || enter == 0)
		{
			break;
		}
		else
		{
			printf("�����������������\n");
		}
	}
	return enter;
}

void Getxy(int row,int col,int xy[])
{
	char ch = 0;
	int err = 0;
	printf("����������\n");
	while (1)
	{
		if (err = scanf("%d %d",&xy[0],&xy[1]) == 0)
		{
			printf("(��_��)��\n");
			while ((ch = getchar()) != EOF && ch != '\n');
		}
		else if (xy[0]>=1&&xy[0]<=col&&xy[1]>=1&&xy[1]<=col)
		{
			break;
		}
		else
		{
			printf("��������ȷ������\n");
		}
	}
}
void Setmine(char mine[ROWS][COLS], int row, int col,int nume)
{
	int x = 0;
	int y = 0;
	int count = 1;
	while (count<=nume)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}

}

void showmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (show[i][j] == '*'&& mine[i][j] == '1')
			{
				show[i][j] = '#';
			}
		}
	}
}

//ʵ�ֱ�����Χ���ֲ���չ
void Infect(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int row,int col,int* count)
{
	char num = 0;
	if (mine[x][y] == '0')
	{
		num=mine[x - 1][y] + mine[x][y] + mine[x + 1][y] +
			mine[x - 1][y - 1] + mine[x - 1][y + 1] + mine[x][y - 1] +
			mine[x][y + 1] + mine[x + 1][y + 1] + mine[x + 1][y - 1] - '0' * 8;
		if (num == '0')
			show[x][y] = ' ';
		else
			show[x][y] = num;
		(*count)++;
	}
	if (show[x][y] == ' ' )
	{
		if (show[x - 1][y] == '*'&&x-1>=1)
			Infect(mine, show, x - 1, y,row,col, count);
		if (show[x -1][y+1] == '*' && x - 1 >= 1&&y+1<= col)
			Infect(mine, show, x-1 , y+1, row, col, count);
		if (show[x ][y+1] == '*' && y + 1 <= col)
			Infect(mine, show, x, y+1, row, col, count);
		if (show[x +1][y+1] == '*'&&x+1<= row && y + 1 <= col)
			Infect(mine, show, x + 1, y+1, row, col, count);
		if (show[x +1][y] == '*' && x + 1 <= row)
			Infect(mine, show, x+1 , y, row, col, count);
		if (show[x+1 ][y-1] == '*' && x + 1 <= row && y - 1 >= 1)
			Infect(mine, show, x + 1, y-1, row, col, count);
		if (show[x ][y-1] == '*'&&y-1>=1)
			Infect(mine, show, x , y-1, row, col, count);
		if (show[x - 1][y - 1] == '*' && x - 1 >= 1 && y - 1 >= 1)
			Infect(mine, show, x - 1, y - 1, row, col, count);
	}
}


void mygame(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	//���˵�
	int xy[2] = {0};
	int win = row * col - DIFFICULTY_1;
	if (Headmenu() ==0)
	{
		return;
	}
	
	//��ʼ��
	while (1)
	{
		int count = 0;
		xy[0] = 0;
		xy[1] = 0;
		system("cls");
		//���̳�ʼ��
		Format(mine, ROWS, COLS, '0');
		Format(show, ROWS, COLS, '*');
		//����
		Setmine(mine, ROW, COL, DIFFICULTY_1);
		while (1)
		{			
			system("cls");
			Displayboard(show, row, col);
			Displayboard(mine, row, col); //���Ե���
			if (mine[xy[0]][xy[1]] == '1' || count == win)
			{
				system("cls");
				showmine(mine, show, row, col);
				Displayboard(show, row, col);
				if (count == win)
					printf("��Ϸʤ��\n");
				else
					printf("�ȵ�ը��GAMEOVRE\n");						
				printf("�Ƿ������1.����0.�˳�\n");
				if (Getenter() == 0)
					return;
				else
					break;
			}
			//��ȡ������������
			Getxy(ROW, COL, xy);
			//������Χ���ֲ���չ
			Infect(mine, show, xy[0], xy[1], row, col, &count);
		}
	}
}