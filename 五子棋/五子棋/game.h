#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#define ROW 8 //棋盘行
#define COLUMN 8   //棋盘列

//菜单
int GameMenu();
//游戏主体
void GameMain();
//画棋盘
void ChessBoard(char chessman[ROW][COLUMN],int row, int column);
//下棋
void PlayChess(char chessman[ROW][COLUMN], int row, int column);
//设置电脑下棋
void SetaiXY(char chessman[ROW][COLUMN], int xy[], int row,int column);
//设置玩家下棋
void SetplayXY(char chessman[ROW][COLUMN], int xy[], int row, int column);
//裁判
int Referee(char chessman[ROW][COLUMN],int  xy[], int row, int column);
