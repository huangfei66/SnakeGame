#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Sound.h"

#include <graphics.h>
#include <conio.h>

#include "Snake.h"
#include "Game.h"
#include "Food.h"
#include "GameOver.h"

/************蛇相关全局变量定义************/

COORD snake[1024]; // 保存蛇身体

size_t SnakeSize; // 蛇长度

char SnakeDir; // 蛇方向

/****************初始化游戏数据****************/

void init()
{

    score = 0;

    SnakeSize = 3;

    srand((unsigned)time(NULL));

    // 初始化生命

    if (mode == 2)
    {
        life = 9999; // 无敌模式
    }
    else
    {
        life = 3; // 普通和穿墙模式
    }

    setbkcolor(WHITE);

    // 初始化地图

    memset(
        gameMap,
        SPACE,
        sizeof(gameMap));

    // 设置左右墙

    for (int i = 0; i < ROW; i++)
    {

        gameMap[i][0] = WALL;

        gameMap[i][COL - 1] = WALL;
    }

    // 设置上下墙

    for (int j = 1; j < COL - 1; j++)
    {

        gameMap[0][j] = WALL;

        gameMap[ROW - 1][j] = WALL;
    }

    // 初始化蛇

    gameMap[3][5] = HEAD;

    gameMap[3][4] = SNAKE;

    gameMap[3][3] = SNAKE;

    snake[0].X = 3;
    snake[0].Y = 5;

    snake[1].X = 3;
    snake[1].Y = 4;

    snake[2].X = 3;
    snake[2].Y = 3;

    SnakeDir = 'D';

    // 生成食物

    addfood();
}
void ResetSnake()
{

    // 清空地图

    memset(
        gameMap,
        SPACE,
        sizeof(gameMap));

    // 重新生成墙

    for (int i = 0; i < ROW; i++)
    {
        gameMap[i][0] = WALL;
        gameMap[i][COL - 1] = WALL;
    }

    for (int j = 1; j < COL - 1; j++)
    {
        gameMap[0][j] = WALL;
        gameMap[ROW - 1][j] = WALL;
    }

    // 恢复蛇长度

    SnakeSize = 3;

    gameMap[3][5] = HEAD;
    gameMap[3][4] = SNAKE;
    gameMap[3][3] = SNAKE;

    snake[0].X = 3;
    snake[0].Y = 5;

    snake[1].X = 3;
    snake[1].Y = 4;

    snake[2].X = 3;
    snake[2].Y = 3;

    SnakeDir = 'D';

    // 重新生成食物

    addfood();
}
/****************修改蛇方向****************/

void ChangeDir()
{

    ExMessage msg;

    while (peekmessage(&msg, EX_KEY))
    {

        if (msg.message == WM_KEYDOWN)
        {

            switch (msg.vkcode)
            {

            case VK_LEFT:

            case 'A':

            case 'a':

                if (SnakeDir != 'D')
                    SnakeDir = 'A';

                break;

            case VK_RIGHT:

            case 'D':

            case 'd':

                if (SnakeDir != 'A')
                    SnakeDir = 'D';

                break;

            case VK_UP:

            case 'W':

            case 'w':

                if (SnakeDir != 'S')
                    SnakeDir = 'W';

                break;

            case VK_DOWN:

            case 'S':

            case 's':

                if (SnakeDir != 'W')
                    SnakeDir = 'S';

                break;
            }
        }
    }
}

/****************普通移动****************/

void NormalMove(COORD next)
{

    // 清除蛇尾

    gameMap
        [snake[SnakeSize - 1].X]
        [snake[SnakeSize - 1].Y] = SPACE;

    // 身体移动

    for (int i = SnakeSize - 1; i > 0; i--)
    {

        snake[i] = snake[i - 1];
    }

    // 原蛇头变身体

    gameMap
        [snake[0].X]
        [snake[0].Y] = SNAKE;

    // 更新蛇头

    snake[0] = next;

    gameMap
        [snake[0].X]
        [snake[0].Y] = HEAD;
} /****************吃食物增长****************/

void GrowMove(COORD next)
{

    // 身体整体后移

    for (int i = SnakeSize; i > 0; i--)
    {

        snake[i] = snake[i - 1];
    }

    // 原蛇头变身体

    gameMap
        [snake[0].X]
        [snake[0].Y] = SNAKE;

    // 更新蛇头

    snake[0] = next;

    // 分数

    score += 10;

    if (score > maxScore)
    {

        maxScore = score;

        SaveMaxScore();
    }

    // 长度增加

    SnakeSize++;

    gameMap
        [snake[0].X]
        [snake[0].Y] = HEAD;

    // 吃豆声音

    PlayEatSound();

    // 重新生成食物

    AddOneFood();
}

/****************穿墙****************/

void WrapWall(COORD *next)
{

    switch (SnakeDir)
    {

    case 'A':

        next->Y = COL - 2;

        break;

    case 'D':

        next->Y = 1;

        break;

    case 'W':

        next->X = ROW - 2;

        break;

    case 'S':

        next->X = 1;

        break;
    }
}

/****************蛇移动****************/

int move()
{

    COORD next;

    // 计算下一格位置

    switch (SnakeDir)
    {

    case 'A':

        next.X = snake[0].X;

        next.Y = snake[0].Y - 1;

        break;

    case 'D':

        next.X = snake[0].X;

        next.Y = snake[0].Y + 1;

        break;

    case 'W':

        next.X = snake[0].X - 1;

        next.Y = snake[0].Y;

        break;

    case 'S':

        next.X = snake[0].X + 1;

        next.Y = snake[0].Y;

        break;
    }

    switch (gameMap[next.X][next.Y])
    {

        // 空地

    case SPACE:

        NormalMove(next);

        break;

        // 普通食物

    case FOOD:

        GrowMove(next);

        break;

        // 刺豆

    case SPIKE:

        // 无敌模式忽略刺豆

        if (mode != 2)
        {

            life--;

            if (life <= 0)
            {
                return ShowGameOver();
            }
        }

        NormalMove(next);

        break;
        // 墙

    case SNAKE:

        if (mode == 2)
        {

            NormalMove(next);
        }

        else
        {

            life--;

            if (life <= 0)
            {
                return ShowGameOver();
            }

            ResetSnake();
        }

        break;

    case WALL:

        if (mode == 0)
        {

            life--;

            if (life <= 0)
            {
                return ShowGameOver();
            }

            ResetSnake();
        }

        else
        {

            WrapWall(&next);

            NormalMove(next);
        }

        break;
    }

    return 0;
}