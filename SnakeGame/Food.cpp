#include <stdlib.h>
#include <time.h>

#include <graphics.h>

#include "Food.h"
#include "Game.h"

// 生成食物
void addfood()
{

	int row, col;

	// 普通豆

	for (int i = 0; i < FOOD_NUM; i++)
	{

		int count = 0;

		do
		{

			row = rand() % (ROW - 2) + 1;
			col = rand() % (COL - 2) + 1;

			count++;

			if (count > 100)
				return;

		} while (gameMap[row][col] != SPACE);

		gameMap[row][col] = FOOD;
	}

	// 刺豆

	for (int i = 0; i < SPIKE_NUM; i++)
	{

		int count = 0;

		do
		{

			row = rand() % (ROW - 2) + 1;
			col = rand() % (COL - 2) + 1;

			count++;

			if (count > 100)
				return;

		} while (gameMap[row][col] != SPACE);

		gameMap[row][col] = SPIKE;
	}
}

// 绘制食物

void drawfood()
{

	for (int i = 0; i < ROW; i++)
	{

		for (int j = 0; j < COL; j++)
		{

			// 普通豆

			if (gameMap[i][j] == FOOD)
			{

				setfillcolor(
					RGB(255, 200, 0));

				fillcircle(
					j * 10 + 5,
					i * 10 + 5,
					5);
			}

			// 刺豆

			if (gameMap[i][j] == SPIKE)
			{

				setfillcolor(RED);

				int pts[] =
					{

						j * 10, i * 10 + 10,

						j * 10 + 5, i * 10,

						j * 10 + 10, i * 10 + 10

					};

				fillpoly(
					3,
					pts);
			}
		}
	}
}
void AddOneFood()
{

    int row,col;


    do
    {

        row=rand()%(ROW-2)+1;

        col=rand()%(COL-2)+1;


    }while(gameMap[row][col]!=SPACE);



    gameMap[row][col]=FOOD;

}