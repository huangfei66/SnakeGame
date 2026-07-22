#include <Windows.h>
#include <mmsystem.h>

#include "Sound.h"

#pragma comment(lib,"winmm.lib")


//播放背景音乐
void PlayBGM()
{
    PlaySound(
        TEXT("sound/bgm.wav"),
        NULL,
        SND_FILENAME | SND_ASYNC | SND_LOOP
    );
}


//停止背景音乐
void StopBGM()
{
    PlaySound(
        NULL,
        NULL,
        0
    );
}


void PlayEatSound()
{

}


//结束声音（如果不用也可以保留）
void PlayGameOverSound()
{
    PlaySound(
        TEXT("sound/gameover.wav"),
        NULL,
        SND_FILENAME | SND_ASYNC
    );
}