#include <iostream>
int map[12][12], p[2][3][100000], t = 0; // p[0]=C,p[1]=F
bool flag = 1;
using namespace std;
void move(int facing, int player)
{
    int x = 0, y = 0;
    switch (facing)
    {
    case 0:
        y = -1;
        break;
    case 1:
        x = 1;
        break;
    case 2:
        y = 1;
        break;
    case 3:
        x = -1;
        break;
    }
    if (map[p[player][0][t] + x][p[player][1][t] + y] == 0)
    {
        p[player][0][t + 1] = p[player][0][t] + x;
        p[player][1][t + 1] = p[player][1][t] + y;
        p[player][2][t + 1] = p[player][2][t];
    }
    else
    {
        p[player][0][t + 1] = p[player][0][t];
        p[player][1][t + 1] = p[player][1][t];
        p[player][2][t + 1] = p[player][2][t] + 1;
        p[player][2][t + 1] %= 4;
    }
}
void test()
{
    bool flags[3];
    for (int i = 0; i < t; i++)
    {
        flags[0] = flags[1] = flags[2] = 0;
        for (int j = 0; j < 3; j++)
        {
            if (p[0][j][i] == p[0][j][t] && p[1][j][i] == p[1][j][t])
                flags[j] = 1;
        }
        if (flags[0] && flags[1] && flags[2])
        {
            flag = 0;
            t = 0;
            break;
        }
    }
}
int main()
{
    char ch;
    p[0][2][0] = 0;
    p[1][2][0] = 0;
    for (int i = 0; i < 12; i++)
    {
        map[i][0] = 1;
        map[i][11] = 1;
        map[0][i] = 1;
        map[11][i] = 1;
    }
    for (int y = 1; y < 11; y++)
    {
        for (int x = 1; x < 11; x++)
        {
            cin >> ch;
            if (ch == '*')
                map[x][y] = 1;
            else
            {
                map[x][y] = 0;
                if (ch == 'C')
                {
                    p[0][0][0] = x;
                    p[0][1][0] = y;
                }
                if (ch == 'F')
                {
                    p[1][0][0] = x;
                    p[1][1][0] = y;
                }
            }
        }
    }
    while (p[0][0][t] != p[1][0][t] || p[0][1][t] != p[1][1][t])
    {
        move(p[0][2][t], 0);
        move(p[1][2][t], 1);
        test();
        if (flag == 0)
        {
            break;
        }
        t++;
    //     cout << t << endl;
    //     for (int y = 1; y < 11; y++)
    //     {
    //         for (int x = 1; x < 11; x++)
    //         {
    //             if (map[x][y] == 1)
    //                 cout << "*";
    //             else
    //             {
    //                 if (x == p[0][0][t] && y == p[0][1][t])
    //                     cout << "C";
    //                 else if (x == p[1][0][t] && y == p[1][1][t])
    //                     cout << "F";
    //                 else
    //                     cout << ".";
    //             }
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    //     cout << p[0][0][t] << " " << p[0][1][t] << " "<<p[0][2][t]<<" " << p[1][0][t] << " " << p[1][1][t] << " "<<p[1][2][t]<<" "  << flag << endl;
    }
    cout << t;
    return 0;
}