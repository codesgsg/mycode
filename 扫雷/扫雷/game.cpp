#include "game.h"

int Headmenu()
{
	printf("---------------------------------------------\n");
	printf("------------      扫雷      -----------------\n");
	printf("---------------------------------------------\n");
	printf("-1.开始游戏   -------------------------------\n");
	printf("-0.退出游戏   -------------------------------\n");
	printf("---------------------------------------------\n");
	printf("--------------------------------BY:codesg----\n");
	printf("请输入:\n");
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
			printf("(⊙_⊙)？\n");
			while ((ch = getchar()) != EOF && ch != '\n');
		}
		else if (enter == 1 || enter == 0)
		{
			break;
		}
		else
		{
			printf("输入错误请重新输入\n");
		}
	}
	return enter;
}

void Getxy(int row,int col,int xy[])
{
	char ch = 0;
	int err = 0;
	printf("请输入坐标\n");
	while (1)
	{
		if (err = scanf("%d %d",&xy[0],&xy[1]) == 0)
		{
			printf("(⊙_⊙)？\n");
			while ((ch = getchar()) != EOF && ch != '\n');
		}
		else if (xy[0]>=1&&xy[0]<=col&&xy[1]>=1&&xy[1]<=col)
		{
			break;
		}
		else
		{
			printf("请输入正确的坐标\n");
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

//实现遍历周围数字并扩展
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
	//主菜单
	int xy[2] = {0};
	int win = row * col - DIFFICULTY_1;
	if (Headmenu() ==0)
	{
		return;
	}
	
	//初始化
	while (1)
	{
		int count = 0;
		xy[0] = 0;
		xy[1] = 0;
		system("cls");
		//棋盘初始化
		Format(mine, ROWS, COLS, '0');
		Format(show, ROWS, COLS, '*');
		//埋雷
		Setmine(mine, ROW, COL, DIFFICULTY_1);
		while (1)
		{			
			system("cls");
			Displayboard(show, row, col);
			Displayboard(mine, row, col); //测试地雷
			if (mine[xy[0]][xy[1]] == '1' || count == win)
			{
				system("cls");
				showmine(mine, show, row, col);
				Displayboard(show, row, col);
				if (count == win)
					printf("游戏胜利\n");
				else
					printf("踩到炸弹GAMEOVRE\n");						
				printf("是否继续？1.继续0.退出\n");
				if (Getenter() == 0)
					return;
				else
					break;
			}
			//获取玩家输入的坐标
			Getxy(ROW, COL, xy);
			//遍历周围数字并扩展
			Infect(mine, show, xy[0], xy[1], row, col, &count);
		}
	}
}