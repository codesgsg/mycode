#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#define ROW 10
#define COL 10
#define ROWS ROW+2
#define COLS COL+2
#define DIFFICULTY_1 10
//游戏主逻辑
void mygame(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//数组初始化
void Format(char arr[ROWS][COLS], int row, int col, char set);
//画界面
void Displayboard(char arr[ROWS][COLS], int row, int col);
//主菜单
int Headmenu();
//防溢出输入
void Getxy(int row, int col, int xy[]);
//输入一个数
int Getenter();
//埋雷
void Setmine(char arr[ROWS][COLS], int row, int col);
//排雷向外扩展
void Infect(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int* col);
//显示地雷
void showmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);