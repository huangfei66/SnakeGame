#include <graphics.h>
#include <conio.h>

#include "Pause.h"

int DrawPause()
{

    while (1)
    {

        BeginBatchDraw();

        cleardevice();

        // 暂停框

        setfillcolor(WHITE);

        solidrectangle(
            150,
            120,
            490,
            400);

        setlinecolor(RED);

        rectangle(
            150,
            120,
            490,
            400);

        settextcolor(RED);

        settextstyle(
            35,
            0,
            "微软雅黑");

        char title[] = "游戏暂停";

        outtextxy(
            320 - textwidth(title) / 2,
            160,
            title);

        settextstyle(
            22,
            0,
            "微软雅黑");

        char a[] = "1.继续游戏";

        char b[] = "2.重新开始";

        char c[] = "3.返回主菜单";

        char d[] = "4.退出游戏";

        outtextxy(
            320 - textwidth(a) / 2,
            230,
            a);

        outtextxy(
            320 - textwidth(b) / 2,
            270,
            b);

        outtextxy(
            320 - textwidth(c) / 2,
            310,
            c);

        outtextxy(
            320 - textwidth(d) / 2,
            350,
            d);

        EndBatchDraw();

        ExMessage msg;

        if (peekmessage(&msg, EX_KEY))
        {

            if (msg.message == WM_KEYDOWN)
            {

                switch (msg.vkcode)
                {

                case '1':

                    return 1;

                case '2':

                    return 2;

                case '3':

                    return 3;

                case '4':

                    return 4;
                }
            }
        }

        Sleep(20);
    }
}