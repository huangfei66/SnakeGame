#include "Game.h"
#include "Config.h"
#include "Food.h"

#include <fstream>
#include <stdio.h>
#include <time.h>
#include <windows.h>

/************全局变量定义************/

int score = 0; // 当前分数

int mode = 0; // 游戏模式

int maxScore = 0; // 历史最高分

int gameSpeed = 100; // 游戏速度

int life = 3; // 生命数量

bool isPause = false; // 暂停状态

clock_t startTime; // 游戏开始时间

clock_t pauseTime = 0; // 暂停时间

DWORD t1, t2; // 控制移动速度

// 地图数组

int gameMap[ROW][COL];

// 保存最高分

void SaveMaxScore()
{

    FILE *fp = fopen(
        "history.txt",
        "w");

    if (fp)
    {

        fprintf(
            fp,
            "%d",
            maxScore);

        fclose(fp);
    }
}