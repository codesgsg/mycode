#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#define ROW 8 //������
#define COLUMN 8   //������

//�˵�
int GameMenu();
//��Ϸ����
void GameMain();
//������
void ChessBoard(char chessman[ROW][COLUMN],int row, int column);
//����
void PlayChess(char chessman[ROW][COLUMN], int row, int column);
//���õ�������
void SetaiXY(char chessman[ROW][COLUMN], int xy[], int row,int column);
//�����������
void SetplayXY(char chessman[ROW][COLUMN], int xy[], int row, int column);
//����
int Referee(char chessman[ROW][COLUMN],int  xy[], int row, int column);
