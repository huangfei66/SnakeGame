#include <stdio.h>
#include <graphics.h>
#include <time.h>

#include "Map.h"
#include "Game.h"
#include "Snake.h"

void DrawMap()
{

	BeginBatchDraw();

	//=====================
	// 背景
	//=====================

	setbkcolor(WHITE);

	cleardevice();

	//=====================
	// 顶部信息栏
	//=====================
	settextcolor(RED);

	settextstyle(
		20,
		0,
		"微软雅黑");

	char s[50];

	// 分数

	sprintf(
		s,
		"分数:%d",
		score);

	outtextxy(
		10,
		15,
		s);

	// 时间

	int t =
		(clock() - startTime) / CLOCKS_PER_SEC;

	sprintf(
		s,
		"时间:%02d:%02d",
		t / 60,
		t % 60);

	outtextxy(
		170,
		15,
		s);

	// 最高分

	sprintf(
		s,
		"最高:%d",
		maxScore);

	outtextxy(
		370,
		15,
		s);

	// 生命

	sprintf(
		s,
		"生命:%d",
		life);

	outtextxy(
		530,
		15,
		s);
	//=====================
	// 绘制地图
	//=====================

	for (int y = 0; y < ROW; y++)
	{

		for (int x = 0; x < COL; x++)
		{

			switch (gameMap[y][x])
			{

				// 空地

			case SPACE:

				break;

				// 墙

			case WALL:

				setlinecolor(BLACK);

				setfillcolor(
					RGB(238, 233, 233));

				fillrectangle(

					x * 10,

					y * 10 + 50,

					x * 10 + 10,

					y * 10 + 60

				);

				break;

				// 蛇身体

			case SNAKE:

				setlinecolor(
					RGB(0, 150, 0));

				setfillcolor(
					RGB(50, 205, 50));

				fillcircle(

					x * 10 + 5,

					y * 10 + 55,

					5

				);

				break;

				// 蛇头

			case HEAD:

				setlinecolor(GREEN);

				setfillcolor(
					RGB(0, 220, 0));

				fillcircle(

					x * 10 + 5,

					y * 10 + 55,

					6

				);

				// 眼睛

				setfillcolor(BLACK);

				switch (SnakeDir)
				{

				case 'D':

					fillcircle(
						x * 10 + 8,
						y * 10 + 52,
						2);

					fillcircle(
						x * 10 + 8,
						y * 10 + 58,
						2);

					break;

				case 'A':

					fillcircle(
						x * 10 + 2,
						y * 10 + 52,
						2);

					fillcircle(
						x * 10 + 2,
						y * 10 + 58,
						2);

					break;

				case 'W':

					fillcircle(
						x * 10 + 3,
						y * 10 + 52,
						2);

					fillcircle(
						x * 10 + 7,
						y * 10 + 52,
						2);

					break;

				case 'S':

					fillcircle(
						x * 10 + 3,
						y * 10 + 58,
						2);

					fillcircle(
						x * 10 + 7,
						y * 10 + 58,
						2);

					break;
				}

				break;

				// 普通食物

			case FOOD:
			{

				COLORREF foodColor[] =
					{
						RED,
						BLUE,
						GREEN,
						YELLOW,
						RGB(255, 100, 200),
						RGB(255, 165, 0)};

				setfillcolor(
					foodColor[(x + y) % 6]);

				fillcircle(

					x * 10 + 5,

					y * 10 + 55,

					5

				);
			}

			break;
				// 刺豆

			case SPIKE:

			{

				setfillcolor(
					RGB(255, 100, 100));

				int pts[] =
					{

						x * 10 + 5,
						y * 10 + 50,

						x * 10,
						y * 10 + 60,

						x * 10 + 10,
						y * 10 + 60

					};

				fillpoly(
					3,
					pts);
			}

			break;
			}
		}
	}

	//=====================
	// 底部提示
	//=====================

	settextcolor(RED);

	settextstyle(
		20,
		0,
		"微软雅黑");

	outtextxy(

		10,

		520,

		"空格:暂停/继续     R:重新开始"

	);

	EndBatchDraw();
}