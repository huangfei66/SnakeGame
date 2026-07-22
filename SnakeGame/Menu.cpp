#include <graphics.h>
#include <conio.h>

#include "Sound.h"
#include "Menu.h"
#include "Game.h"

void start()
{

	PlayBGM();

	setbkcolor(WHITE);

	cleardevice();

	setbkmode(TRANSPARENT);

	settextcolor(BLACK);

	// 标题

	settextstyle(
		35,
		0,
		"微软雅黑");

	char title[] = "智能贪吃蛇";

	outtextxy(
		320 - textwidth(title) / 2,
		80,
		title);

	// 选项

	settextstyle(
		25,
		0,
		"微软雅黑");

	char a[] = "1.开始游戏";

	char b[] = "2.退出游戏";

	outtextxy(
		320 - textwidth(a) / 2,
		180,
		a);

	outtextxy(
		320 - textwidth(b) / 2,
		240,
		b);

	settextstyle(
		18,
		0,
		"微软雅黑");

	char c[] = "请按数字键选择";

	outtextxy(
		320 - textwidth(c) / 2,
		320,
		c);

	FlushBatchDraw();

	while (1)
	{

		ExMessage msg;

		if (peekmessage(&msg, EX_KEY))
		{

			if (msg.message == WM_KEYDOWN)
			{

				switch (msg.vkcode)
				{

				case '1':

					cleardevice();

					return;

				case '2':

					closegraph();

					exit(0);
				}
			}
		}
	}
}

void chose()
{

	setbkcolor(WHITE);

	cleardevice();

	setbkmode(TRANSPARENT);

	settextcolor(BLACK);

	settextstyle(
		30,
		0,
		"微软雅黑");

	char title[] = "选择游戏模式";

	outtextxy(
		320 - textwidth(title) / 2,
		80,
		title);

	settextstyle(
		22,
		0,
		"微软雅黑");

	char a[] = "1.普通模式";

	char b[] = "2.穿墙模式";

	char c[] = "3.无敌模式";

	outtextxy(
		320 - textwidth(a) / 2,
		170,
		a);

	outtextxy(
		320 - textwidth(b) / 2,
		220,
		b);

	outtextxy(
		320 - textwidth(c) / 2,
		270,
		c);

	FlushBatchDraw();

	while (1)
	{

		ExMessage msg;

		if (peekmessage(&msg, EX_KEY))
		{

			if (msg.message == WM_KEYDOWN)
			{

				switch (msg.vkcode)
				{

				case '1':

					mode = 0;

					cleardevice();

					return;

				case '2':

					mode = 1;

					cleardevice();

					return;

				case '3':

					mode = 2;

					cleardevice();

					return;
				}
			}
		}
	}
}