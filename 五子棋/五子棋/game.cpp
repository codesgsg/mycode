#include "game.h"


int GameMenu()
{
	system("cls");
	printf("———————————————————————————\n");
	printf("|**********************五子棋************************|\n");
	printf("|****************************************************|\n");
	printf("|*1.开始游戏*****************************************|\n");
	printf("|*0.退出游戏*****************************************|\n");
	printf("|****************************************************|\n");
	printf("|*******************************************by:codesg|\n");
	printf("———————————————————————————\n\n");
	int Option = 0;
	char ch = 0;
	while (1)
	{
		int err = scanf("%d", &Option);
		if (err == 0)
		{
			//输入非数字退出
			while ((ch = getchar()) != EOF && ch != '\n');
			printf("(⊙_⊙)？\n");
		}
		else if (Option == 1)
		{
			//输入1开始游戏
			break;
		}
		else if (Option == 0)
		{
			//输入0退出游戏
			printf("拜拜\n");
			return 0;
		}
		else
		{
			printf("输入错误,请重新输入\n");
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
	printf("请输入坐标(x y):\n");
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
			printf("请输入数字\n");
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
			printf("坐标已有棋子\n");
		}
		else 
		{
			printf("请输入正确的坐标\n");
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
	//1,玩家胜 2,电脑胜 3,平局 4,继续
	//判断横坐标是否5子
	char che = chessman[xy[0]][xy[1]];
	int x = xy[0];
	int y = xy[1];
	int countx = 1;
	int county = 1;


	if (che == '*' || che == '#')
	{
		//横竖
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
		//斜角
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
				printf("玩家胜\n");
			else
				printf("电脑胜\n");
			printf("是否继续游戏？1.继续 2.退出\n");
			while (1)
			{
				char ch = 0;
				int err = 0;
				if (scanf("%d", &err) == 0)
				{
					while ((ch = getchar()) != EOF && ch != '\n');
					printf("(⊙_⊙)？\n");
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
					printf("请输入正确的数字\n");
				}
			}
		}
	}
	
	return 0;
}

void GameMain()
{
	int xy[2] = { 0 };//落子点
	int decide = 0;
	int restart = 1;//重新开始
	int order = 0;
	srand((unsigned int)time(NULL));//置随机数种子
	char chessman[ROW][COLUMN] = { 0 };	

	while (1)
	{
		if (restart == 1)
		{
			order = 0;
			memset(chessman, ' ', ROW * COLUMN); //初始化棋盘数组为空格	
			if (GameMenu() == 0)//开始菜单
			{
				return;
			}

		}	
		restart = 0;//初始化完毕 开始下棋
		system("cls");
		ChessBoard(chessman, ROW, COLUMN);//画棋盘
		decide = Referee(chessman, xy, ROW, COLUMN);
		if (decide == 1)
		{
			restart = 1; //重新开始初始化
			continue;
		}
		else if (decide == 2)
		{
			return;
		}
		//如果order == 0 玩家下棋 order == 1电脑下
		if (order= !order)
		{	
			SetplayXY(chessman, xy,ROW, COLUMN);	//设置玩家下棋
		}
		else
		{
			SetaiXY(chessman, xy, ROW, COLUMN);//设置AI下棋
			Sleep(500);
		}
		//裁判 1.重新游戏2.退出游戏

	}
}