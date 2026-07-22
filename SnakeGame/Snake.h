#pragma once

#include <Windows.h>

// 蛇数组

extern COORD snake[1024];

// 蛇长度

extern size_t SnakeSize;

// 蛇方向

extern char SnakeDir;

// 初始化游戏数据

void init();

// 修改蛇方向

void ChangeDir();

// 蛇移动

int move();

// 游戏结束界面

int GameOver();

// 普通移动

void NormalMove(COORD next);

// 吃食物移动

void GrowMove(COORD next);

// 穿墙处理

void WrapWall(COORD *next);

// 碰撞检测

bool CheckDead();
void ResetSnake();