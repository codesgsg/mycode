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
//��Ϸ���߼�
void mygame(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//�����ʼ��
void Format(char arr[ROWS][COLS], int row, int col, char set);
//������
void Displayboard(char arr[ROWS][COLS], int row, int col);
//���˵�
int Headmenu();
//���������
void Getxy(int row, int col, int xy[]);
//����һ����
int Getenter();
//����
void Setmine(char arr[ROWS][COLS], int row, int col);
//����������չ
void Infect(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int* col);
//��ʾ����
void showmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);