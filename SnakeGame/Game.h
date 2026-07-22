#pragma once

#include <graphics.h>
#include <Windows.h>
#include <time.h>

#include "Config.h"

// 枚举

enum game
{
	SPACE,
	WALL,
	SNAKE,
	FOOD,
	SPIKE,
	HEAD
};

// 全局变量

extern int mode;

// 分数

extern int score;

// 最高分

extern int maxScore;

// 游戏速度

extern int gameSpeed;

// 生命

extern int life;

// 游戏开始时间

extern clock_t startTime;

// 暂停时间

extern clock_t pauseTime;

// 暂停状态

extern bool isPause;

// 蛇方向

extern char SnakeDir;

// 移动计时

extern DWORD t1;
extern DWORD t2;

// 地图

extern int gameMap[ROW][COL];

// 保存最高分

void SaveMaxScore();