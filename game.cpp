#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void gotoxy(int x,int y)
{

    COORD pos;
    HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );

    if (INVALID_HANDLE_VALUE != hConsole)
    {
        pos.X = x;
        pos.Y = y;

        SetConsoleCursorPosition( hConsole, pos );
    }
}
void game()
{
    int x = 39, y = 48, xf, yf;
    int xb = 33, xbo;
    int g[7][42];
    xf = ((rand() % 2) * 2) - 1;
    yf = -1;
    for (int i = 0; i < 7; i++)
    {
        if (i < 1 || i > 5)
        {
            for (int k = 0; k < 42; k++)
                g[i][k] = 0;
            continue;
        }
        g[i][0] = g[i][41] = 0;
        gotoxy(19, 7 + i );
        for (int j = 1; j < 41; j++)
        {
            g[i][j] = 1;
            cout << "#";
        }
    }
    gotoxy (xb, 49);
    cout << "=============";
    while (1)
    {
        gotoxy(x, y);
        cout << "@";
        if (x >= 19 && x <= 59 && y >= 8 && y <= 13)
        {
            if (g[y - 7][x - 18] == 1)
            {
                g[y - 7][x - 18] = 0;
                if (g[y - 7][x - 18 + 1] != g[y - 7][x - 18 - 1])
                    xf *= -1;
                if (g[y - 7 + 1][x - 18] != g[y - 7 - 1][x - 18])
                    yf *= -1;
                if ((g[y - 7][x - 18 + 1] == g[y - 7][x - 18 - 1]) && (g[y - 7 + 1][x - 18] == g[y - 7 - 1][x - 18]))
                {
                    xf *= -1;
                    yf *= -1;
                }
            }
        }
        Sleep(30L);
        gotoxy(x, y);
        cout << " ";
        x += xf;
        y += yf;
        if (x > 78 || x < 1)
            xf *= -1;
        if (y > 47 || y < 1)
        {
            if (y > 47)
                if (x - xb < 0 || x - xb > 12)
                {
                    gotoxy(35, 24);
                    cout << "GAME OVER!" << endl;
                    getch();
                    getch();
                    return;
                }

            yf *= -1;
        }
        xbo = xb;
        if (GetAsyncKeyState(VK_LEFT))
            if (xb - 1 > 0)
                xb--;
        if (GetAsyncKeyState(VK_RIGHT))
            if (xb + 1 < 66)
                xb++;
        if (xbo != xb)
        {
            gotoxy(xbo, 49);
            cout << "             ";
            gotoxy(xb, 49);
            cout << "=============";
        }
    }

}
int main()
{
    srand(time(0));
    game();
    Sleep(2000L);
    getch();
    return 0;
}
