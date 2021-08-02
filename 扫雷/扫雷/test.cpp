#include "game.h"

int main()
{
	char mine[ROWS][ROWS] = { 0 };
	char show[ROWS][ROWS] = { 0 };
	srand((unsigned int)time(NULL));

	mygame(mine, show, ROW, COL);

	return 0;
}