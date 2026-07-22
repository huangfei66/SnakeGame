#include <graphics.h>
#include <Windows.h>
#include <stdio.h>

#include "GameOver.h"
#include "Game.h"

bool gameOver = false;

int ShowGameOver()
{

    ExMessage msg;

    while (1)
    {

        BeginBatchDraw();

        cleardevice();

        //=====================
        // 游戏结束窗口
        //=====================

        setfillcolor(WHITE);

        solidrectangle(
            150,
            120,
            490,
            380);

        setlinecolor(RED);

        rectangle(
            150,
            120,
            490,
            380);

        // 标题

        settextcolor(RED);

        settextstyle(
            35,
            0,
            "微软雅黑");

        outtextxy(
            240,
            160,
            "游戏结束");

        // 分数

        char s[50];

        sprintf_s(
            s,
            sizeof(s),
            "最终得分:%d",
            score);

        settextstyle(
            20,
            0,
            "微软雅黑");

        outtextxy(
            230,
            220,
            s);

        // 选项

        outtextxy(
            220,
            260,
            "1.退出游戏");

        outtextxy(
            220,
            300,
            "2.返回难度选择");

        outtextxy(
            220,
            340,
            "3.重新开始");

        EndBatchDraw();

        //=====================
        // 键盘检测
        //=====================

        while (peekmessage(&msg, EX_KEY))
        {

            if (msg.message == WM_KEYDOWN)
            {

                if (msg.vkcode == '1')
                {

                    return 1;
                }

                if (msg.vkcode == '2')
                {

                    return 2;
                }

                if (msg.vkcode == '3')
                {

                    return 3;
                }
            }
        }

        Sleep(10);
    }
}