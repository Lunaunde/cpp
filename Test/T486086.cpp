#include <iostream>
#include <cmath>
using namespace std;
int n, m, info[3][100000], change_info[2][100000], new_info[2], ed_info[2][100000], base_max_v, new_max_v, key1, key2;
void quickSort(int start, int end)
{
    int counter = 0, b, c, d;
    for (int i = start + 1; i <= end; i++)
    {
        if (info[1][start + counter] > info[1][i])
        {
            b = info[1][i];
            c = info[0][i];
            d = info[2][i];
            for (int j = i; j > start + counter; j--)
            {
                info[0][j] = info[0][j - 1];
                info[1][j] = info[1][j - 1];
                info[2][j] = info[2][j - 1];
            }
            info[1][start + counter] = b;
            info[0][start + counter] = c;
            info[2][start + counter] = d;
            counter++;
        }
    }
    if (start + counter < end - 1)
        quickSort(start + counter + 1, end);
    if (start + counter > start + 1)
        quickSort(start, start + counter - 1);
}
void quickSort2(int start, int end)
{
    int counter = 0, b, c, d;
    for (int i = start + 1; i <= end; i++)
    {
        if (ed_info[1][start + counter] > ed_info[1][i])
        {
            b = ed_info[1][i];
            c = ed_info[0][i];
            d = ed_info[2][i];
            for (int j = i; j > start + counter; j--)
            {
                ed_info[0][j] = ed_info[0][j - 1];
                ed_info[1][j] = ed_info[1][j - 1];
                ed_info[2][j] = ed_info[2][j - 1];
            }
            ed_info[1][start + counter] = b;
            ed_info[0][start + counter] = c;
            ed_info[2][start + counter] = d;
            counter++;
        }
    }
    if (start + counter < end - 1)
        quickSort2(start + counter + 1, end);
    if (start + counter > start + 1)
        quickSort2(start, start + counter - 1);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> info[0][i] >> info[1][i];
        info[2][i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> change_info[0][i] >> change_info[1][i];
    }
    quickSort(0, n - 1);
    base_max_v = 0;
    for (int j = 0; j < n - 1; j++)
    {
        if (base_max_v < (abs(info[0][j] - info[0][j + 1])) / abs(info[1][j] - info[1][j + 1]))
        {
            base_max_v = (abs(info[0][j] - info[0][j + 1])) / abs(info[1][j] - info[1][j + 1]);
            key1 = j;
            key2 = j + 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        new_max_v = 0;
        if (change_info[0][i] - 1 != key1 && change_info[0][i] - 1 != key2)
        {
            for (int j = 0; j < n; j++)
            {
                if (info[2][j] == change_info[0][i] - 1)
                {
                    new_info[0] = info[0][j];
                    new_info[1] = change_info[1][i];
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (j == 0 && new_info[1] < info[1][0])
                    new_max_v = abs(new_info[0] - info[0][j]) / abs(new_info[1] - info[1][j]);
                if (info[1][j] <= new_info[1] && new_info[1] < info[1][j + 1])
                    new_max_v = max(abs(new_info[0] - info[0][j]) / abs(new_info[1] - info[1][j]), abs(new_info[0] - info[0][j + 1]) / abs(new_info[1] - info[1][j + 1]));
                if (j == n - 1 && new_info[1] > info[1][j])
                    new_max_v = abs(new_info[0] - info[0][j]) / abs(new_info[1] - info[1][j]);
            }
            cout << max(base_max_v, new_max_v) << endl;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                ed_info[0][j] = info[0][j];
                ed_info[1][j] = info[1][j];
            }
            for (int j = 0; j < n; j++)
            {
                if (ed_info[2][j] == change_info[0][i] - 1)
                {
                    ed_info[1][j] = change_info[1][i];
                }
            }
            quickSort2(0, n - 1);
            for (int j = 0; j < n - 1; j++)
            {
                if (new_max_v < (abs(ed_info[0][j] - ed_info[0][j + 1])) / abs(ed_info[1][j] - ed_info[1][j + 1]))
                {
                    new_max_v = (abs(ed_info[0][j] - ed_info[0][j + 1])) / abs(ed_info[1][j] - ed_info[1][j + 1]);
                }
            }
            cout<<new_max_v<<endl;
        }
    }
    return 0;
}