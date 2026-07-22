#include <graphics.h>
#include <Windows.h>
#include <stdio.h>
#include <time.h>

#include "Game.h"
#include "Menu.h"
#include "Snake.h"
#include "Map.h"
#include "Pause.h"
#include "Sound.h"

int main()
{

    initgraph(640, 550);

    SetWindowTextA(
        GetHWnd(),
        "贪吃蛇游戏");

    start();

    chose();

    init();

    score = 0;

    startTime = clock();

    // 读取最高分

    FILE *fp = fopen(
        "history.txt",
        "r");

    if (fp)
    {

        fscanf(
            fp,
            "%d",
            &maxScore);

        fclose(fp);
    }
    else
    {

        maxScore = 0;
    }

    while (1)
    {

        //====================
        // 暂停控制
        //====================

        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {

            isPause = !isPause;

            Sleep(200);
        }

        //====================
        // 重新开始
        //====================

        if (GetAsyncKeyState('R') & 0x8000)
        {

            init();

            score = 0;

            startTime = clock();

            pauseTime = 0;

            isPause = false;

            Sleep(200);
        }

        //====================
        // 暂停界面
        //====================

        if (isPause)
        {

            int result = DrawPause();

            // 继续

            if (result == 1)
            {

                isPause = false;
            }

            // 重新开始

            if (result == 2)
            {

                init();

                score = 0;

                startTime = clock();

                pauseTime = 0;

                isPause = false;
            }

            // 返回主菜单

            if (result == 3)
            {

                isPause = false;

                start();

                chose();

                init();

                score = 0;

                startTime = clock();
            }

            // 退出

            if (result == 4)
            {

                closegraph();

                return 0;
            }

            continue;
        }

        //====================
        // 游戏运行
        //====================

        t2 = GetTickCount();

        ChangeDir();

        // 长按方向加速

        int speed = gameSpeed;

        if (
            (GetAsyncKeyState('D') & 0x8000 && SnakeDir == 'D') ||
            (GetAsyncKeyState('A') & 0x8000 && SnakeDir == 'A') ||
            (GetAsyncKeyState('W') & 0x8000 && SnakeDir == 'W') ||
            (GetAsyncKeyState('S') & 0x8000 && SnakeDir == 'S'))
        {

            speed = gameSpeed / 2;
        }

        if (t2 - t1 > speed)
        {

            int result = move();

            t1 = t2;

            // 退出

            if (result == 1)
            {

                closegraph();

                return 0;
            }

            // 返回主菜单

            if (result == 2)
            {

                StopBGM();

                start();

                chose();

                init();

                score = 0;

                startTime = clock();

                pauseTime = 0;
            }

            // 重新开始

            if (result == 3)
            {

                init();

                score = 0;

                startTime = clock();

                pauseTime = 0;
            }
        }

        DrawMap();
    }

    closegraph();

    return 0;
}